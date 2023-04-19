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
void plotTrackMult2x2wTruth_CC()
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


// // // True Multiplicity for CCQE (No Cut)

TH1D *truemultmuCCQE=new TH1D("truemultmuCCQE","truemultmuCCQE",5,0,5);
TH1D *truemultenuCCQE=new TH1D("truemultenuCCQE","truemultenuCCQE",5,0,5);

TCanvas c1=TCanvas();
c1.Draw();
tevt->Project("truemultmuCCQE","_truemultmu","nu_ccnc == 0 && nu_mode == 0");
tevt->Project("truemultenuCCQE","_truemultenu","nu_ccnc == 0 && nu_mode == 0");

truemultmuCCQE->SetTitle(" ");
truemultmuCCQE->GetXaxis()->SetTitle("True Multiplicity for CCQE (No Cut)");
truemultmuCCQE->GetYaxis()->SetTitle("Number of Particles");
truemultmuCCQE->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCQE->SetLineColor(kRed);
truemultmuCCQE->SetLineStyle(1);
truemultenuCCQE->SetLineColor(kBlue);
truemultenuCCQE->SetLineStyle(1);

TLegend *l1 = new TLegend(0.4,0.65,0.80,0.88);
l1->AddEntry(truemultmuCCQE,"muons ","l");
l1->AddEntry(truemultenuCCQE,"electron neutrinos ","l");

truemultmuCCQE->Draw("HIST");
truemultenuCCQE->Draw("SAME HIST");
l1->Draw("SAME");
c1.Print("mult_mu_enu_CCQE.png");

////////// --------------------------------------------------------------- //////////

// // // True Multiplicity for CCRes (No Cut)

TH1D *truemultmuCCRes=new TH1D("truemultmuCCRes","truemultmuCCRes",5,0,5);
TH1D *truemultenuCCRes=new TH1D("truemultenuCCRes","truemultenuCCRes",5,0,5);

TCanvas c2=TCanvas();
c2.Draw();
tevt->Project("truemultmuCCRes","_truemultmu","nu_ccnc == 0 && nu_mode == 1");
tevt->Project("truemultenuCCRes","_truemultenu","nu_ccnc == 0 && nu_mode == 1");

truemultmuCCRes->SetTitle(" ");
truemultmuCCRes->GetXaxis()->SetTitle("True Multiplicity for CCRes (No Cut)");
truemultmuCCRes->GetYaxis()->SetTitle("Number of Particles");
truemultmuCCRes->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCRes->SetLineColor(kRed);
truemultmuCCRes->SetLineStyle(1);
truemultenuCCRes->SetLineColor(kBlue);
truemultenuCCRes->SetLineStyle(1);

TLegend *l2 = new TLegend(0.4,0.65,0.80,0.88);
l2->AddEntry(truemultmuCCRes,"muons ","l");
l2->AddEntry(truemultenuCCRes,"electron neutrinos ","l");

truemultmuCCRes->Draw("HIST");
truemultenuCCRes->Draw("SAME HIST");
l2->Draw("SAME");
c2.Print("mult_mu_enu_CCRes.png");


////////// --------------------------------------------------------------- //////////

// // // True Multiplicity for CCDIS (No Cut)

TH1D *truemultmuCCDIS=new TH1D("truemultmuCCDIS","truemultmuCCDIS",5,0,5);
TH1D *truemultenuCCDIS=new TH1D("truemultenuCCDIS","truemultenuCCDIS",5,0,5);

TCanvas c3=TCanvas();
c3.Draw();
tevt->Project("truemultmuCCDIS","_truemultmu","nu_ccnc == 0 && nu_mode == 2");
tevt->Project("truemultenuCCDIS","_truemultenu","nu_ccnc == 0 && nu_mode == 2");

truemultmuCCDIS->SetTitle(" ");
truemultmuCCDIS->GetXaxis()->SetTitle("True Multiplicity for CCDIS (No Cut)");
truemultmuCCDIS->GetYaxis()->SetTitle("Number of Particles");
truemultmuCCDIS->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCDIS->SetLineColor(kRed);
truemultmuCCDIS->SetLineStyle(1);
truemultenuCCDIS->SetLineColor(kBlue);
truemultenuCCDIS->SetLineStyle(1);

TLegend *l3 = new TLegend(0.4,0.65,0.80,0.88);
l3->AddEntry(truemultmuCCDIS,"muons ","l");
l3->AddEntry(truemultenuCCDIS,"electron neutrinos ","l");

truemultmuCCDIS->Draw("HIST");
truemultenuCCDIS->Draw("SAME HIST");
l3->Draw("SAME");
c3.Print("mult_mu_enu_CCDIS.png");


////////// --------------------------------------------------------------- //////////

// // // True Multiplicity for CCCOH (No Cut)

TH1D *truemultmuCCCOH=new TH1D("truemultmuCCCOH","truemultmuCCCOH",5,0,5);
TH1D *truemultenuCCCOH=new TH1D("truemultenuCCCOH","truemultenuCCCOH",5,0,5);

TCanvas c4=TCanvas();
c4.Draw();
tevt->Project("truemultmuCCCOH","_truemultmu","nu_ccnc == 0 && nu_mode == 3");
tevt->Project("truemultenuCCCOH","_truemultenu","nu_ccnc == 0 && nu_mode == 3");

truemultmuCCCOH->SetTitle(" ");
truemultmuCCCOH->GetXaxis()->SetTitle("True Multiplicity for CCCOH (No Cut)");
truemultmuCCCOH->GetYaxis()->SetTitle("Number of Particles");
truemultmuCCCOH->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCCOH->SetLineColor(kRed);
truemultmuCCCOH->SetLineStyle(1);
truemultenuCCCOH->SetLineColor(kBlue);
truemultenuCCCOH->SetLineStyle(1);

TLegend *l4 = new TLegend(0.4,0.65,0.80,0.88);
l4->AddEntry(truemultmuCCCOH,"muons ","l");
l4->AddEntry(truemultenuCCCOH,"electron neutrinos ","l");

truemultmuCCCOH->Draw("HIST");
truemultenuCCCOH->Draw("SAME HIST");
l4->Draw("SAME");
c4.Print("mult_mu_enu_CCCOH.png");


////////// --------------------------------------------------------------- //////////

// // // True Multiplicity for CCMEC (No Cut)

TH1D *truemultmuCCMEC=new TH1D("truemultmuCCMEC","truemultmuCCMEC",5,0,5);
TH1D *truemultenuCCMEC=new TH1D("truemultenuCCMEC","truemultenuCCMEC",5,0,5);

TCanvas c5=TCanvas();
c5.Draw();
tevt->Project("truemultmuCCMEC","_truemultmu","nu_ccnc == 0 && nu_mode == 10");
tevt->Project("truemultenuCCMEC","_truemultenu","nu_ccnc == 0 && nu_mode == 10");

truemultmuCCMEC->SetTitle(" ");
truemultmuCCMEC->GetXaxis()->SetTitle("True Multiplicity for CCMEC (No Cut)");
truemultmuCCMEC->GetYaxis()->SetTitle("Number of Particles");
truemultmuCCMEC->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCMEC->SetLineColor(kRed);
truemultmuCCMEC->SetLineStyle(1);
truemultenuCCMEC->SetLineColor(kBlue);
truemultenuCCMEC->SetLineStyle(1);

TLegend *l5 = new TLegend(0.4,0.65,0.80,0.88);
l5->AddEntry(truemultmuCCMEC,"muons ","l");
l5->AddEntry(truemultenuCCMEC,"electron neutrinos ","l");

truemultmuCCMEC->Draw("HIST");
truemultenuCCMEC->Draw("SAME HIST");
l5->Draw("SAME");
c5.Print("mult_mu_enu_CCMEC.png");


////////// --------------------------------------------------------------- //////////

// // //  True Muon and nu_e Multiplicity for CC (No Cut)

TH1D *truemultmu_CC=new TH1D("truemultmu_CC","truemultmu_CC",5,0,5);
TH1D *truemultenu_CC=new TH1D("truemultenu_CC","truemultenu_CC",5,0,5);

TCanvas c6=TCanvas();
c6.Draw();
tevt->Project("truemultmu_CC","_truemultmu","nu_ccnc == 0");
tevt->Project("truemultenu_CC","_truemultenu","nu_ccnc == 0");

truemultmu_CC->SetTitle(" ");
truemultmu_CC->GetXaxis()->SetTitle("True CC Multiplicity");
truemultmu_CC->GetYaxis()->SetTitle("Number of events");
truemultmu_CC->GetYaxis()->SetRangeUser(0, 3000);
truemultmu_CC->GetYaxis()->SetTitleOffset(1.2);
truemultmu_CC->SetLineColor(kRed);
truemultmu_CC->SetLineStyle(1);
truemultenu_CC->SetLineColor(kBlue);
truemultenu_CC->SetLineStyle(1);

TLegend *l6 = new TLegend(0.4,0.65,0.80,0.88);
l6->AddEntry(truemultmu_CC,"muons ","l");
l6->AddEntry(truemultenu_CC,"electron neutrinos ","l");

truemultmu_CC->Draw("HIST");
truemultenu_CC->Draw("SAME HIST");
l6->Draw("SAME");
c6.Print("mult_mu_enu_CC.png");

}

