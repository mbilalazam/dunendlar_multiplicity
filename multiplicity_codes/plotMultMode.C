#include "TH1.h"
#include "TGraph.h"
#include "TH2.h"
#include "TF1.h"
#include "TROOT.h"
#include "THStack.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TGraphErrors.h"
#include "TVectorD.h"
#include "TTimeStamp.h"
#include <fstream>
#include "TMinuit.h"
#include "TString.h"
#include <vector>
#include <string.h>
#include "TLatex.h"
#include "TPaveStats.h"
#include "TDatime.h"
#include "TColor.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TH2F.h"
void plotMultMode()
{


gROOT->LoadMacro("protoDUNEStyle.C");
gROOT->SetStyle("protoDUNEStyle");
gROOT->ForceStyle();
gStyle->SetTitleX(0.35);
gStyle->SetOptFit(111);
gStyle->SetPadRightMargin(0.15);
gStyle->SetPadLeftMargin(0.15);
gStyle->SetOptTitle(2);  //no title
gStyle->SetOptStat("emr");  ////stats box
gStyle->SetStatY(0.9);  //// Set y-position (fraction of pad size)
gStyle->SetStatX(0.9);  //// Set x-position (fraction of pad size)
gStyle->SetStatW(0.2);  //// Set width of stat-box (fraction of pad size)
gStyle->SetStatH(0.2);  //// Set height of stat-box (fraction of pad size)
gStyle->SetTextFont(42);
gStyle->SetTextSize(0.05);
gStyle->SetStatFontSize(0.05);


  
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/nocutonRange/TrackMult2x2wTruth.root");

TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");

// // // Interaction Modes (Within Acceptance)

TH1D *truemultQE=new TH1D("truemultQE","truemultQE",10,1,11);
TH1D *truemultRES=new TH1D("truemultRES","truemultRES",10,1,11);
TH1D *truemultDIS=new TH1D("truemultDIS","truemultDIS",10,1,11);
TH1D *truemultCOH=new TH1D("truemultCOH","truemultCOH",10,1,11);
TH1D *truemultMEC=new TH1D("truemultMEC","truemultMEC",10,1,11);
THStack *hs = new THStack("hs","Interaction Types in Observed Multiplicity Bins");
TCanvas c2=TCanvas();
c2.Draw();
tevt->Project("truemultQE","_truemultQE");
tevt->Project("truemultRES","_truemultRES");
tevt->Project("truemultDIS","_truemultDIS");
tevt->Project("truemultCOH","_truemultCOH");
tevt->Project("truemultMEC","_truemultMEC");
hs->Add(truemultQE);
hs->Add(truemultRES);
hs->Add(truemultDIS);
hs->Add(truemultCOH);
hs->Add(truemultMEC); 
truemultQE->SetFillColor(kBlack);
truemultRES->SetFillColor(kRed);
truemultDIS->SetFillColor(kBlue);
truemultCOH->SetFillColor(kGreen);
truemultMEC->SetFillColor(6);
hs->Draw("hist");
hs->SetTitle(" ");
hs->GetXaxis()->SetTitle("True Multiplicity");
hs->GetYaxis()->SetTitle("Number of Events");
hs->GetYaxis()->SetRangeUser(0, 500);
TLegend *l2 = new TLegend(0.65,0.65,0.95,0.88);
l2->AddEntry(truemultQE,"QE ","F");  
l2->AddEntry(truemultRES,"RES ","F");
l2->AddEntry(truemultDIS,"DIS ","F");
l2->AddEntry(truemultCOH,"COH ","F");
l2->AddEntry(truemultMEC,"MEC ","F");
l2->Draw("SAME");
c2.Print("mult_mode.png");


// Calculate average multiplicity and average bin values for each mode
double averageMultiplicityQE = truemultQE->GetMean();
double averageMultiplicityRES = truemultRES->GetMean();
double averageMultiplicityDIS = truemultDIS->GetMean();
double averageMultiplicityCOH = truemultCOH->GetMean();
double averageMultiplicityMEC = truemultMEC->GetMean();

// Calculate total average multiplicity
double totalAverageMultiplicity = (averageMultiplicityQE + averageMultiplicityRES + averageMultiplicityDIS + averageMultiplicityCOH + averageMultiplicityMEC) / 5.0;


cout << "Average Multiplicity for QE: " << averageMultiplicityQE << endl;
cout << "Average Multiplicity for RES: " << averageMultiplicityRES << endl;
cout << "Average Multiplicity for DIS: " << averageMultiplicityDIS << endl;
cout << "Average Multiplicity for COH: " << averageMultiplicityCOH << endl;
cout << "Average Multiplicity for MEC: " << averageMultiplicityMEC << endl;
cout << "Total Average Multiplicity: " << totalAverageMultiplicity << endl;


////////// --------------------------------------------------------------- //////////

// // // Interaction Modes CC (Within Acceptance)

TH1D *truemultQE_CC=new TH1D("truemultQE_CC","truemultQE_CC",10,1,11);
TH1D *truemultRES_CC=new TH1D("truemultRES_CC","truemultRES_CC",10,1,11);
TH1D *truemultDIS_CC=new TH1D("truemultDIS_CC","truemultDIS_CC",10,1,11);
TH1D *truemultCOH_CC=new TH1D("truemultCOH_CC","truemultCOH_CC",10,1,11);
TH1D *truemultMEC_CC=new TH1D("truemultMEC_CC","truemultMEC_CC",10,1,11);
THStack *hs_CC = new THStack("hs_CC","Interaction Types in Observed Multiplicity Bins");
TCanvas c3=TCanvas();
c3.Draw();
tevt->Project("truemultQE_CC","_truemultQE","nu_ccnc == 0");
tevt->Project("truemultRES_CC","_truemultRES","nu_ccnc == 0");
tevt->Project("truemultDIS_CC","_truemultDIS","nu_ccnc == 0");
tevt->Project("truemultCOH_CC","_truemultCOH","nu_ccnc == 0");
tevt->Project("truemultMEC_CC","_truemultMEC","nu_ccnc == 0");
hs_CC->Add(truemultQE_CC);
hs_CC->Add(truemultRES_CC);
hs_CC->Add(truemultDIS_CC);
hs_CC->Add(truemultCOH_CC);
hs_CC->Add(truemultMEC_CC); 
truemultQE_CC->SetFillColor(kBlack);
truemultRES_CC->SetFillColor(kRed);
truemultDIS_CC->SetFillColor(kBlue);
truemultCOH_CC->SetFillColor(kGreen);
truemultMEC_CC->SetFillColor(6);
hs_CC->Draw("hist");
hs_CC->SetTitle(" ");
hs_CC->GetXaxis()->SetTitle("True Multiplicity CC");
hs_CC->GetYaxis()->SetTitle("Number of Events");
hs_CC->GetYaxis()->SetRangeUser(0, 500);
TLegend *l3 = new TLegend(0.65,0.65,0.95,0.88);
l3->AddEntry(truemultQE_CC,"QE ","F");  
l3->AddEntry(truemultRES_CC,"RES ","F");
l3->AddEntry(truemultDIS_CC,"DIS ","F");
l3->AddEntry(truemultCOH_CC,"COH ","F");
l3->AddEntry(truemultMEC_CC,"MEC ","F");
l3->Draw("SAME");
c3.Print("mult_mode_CC.png");

// Calculate average multiplicity for each mode (CC)
double averageMultiplicityQE_CC = truemultQE_CC->GetMean();
double averageMultiplicityRES_CC = truemultRES_CC->GetMean();
double averageMultiplicityDIS_CC = truemultDIS_CC->GetMean();
double averageMultiplicityCOH_CC = truemultCOH_CC->GetMean();
double averageMultiplicityMEC_CC = truemultMEC_CC->GetMean();

// Calculate total average multiplicity
double totalAverageMultiplicity_CC = (averageMultiplicityQE_CC + averageMultiplicityRES_CC + averageMultiplicityDIS_CC + averageMultiplicityCOH_CC + averageMultiplicityMEC_CC) / 5.0;


// Print the average multiplicity for each mode (CC)
cout << "Average Multiplicity for QE (CC): " << averageMultiplicityQE_CC << endl;
cout << "Average Multiplicity for RES (CC): " << averageMultiplicityRES_CC << endl;
cout << "Average Multiplicity for DIS (CC): " << averageMultiplicityDIS_CC << endl;
cout << "Average Multiplicity for COH (CC): " << averageMultiplicityCOH_CC << endl;
cout << "Average Multiplicity for MEC (CC): " << averageMultiplicityMEC_CC << endl;
cout << "Total Average Multiplicity (CC): " << totalAverageMultiplicity_CC << endl;


////////// --------------------------------------------------------------- //////////

// // // Interaction Modes NC (Within Acceptance)

TH1D *truemultQE_NC=new TH1D("truemultQE_NC","truemultQE_NC",10,1,11);
TH1D *truemultRES_NC=new TH1D("truemultRES_NC","truemultRES_NC",10,1,11);
TH1D *truemultDIS_NC=new TH1D("truemultDIS_NC","truemultDIS_NC",10,1,11);
TH1D *truemultCOH_NC=new TH1D("truemultCOH_NC","truemultCOH_NC",10,1,11);
TH1D *truemultMEC_NC=new TH1D("truemultMEC_NC","truemultMEC_NC",10,1,11);
THStack *hs_NC = new THStack("hs_NC","Interaction Types in Observed Multiplicity Bins");
TCanvas c4=TCanvas();
c4.Draw();
tevt->Project("truemultQE_NC","_truemultQE","nu_ccnc == 1");
tevt->Project("truemultRES_NC","_truemultRES","nu_ccnc == 1");
tevt->Project("truemultDIS_NC","_truemultDIS","nu_ccnc == 1");
tevt->Project("truemultCOH_NC","_truemultCOH","nu_ccnc == 1");
tevt->Project("truemultMEC_NC","_truemultMEC","nu_ccnc == 1");
hs_NC->Add(truemultQE_NC);
hs_NC->Add(truemultRES_NC);
hs_NC->Add(truemultDIS_NC);
hs_NC->Add(truemultCOH_NC);
hs_NC->Add(truemultMEC_NC); 
truemultQE_NC->SetFillColor(kBlack);
truemultRES_NC->SetFillColor(kRed);
truemultDIS_NC->SetFillColor(kBlue);
truemultCOH_NC->SetFillColor(kGreen);
truemultMEC_NC->SetFillColor(6);
hs_NC->Draw("hist");
hs_NC->SetTitle(" ");
hs_NC->GetXaxis()->SetTitle("True Multiplicity NC");
hs_NC->GetYaxis()->SetTitle("Number of Events");
hs_NC->GetYaxis()->SetRangeUser(0, 500);
TLegend *l4 = new TLegend(0.65,0.65,0.95,0.88);
l4->AddEntry(truemultQE_NC,"QE ","F");  
l4->AddEntry(truemultRES_NC,"RES ","F");
l4->AddEntry(truemultDIS_NC,"DIS ","F");
l4->AddEntry(truemultCOH_NC,"COH ","F");
l4->AddEntry(truemultMEC_NC,"MEC ","F");
l4->Draw("SAME");
c4.Print("mult_mode_NC.png");

// Calculate average multiplicity for each mode (NC)
double averageMultiplicityQE_NC = truemultQE_NC->GetMean();
double averageMultiplicityRES_NC = truemultRES_NC->GetMean();
double averageMultiplicityDIS_NC = truemultDIS_NC->GetMean();
double averageMultiplicityCOH_NC = truemultCOH_NC->GetMean();
double averageMultiplicityMEC_NC = truemultMEC_NC->GetMean();

// Calculate total average multiplicity
double totalAverageMultiplicity_NC = (averageMultiplicityQE_NC + averageMultiplicityRES_NC + averageMultiplicityDIS_NC + averageMultiplicityCOH_NC + averageMultiplicityMEC_NC) / 5.0;


// Print the average multiplicity for each mode (NC)
cout << "Average Multiplicity for QE (NC): " << averageMultiplicityQE_NC << endl;
cout << "Average Multiplicity for RES (NC): " << averageMultiplicityRES_NC << endl;
cout << "Average Multiplicity for DIS (NC): " << averageMultiplicityDIS_NC << endl;
cout << "Average Multiplicity for COH (NC): " << averageMultiplicityCOH_NC << endl;
cout << "Average Multiplicity for MEC (NC): " << averageMultiplicityMEC_NC << endl;
cout << "Total Average Multiplicity (NC): " << totalAverageMultiplicity_NC << endl;



////////// --------------------------------------------------------------- //////////


}
