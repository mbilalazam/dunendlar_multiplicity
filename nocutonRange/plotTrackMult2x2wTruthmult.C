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
void plotTrackMult2x2wTruthmult()
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


  
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/withcutonRange/TrackMult2x2wTruth.root");

TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


// // // True Multiplicity (No Cut)

TH1D *truemult=new TH1D("truemult","truemult",10,0,10);
TH1D *truemultmu=new TH1D("truemultmu","truemultmu",10,0,10);
TH1D *truemultpi=new TH1D("truemultpi","truemultpi",10,0,10);
TH1D *truemultk=new TH1D("truemultk","truemultk",10,0,10);
TH1D *truemultp=new TH1D("truemultp","truemultp",10,0,10);
TH1D *truemultpi0=new TH1D("truemultpi0","truemultpi0",10,0,10);
TH1D *truemultg=new TH1D("truemultg","truemultg",10,0,10);
TH1D *truemultn=new TH1D("truemultn","truemultn",10,0,10);
TH1D *truemulte=new TH1D("truemulte","truemulte",10,0,10);
TH1D *truemultenu=new TH1D("truemultenu","truemultenu",10,0,10);

TCanvas c1=TCanvas();
c1.Draw();
tevt->Project("truemult","_truemult");
tevt->Project("truemultmu","_truemultmu");
tevt->Project("truemultpi","_truemultpi");
tevt->Project("truemultk","_truemultk");
tevt->Project("truemultp","_truemultp");
tevt->Project("truemultpi0","_truemultpi0");
tevt->Project("truemultg","_truemultg");
tevt->Project("truemultn","_truemultn");
tevt->Project("truemulte","_truemulte");
tevt->Project("truemultenu","_truemultenu");

truemult->SetTitle(" ");
truemult->GetXaxis()->SetTitle("True Multiplicity");
truemult->GetYaxis()->SetTitle("Number of Events");
truemult->GetYaxis()->SetRangeUser(0, 3300);
truemult->GetYaxis()->SetTitleOffset(1.2);
truemult->SetLineColor(kBlack);
truemult->SetLineStyle(1);
truemultmu->SetLineColor(kRed);
truemultmu->SetLineStyle(2);
truemultpi->SetLineColor(kBlue);
truemultpi->SetLineStyle(3);
truemultk->SetLineColor(kGreen);
truemultk->SetLineStyle(4);
truemultpi0->SetLineColor(kOrange+1);
truemultpi0->SetLineStyle(1);
truemultg->SetLineColor(kCyan+2);
truemultg->SetLineStyle(1);
truemultn->SetLineColor(kViolet+2);
truemultn->SetLineStyle(2);
truemultp->SetLineColor(kPink+2);
truemultp->SetLineStyle(4);
truemulte->SetLineColor(kTeal+1);
truemulte->SetLineStyle(5);
truemultenu->SetLineColor(kYellow+2);
truemultenu->SetLineStyle(6);

TLegend *l1 = new TLegend(0.4,0.65,0.80,0.88);
l1->AddEntry(truemult,"all ","l");  
l1->AddEntry(truemultmu,"muons ","l");
l1->AddEntry(truemultpi,"pions ","l");
l1->AddEntry(truemultk,"kaons ","l");
l1->AddEntry(truemultp,"protons ","l");
l1->AddEntry(truemultpi0,"pion0 ","l");
l1->AddEntry(truemultg,"photons ","l");
l1->AddEntry(truemultn,"neutrons ","l");
l1->AddEntry(truemulte,"electrons ","l");
l1->AddEntry(truemultenu,"electron neutrino ","l");

truemult->Draw("HIST");
truemultmu->Draw("SAME HIST");
truemultpi->Draw("HIST SAME");
truemultpi0->Draw("HIST SAME");
truemultk->Draw("HIST SAME");
truemultp->Draw("SAME HIST");
truemultg->Draw("SAME HIST");
truemultn->Draw("SAME HIST");
truemulte->Draw("SAME HIST");
truemultenu->Draw("SAME HIST");
l1->Draw("SAME");
c1.Print("mult.png");

////////// --------------------------------------------------------------- //////////

// // // True Multiplicity CC (No Cut)

TH1D *truemult_CC=new TH1D("truemult_CC","truemult_CC",10,0,10);
TH1D *truemultmu_CC=new TH1D("truemultmu_CC","truemultmu_CC",10,0,10);
TH1D *truemultpi_CC=new TH1D("truemultpi_CC","truemultpi_CC",10,0,10);
TH1D *truemultk_CC=new TH1D("truemultk_CC","truemultk_CC",10,0,10);
TH1D *truemultp_CC=new TH1D("truemultp_CC","truemultp_CC",10,0,10);
TH1D *truemultpi0_CC=new TH1D("truemultpi0_CC","truemultpi0_CC",10,0,10);
TH1D *truemultg_CC=new TH1D("truemultg_CC","truemultg_CC",10,0,10);
TH1D *truemultn_CC=new TH1D("truemultn_CC","truemultn_CC",10,0,10);
TH1D *truemulte_CC=new TH1D("truemulte_CC","truemulte_CC",10,0,10);
TH1D *truemultenu_CC=new TH1D("truemultenu_CC","truemultenu_CC",10,0,10);

TCanvas c7=TCanvas();
c7.Draw();
tevt->Project("truemult_CC","_truemult","nu_ccnc == 0");
tevt->Project("truemultmu_CC","_truemultmu","nu_ccnc == 0");
tevt->Project("truemultpi_CC","_truemultpi","nu_ccnc == 0");
tevt->Project("truemultk_CC","_truemultk","nu_ccnc == 0");
tevt->Project("truemultp_CC","_truemultp","nu_ccnc == 0");
tevt->Project("truemultpi0_CC","_truemultpi0","nu_ccnc == 0");
tevt->Project("truemultg_CC","_truemultg","nu_ccnc == 0");
tevt->Project("truemultn_CC","_truemultn","nu_ccnc == 0");
tevt->Project("truemulte_CC","_truemulte","nu_ccnc == 0");
tevt->Project("truemultenu_CC","_truemultenu","nu_ccnc == 0");

truemult_CC->SetTitle(" ");
truemult_CC->GetXaxis()->SetTitle("True Multiplicity CC (No Cut)");
truemult_CC->GetYaxis()->SetTitle("Number of Events");
truemult_CC->GetYaxis()->SetRangeUser(0, 3300);
truemult_CC->GetYaxis()->SetTitleOffset(1.2);
truemult_CC->SetLineColor(kBlack);
truemult_CC->SetLineStyle(1);
truemultmu_CC->SetLineColor(kRed);
truemultmu_CC->SetLineStyle(2);
truemultpi_CC->SetLineColor(kBlue);
truemultpi_CC->SetLineStyle(3);
truemultk_CC->SetLineColor(kGreen);
truemultk_CC->SetLineStyle(4);
truemultpi0_CC->SetLineColor(kOrange+1);
truemultpi0_CC->SetLineStyle(1);
truemultg_CC->SetLineColor(kCyan+2);
truemultg_CC->SetLineStyle(1);
truemultn_CC->SetLineColor(kViolet+2);
truemultn_CC->SetLineStyle(2);
truemultp_CC->SetLineColor(kPink+2);
truemultp_CC->SetLineStyle(4);
truemulte_CC->SetLineColor(kTeal+1);
truemulte_CC->SetLineStyle(5);
truemultenu_CC->SetLineColor(kYellow+2);
truemultenu_CC->SetLineStyle(6);

TLegend *l7 = new TLegend(0.4,0.65,0.80,0.88);
l7->AddEntry(truemult_CC,"all ","l");  
l7->AddEntry(truemultmu_CC,"muons ","l");
l7->AddEntry(truemultpi_CC,"pions ","l");
l7->AddEntry(truemultk_CC,"kaons ","l");
l7->AddEntry(truemultp_CC,"protons ","l");
l7->AddEntry(truemultpi0_CC,"pion0 ","l");
l7->AddEntry(truemultg_CC,"photons ","l");
l7->AddEntry(truemultn_CC,"neutrons ","l");
l7->AddEntry(truemulte_CC,"electrons ","l");
l7->AddEntry(truemultenu_CC,"electron neutrino ","l");

truemult_CC->Draw("HIST");
truemultmu_CC->Draw("SAME HIST");
truemultpi_CC->Draw("HIST SAME");
truemultpi0_CC->Draw("HIST SAME");
truemultk_CC->Draw("HIST SAME");
truemultp_CC->Draw("SAME HIST");
truemultg_CC->Draw("SAME HIST");
truemultn_CC->Draw("SAME HIST");
truemulte_CC->Draw("SAME HIST");
truemultenu_CC->Draw("SAME HIST");
l7->Draw("SAME");
c7.Print("mult_CC.png");


////////// --------------------------------------------------------------- //////////

// // // True Multiplicity NC (No Cut)

TH1D *truemult_NC=new TH1D("truemult_NC","truemult_NC",10,0,10);
TH1D *truemultmu_NC=new TH1D("truemultmu_NC","truemultmu_NC",10,0,10);
TH1D *truemultpi_NC=new TH1D("truemultpi_NC","truemultpi_NC",10,0,10);
TH1D *truemultk_NC=new TH1D("truemultk_NC","truemultk_NC",10,0,10);
TH1D *truemultp_NC=new TH1D("truemultp_NC","truemultp_NC",10,0,10);
TH1D *truemultpi0_NC=new TH1D("truemultpi0_NC","truemultpi0_NC",10,0,10);
TH1D *truemultg_NC=new TH1D("truemultg_NC","truemultg_NC",10,0,10);
TH1D *truemultn_NC=new TH1D("truemultn_NC","truemultn_NC",10,0,10);
TH1D *truemulte_NC=new TH1D("truemulte_NC","truemulte_NC",10,0,10);
TH1D *truemultenu_NC=new TH1D("truemultenu_NC","truemultenu_NC",10,0,10);

TCanvas c6=TCanvas();
c6.Draw();
tevt->Project("truemult_NC","_truemult","nu_ccnc == 1");
tevt->Project("truemultmu_NC","_truemultmu","nu_ccnc == 1");
tevt->Project("truemultpi_NC","_truemultpi","nu_ccnc == 1");
tevt->Project("truemultk_NC","_truemultk","nu_ccnc == 1");
tevt->Project("truemultp_NC","_truemultp","nu_ccnc == 1");
tevt->Project("truemultpi0_NC","_truemultpi0","nu_ccnc == 1");
tevt->Project("truemultg_NC","_truemultg","nu_ccnc == 1");
tevt->Project("truemultn_NC","_truemultn","nu_ccnc == 1");
tevt->Project("truemulte_NC","_truemulte","nu_ccnc == 1");
tevt->Project("truemultenu_NC","_truemultenu","nu_ccnc == 1");

truemult_NC->SetTitle(" ");
truemult_NC->GetXaxis()->SetTitle("True Multiplicity NC (No Cut)");
truemult_NC->GetYaxis()->SetTitle("Number of Events");
truemult_NC->GetYaxis()->SetRangeUser(0, 3300);
truemult_NC->GetYaxis()->SetTitleOffset(1.2);
truemult_NC->SetLineColor(kBlack);
truemult_NC->SetLineStyle(1);
truemultmu_NC->SetLineColor(kRed);
truemultmu_NC->SetLineStyle(2);
truemultpi_NC->SetLineColor(kBlue);
truemultpi_NC->SetLineStyle(3);
truemultk_NC->SetLineColor(kGreen);
truemultk_NC->SetLineStyle(4);
truemultpi0_NC->SetLineColor(kOrange+1);
truemultpi0_NC->SetLineStyle(1);
truemultg_NC->SetLineColor(kCyan+2);
truemultg_NC->SetLineStyle(1);
truemultn_NC->SetLineColor(kViolet+2);
truemultn_NC->SetLineStyle(2);
truemultp_NC->SetLineColor(kPink+2);
truemultp_NC->SetLineStyle(4);
truemulte_NC->SetLineColor(kTeal+1);
truemulte_NC->SetLineStyle(5);
truemultenu_NC->SetLineColor(kYellow+2);
truemultenu_NC->SetLineStyle(6);

TLegend *l6 = new TLegend(0.4,0.65,0.80,0.88);
l6->AddEntry(truemult_NC,"all ","l");  
l6->AddEntry(truemultmu_NC,"muons ","l");
l6->AddEntry(truemultpi_NC,"pions ","l");
l6->AddEntry(truemultk_NC,"kaons ","l");
l6->AddEntry(truemultp_NC,"protons ","l");
l6->AddEntry(truemultpi0_NC,"pion0 ","l");
l6->AddEntry(truemultg_NC,"photons ","l");
l6->AddEntry(truemultn_NC,"neutrons ","l");
l6->AddEntry(truemulte_NC,"electrons ","l");
l6->AddEntry(truemultenu_NC,"electron neutrino ","l");

truemult_NC->Draw("HIST");
truemultmu_NC->Draw("SAME HIST");
truemultpi_NC->Draw("HIST SAME");
truemultpi0_NC->Draw("HIST SAME");
truemultk_NC->Draw("HIST SAME");
truemultp_NC->Draw("SAME HIST");
truemultg_NC->Draw("SAME HIST");
truemultn_NC->Draw("SAME HIST");
truemulte_NC->Draw("SAME HIST");
truemultenu_NC->Draw("SAME HIST");
l6->Draw("SAME");
c6.Print("mult_NC.png");

////////// --------------------------------------------------------------- //////////

// // // Interaction Modes (No Cut)

TH1D *truemultQE=new TH1D("truemultQE","truemultQE",10,0.5,10.5);
TH1D *truemultRES=new TH1D("truemultRES","truemultRES",10,0.5,10.5);
TH1D *truemultDIS=new TH1D("truemultDIS","truemultDIS",10,0.5,10.5);
TH1D *truemultCOH=new TH1D("truemultCOH","truemultCOH",10,0.5,10.5);
TH1D *truemultMEC=new TH1D("truemultMEC","truemultMEC",10,0.5,10.5);
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


////////// --------------------------------------------------------------- //////////

// // // Interaction Modes CC (No Cut)

TH1D *truemultQE_CC=new TH1D("truemultQE_CC","truemultQE_CC",10,0.5,10.5);
TH1D *truemultRES_CC=new TH1D("truemultRES_CC","truemultRES_CC",10,0.5,10.5);
TH1D *truemultDIS_CC=new TH1D("truemultDIS_CC","truemultDIS_CC",10,0.5,10.5);
TH1D *truemultCOH_CC=new TH1D("truemultCOH_CC","truemultCOH_CC",10,0.5,10.5);
TH1D *truemultMEC_CC=new TH1D("truemultMEC_CC","truemultMEC_CC",10,0.5,10.5);
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


////////// --------------------------------------------------------------- //////////

// // // Interaction Modes NC (No Cut)

TH1D *truemultQE_NC=new TH1D("truemultQE_NC","truemultQE_NC",10,0.5,10.5);
TH1D *truemultRES_NC=new TH1D("truemultRES_NC","truemultRES_NC",10,0.5,10.5);
TH1D *truemultDIS_NC=new TH1D("truemultDIS_NC","truemultDIS_NC",10,0.5,10.5);
TH1D *truemultCOH_NC=new TH1D("truemultCOH_NC","truemultCOH_NC",10,0.5,10.5);
TH1D *truemultMEC_NC=new TH1D("truemultMEC_NC","truemultMEC_NC",10,0.5,10.5);
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

}

