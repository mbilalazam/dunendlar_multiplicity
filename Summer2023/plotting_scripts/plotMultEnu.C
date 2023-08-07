// This script is used to plot the MCP True Energy, KE and/or Final Energy of MCP Neutrinos and/or other final state particles.

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
void plotMultEnu()
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


  
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth.root");  
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");


TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


// // // Energy

// TH1D *truemcpE=new TH1D("truemcpE","truemcpE",10,0,11);
// TH1D *truemcpKE=new TH1D("truemcpKE","truemcpKE",10,0,11);
TH1D *truemcpEndE=new TH1D("truemcpEndE","truemcpEndE",10,0,11);

TCanvas c1=TCanvas();
c1.Draw();
// tmcp->Project("truemcpE","_truemcpE", "abs(_truemcppdg == 14)");
// tmcp->Project("truemcpKE","_truemcpKE",  "abs(_truemcppdg == 12 || _truemcppdg == 14 || _truemcppdg == 16)");
tmcp->Project("truemcpEndE","_truemcpEndE", "abs(_truemcppdg == 12 || _truemcppdg == 14 || _truemcppdg == 16)");

truemcpEndE->SetTitle(" ");
truemcpEndE->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
truemcpEndE->GetYaxis()->SetTitle("Number of Events");
double maxY = 1.5 * truemcpEndE->GetMaximum();
truemcpEndE->GetYaxis()->SetRangeUser(0, maxY);
truemcpEndE->GetYaxis()->SetTitleOffset(1.2);
truemcpEndE->SetLineColor(kRed);
truemcpEndE->SetLineStyle(1);

// truemcpKE->SetTitle(" ");
// truemcpKE->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
// truemcpKE->GetYaxis()->SetTitle("Number of Events");
// double maxY = 1.5 * truemcpKE->GetMaximum();
// truemcpKE->GetYaxis()->SetRangeUser(0, maxY);
// truemcpKE->GetYaxis()->SetTitleOffset(1.2);
// truemcpKE->SetLineColor(kRed);
// truemcpKE->SetLineStyle(1);



// truemcpE->SetTitle(" ");
// truemcpE->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
// truemcpE->GetYaxis()->SetTitle("Number of Events");
// double maxY = 1.5 * truemcpE->GetMaximum();
// truemcpE->GetYaxis()->SetRangeUser(0, maxY);
// truemcpE->GetYaxis()->SetTitleOffset(1.2);
// truemcpE->SetLineColor(kBlack);
// truemcpE->SetLineStyle(1);
// truemcpKE->SetLineColor(kRed);
// truemcpKE->SetLineStyle(1);
// truemcpEndE->SetLineColor(kBlue);
// truemcpEndE->SetLineStyle(1);

// TLegend *l1 = new TLegend(0.4,0.65,0.80,0.88);
// l1->AddEntry(truemcpE,"True Energy ","l");  
// l1->AddEntry(truemcpKE,"Kinetic Energy ","l");
// l1->AddEntry(truemcpEndE,"Final Energy ","l");

// truemcpE->Draw("HIST");
// truemcpKE->Draw("SAME HIST");
// truemcpEndE->Draw("HIST SAME");
truemcpEndE->Draw("HIST");
// truemcpKE->Draw("HIST");


// l1->Draw("SAME");
c1.Print("nu_energy_0to10MeV.png");
// c1.Print("nu_energy_noCut.png");
// c1.Print("mult_accp50.png");
// c1.Print("nu_ke_noCut.png");
// c1.Print("nu_ke_0p05GeVke.png");


////////// --------------------------------------------------------------- //////////

// // // Energy CC


// TH1D *truemcpE_CC=new TH1D("truemcpE_CC","truemcpE_CC",10,1,11);
// TH1D *truemcpKE_CC=new TH1D("truemcpKE_CC","truemcpKE_CC",10,1,11);
TH1D *truemcpEndE_CC=new TH1D("truemcpEndE_CC","truemcpEndE_CC",10,1,11);

TCanvas c2=TCanvas();
c2.Draw();

// Add these lines to create a TEventList with the desired condition
tevt->Draw(">>eventList_CC", "nu_ccnc == 0", "goff");
TEventList *eventList_CC = (TEventList*)gDirectory->Get("eventList_CC");

// Add these lines to modify the evtTree to only include events satisfying the condition
tmcp->SetBranchStatus("*", 0);
// tmcp->SetBranchStatus("_truemcpE", 1);
// tmcp->SetBranchStatus("_truemcpKE", 1);
tmcp->SetBranchStatus("_truemcpEndE", 1);
tmcp->SetBranchStatus("_truemcppdg", 1);
tmcp->SetEventList(eventList_CC);


// tmcp->Project("truemcpE_CC","_truemcpE");
// tmcp->Project("truemcpKE_CC","_truemcpKE");
// tmcp->Project("truemcpEndE_CC","_truemcpEndE");
tmcp->Project("truemcpEndE","_truemcpEndE", "abs(_truemcppdg == 12 || _truemcppdg == 14 || _truemcppdg == 16)");


truemcpEndE_CC->SetTitle(" ");
truemcpEndE_CC->GetXaxis()->SetTitle("Final Energy (CC)");
truemcpEndE_CC->GetYaxis()->SetTitle("Number of Events");
// truemult_CC->GetYaxis()->SetRangeUser(0, 3300);
double maxY_CC = 1.5 * truemcpEndE_CC->GetMaximum();
truemcpEndE_CC->GetYaxis()->SetRangeUser(0, maxY_CC);
truemcpEndE_CC->GetYaxis()->SetTitleOffset(1.2);
truemcpEndE_CC->SetLineColor(kBlack);
truemcpEndE_CC->SetLineStyle(1);
// truemcpKE_CC->SetLineColor(kRed);
// truemcpKE_CC->SetLineStyle(1);
// truemcpEndE_CC->SetLineColor(kBlue);
// truemcpEndE_CC->SetLineStyle(1);

// TLegend *l2 = new TLegend(0.4,0.65,0.80,0.88);
// l2->AddEntry(truemcpE_CC,"True Energy ","l");  
// l2->AddEntry(truemcpKE_CC,"Kinetic Energy ","l");
// l2->AddEntry(truemcpEndE_CC,"Final Energy ","l");

// truemcpE_CC->Draw("HIST");
// truemcpKE_CC->Draw("SAME HIST");
truemcpEndE_CC->Draw("HIST");

// l2->Draw("SAME");
c2.Print("energyEnd_CC_0to10MeV.png");


////////// --------------------------------------------------------------- //////////

// // // Energy NC


// TH1D *truemcpE_NC=new TH1D("truemcpE_NC","truemcpE_NC",10,1,11);
// TH1D *truemcpKE_NC=new TH1D("truemcpKE_NC","truemcpKE_NC",10,1,11);
// TH1D *truemcpEndE_NC=new TH1D("truemcpEndE_NC","truemcpEndE_NC",10,1,11);

// TCanvas c3=TCanvas();
// c3.Draw();

// Add these lines to create a TEventList with the desired condition
// tevt->Draw(">>eventList_NC", "nu_ccnc == 1", "goff");
// TEventList *eventList_NC = (TEventList*)gDirectory->Get("eventList_NC");

// Add these lines to modify the evtTree to only include events satisfying the condition
// tmcp->SetBranchStatus("*", 0);
// tmcp->SetBranchStatus("_truemcpE", 1);
// tmcp->SetBranchStatus("_truemcpKE", 1);
// tmcp->SetBranchStatus("_truemcpEndE", 1);
// tmcp->SetEventList(eventList_NC);

// tmcp->Project("truemcpE_NC","_truemcpE");
// tmcp->Project("truemcpKE_NC","_truemcpKE");
// tmcp->Project("truemcpEndE_NC","_truemcpEndE");

// truemcpE_NC->SetTitle(" ");
// truemcpE_NC->GetXaxis()->SetTitle("Energy (NC)");
// truemcpE_NC->GetYaxis()->SetTitle("Number of Events");
// truemult_NC->GetYaxis()->SetRangeUser(0, 3300);
// double maxY_NC = 1.5 * truemcpE_NC->GetMaximum();
// truemcpE_NC->GetYaxis()->SetRangeUser(0, maxY_NC);
// truemcpE_NC->GetYaxis()->SetTitleOffset(1.2);
// truemcpE_NC->SetLineColor(kBlack);
// truemcpE_NC->SetLineStyle(1);
// truemcpKE_NC->SetLineColor(kRed);
// truemcpKE_NC->SetLineStyle(1);
// truemcpEndE_NC->SetLineColor(kBlue);
// truemcpEndE_NC->SetLineStyle(1);

// TLegend *l3 = new TLegend(0.4,0.65,0.80,0.88);
// l3->AddEntry(truemcpE_NC,"True Energy ","l");  
// l3->AddEntry(truemcpKE_NC,"Kinetic Energy ","l");
// l3->AddEntry(truemcpEndE_NC,"Final Energy ","l");

// truemcpE_NC->Draw("HIST");
// truemcpKE_NC->Draw("SAME HIST");
// truemcpEndE_NC->Draw("HIST SAME");

// l3->Draw("SAME");
// c3.Print("energy_NC.png");

////////// --------------------------------------------------------------- //////////


}
