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
void plotTrackMult2x2wTruth_NC()
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


// // // True Multiplicity for NCQE (No Cut)

TH1D *truemultmuNCQE=new TH1D("truemultmuNCQE","truemultmuNCQE",5,0,5);
TH1D *truemultenuNCQE=new TH1D("truemultenuNCQE","truemultenuNCQE",5,0,5);

TCanvas c1=TCanvas();
c1.Draw();
tevt->Project("truemultmuNCQE","_truemultmu","nu_ccnc == 1 && nu_mode == 0");
tevt->Project("truemultenuNCQE","_truemultenu","nu_ccnc == 1 && nu_mode == 0");

truemultmuNCQE->SetTitle(" ");
truemultmuNCQE->GetXaxis()->SetTitle("True Multiplicity for NCQE (No Cut)");
truemultmuNCQE->GetYaxis()->SetTitle("Number of Particles");
truemultmuNCQE->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCQE->SetLineColor(kRed);
truemultmuNCQE->SetLineStyle(1);
truemultenuNCQE->SetLineColor(kBlue);
truemultenuNCQE->SetLineStyle(1);

TLegend *l1 = new TLegend(0.4,0.65,0.80,0.88);
l1->AddEntry(truemultmuNCQE,"muons ","l");
l1->AddEntry(truemultenuNCQE,"electron neutrinos ","l");

truemultmuNCQE->Draw("HIST");
truemultenuNCQE->Draw("SAME HIST");
l1->Draw("SAME");
c1.Print("mult_mu_enu_NCQE.png");

////////// --------------------------------------------------------------- //////////

// // // True Multiplicity for NCRes (No Cut)

TH1D *truemultmuNCRes=new TH1D("truemultmuNCRes","truemultmuNCRes",5,0,5);
TH1D *truemultenuNCRes=new TH1D("truemultenuNCRes","truemultenuNCRes",5,0,5);

TCanvas c2=TCanvas();
c2.Draw();
tevt->Project("truemultmuNCRes","_truemultmu","nu_ccnc == 1 && nu_mode == 1");
tevt->Project("truemultenuNCRes","_truemultenu","nu_ccnc == 1 && nu_mode == 1");

truemultmuNCRes->SetTitle(" ");
truemultmuNCRes->GetXaxis()->SetTitle("True Multiplicity for NCRes (No Cut)");
truemultmuNCRes->GetYaxis()->SetTitle("Number of Particles");
truemultmuNCRes->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCRes->SetLineColor(kRed);
truemultmuNCRes->SetLineStyle(1);
truemultenuNCRes->SetLineColor(kBlue);
truemultenuNCRes->SetLineStyle(1);

TLegend *l2 = new TLegend(0.4,0.65,0.80,0.88);
l2->AddEntry(truemultmuNCRes,"muons ","l");
l2->AddEntry(truemultenuNCRes,"electron neutrinos ","l");

truemultmuNCRes->Draw("HIST");
truemultenuNCRes->Draw("SAME HIST");
l2->Draw("SAME");
c2.Print("mult_mu_enu_NCRes.png");


////////// --------------------------------------------------------------- //////////

// // // True Multiplicity for NCDIS (No Cut)

TH1D *truemultmuNCDIS=new TH1D("truemultmuNCDIS","truemultmuNCDIS",5,0,5);
TH1D *truemultenuNCDIS=new TH1D("truemultenuNCDIS","truemultenuNCDIS",5,0,5);

TCanvas c3=TCanvas();
c3.Draw();
tevt->Project("truemultmuNCDIS","_truemultmu","nu_ccnc == 1 && nu_mode == 2");
tevt->Project("truemultenuNCDIS","_truemultenu","nu_ccnc == 1 && nu_mode == 2");

truemultmuNCDIS->SetTitle(" ");
truemultmuNCDIS->GetXaxis()->SetTitle("True Multiplicity for NCDIS (No Cut)");
truemultmuNCDIS->GetYaxis()->SetTitle("Number of Particles");
truemultmuNCDIS->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCDIS->SetLineColor(kRed);
truemultmuNCDIS->SetLineStyle(1);
truemultenuNCDIS->SetLineColor(kBlue);
truemultenuNCDIS->SetLineStyle(1);

TLegend *l3 = new TLegend(0.4,0.65,0.80,0.88);
l3->AddEntry(truemultmuNCDIS,"muons ","l");
l3->AddEntry(truemultenuNCDIS,"electron neutrinos ","l");

truemultmuNCDIS->Draw("HIST");
truemultenuNCDIS->Draw("SAME HIST");
l3->Draw("SAME");
c3.Print("mult_mu_enu_NCDIS.png");


////////// --------------------------------------------------------------- //////////

// // // True Multiplicity for NCCOH (No Cut)

TH1D *truemultmuNCCOH=new TH1D("truemultmuNCCOH","truemultmuNCCOH",5,0,5);
TH1D *truemultenuNCCOH=new TH1D("truemultenuNCCOH","truemultenuNCCOH",5,0,5);

TCanvas c4=TCanvas();
c4.Draw();
tevt->Project("truemultmuNCCOH","_truemultmu","nu_ccnc == 1 && nu_mode == 3");
tevt->Project("truemultenuNCCOH","_truemultenu","nu_ccnc == 1 && nu_mode == 3");

truemultmuNCCOH->SetTitle(" ");
truemultmuNCCOH->GetXaxis()->SetTitle("True Multiplicity for NCCOH (No Cut)");
truemultmuNCCOH->GetYaxis()->SetTitle("Number of Particles");
truemultmuNCCOH->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCCOH->SetLineColor(kRed);
truemultmuNCCOH->SetLineStyle(1);
truemultenuNCCOH->SetLineColor(kBlue);
truemultenuNCCOH->SetLineStyle(1);

TLegend *l4 = new TLegend(0.4,0.65,0.80,0.88);
l4->AddEntry(truemultmuNCCOH,"muons ","l");
l4->AddEntry(truemultenuNCCOH,"electron neutrinos ","l");

truemultmuNCCOH->Draw("HIST");
truemultenuNCCOH->Draw("SAME HIST");
l4->Draw("SAME");
c4.Print("mult_mu_enu_NCCOH.png");


////////// --------------------------------------------------------------- //////////

// // // True Multiplicity for NCMEC (No Cut)

TH1D *truemultmuNCMEC=new TH1D("truemultmuNCMEC","truemultmuNCMEC",5,0,5);
TH1D *truemultenuNCMEC=new TH1D("truemultenuNCMEC","truemultenuNCMEC",5,0,5);

TCanvas c5=TCanvas();
c5.Draw();
tevt->Project("truemultmuNCMEC","_truemultmu","nu_ccnc == 1 && nu_mode == 10");
tevt->Project("truemultenuNCMEC","_truemultenu","nu_ccnc == 1 && nu_mode == 10");

truemultmuNCMEC->SetTitle(" ");
truemultmuNCMEC->GetXaxis()->SetTitle("True Multiplicity for NCMEC (No Cut)");
truemultmuNCMEC->GetYaxis()->SetTitle("Number of Particles");
truemultmuNCMEC->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCMEC->SetLineColor(kRed);
truemultmuNCMEC->SetLineStyle(1);
truemultenuNCMEC->SetLineColor(kBlue);
truemultenuNCMEC->SetLineStyle(1);

TLegend *l5 = new TLegend(0.4,0.65,0.80,0.88);
l5->AddEntry(truemultmuNCMEC,"muons ","l");
l5->AddEntry(truemultenuNCMEC,"electron neutrinos ","l");

truemultmuNCMEC->Draw("HIST");
truemultenuNCMEC->Draw("SAME HIST");
l5->Draw("SAME");
c5.Print("mult_mu_enu_NCMEC.png");


////////// --------------------------------------------------------------- //////////

// // //  True Muon and nu_e Multiplicity for CC (No Cut)

TH1D *truemultmu_NC=new TH1D("truemultmu_NC","truemultmu_NC",5,0,5);
TH1D *truemultenu_NC=new TH1D("truemultenu_NC","truemultenu_NC",5,0,5);

TCanvas c6=TCanvas();
c6.Draw();
tevt->Project("truemultmu_NC","_truemultmu","nu_ccnc == 1");
tevt->Project("truemultenu_NC","_truemultenu","nu_ccnc == 1");

truemultmu_NC->SetTitle(" ");
truemultmu_NC->GetXaxis()->SetTitle("True NC Multiplicity");
truemultmu_NC->GetYaxis()->SetTitle("Number of events");
truemultmu_NC->GetYaxis()->SetRangeUser(0, 3000);
truemultmu_NC->GetYaxis()->SetTitleOffset(1.2);
truemultmu_NC->SetLineColor(kRed);
truemultmu_NC->SetLineStyle(1);
truemultenu_NC->SetLineColor(kBlue);
truemultenu_NC->SetLineStyle(1);

TLegend *l6 = new TLegend(0.4,0.65,0.80,0.88);
l6->AddEntry(truemultmu_NC,"muons ","l");
l6->AddEntry(truemultenu_NC,"electron neutrinos ","l");

truemultmu_NC->Draw("HIST");
truemultenu_NC->Draw("SAME HIST");
l6->Draw("SAME");
c6.Print("mult_mu_enu_NC.png");

}

