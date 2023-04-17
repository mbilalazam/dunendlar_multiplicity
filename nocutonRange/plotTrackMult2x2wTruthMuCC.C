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
void plotTrackMult2x2wTruthMuCC()
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


TH1D *truemultmuCCQE=new TH1D("truemultmuCCQE","truemultmuCCQE",5,0,5);
TCanvas c1=TCanvas();
c1.Draw();
tevt->Project("truemultmuCCQE","_truemultmu","nu_ccnc == 0 && nu_mode == 0");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuCCQE->GetNbinsX(); i++) {
    int binEntries = truemultmuCCQE->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuCCQE->GetBinLowEdge(i), binEntries);
    truemultmuCCQE->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuCCQE->SetTitle(" ");
truemultmuCCQE->GetXaxis()->SetTitle("True muon multiplicity for CCMEC within acceptance");
truemultmuCCQE->GetYaxis()->SetTitle("Number of particles");
truemultmuCCQE->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCQE->SetLineColor(kBlue);
truemultmuCCQE->Draw("HISTE1");
c1.Print("mult_muCCQE.png");


TH1D *truemultmuCCRes=new TH1D("truemultmuCCRes","truemultmuCCRes",5,0,5);
TCanvas c2=TCanvas();
c2.Draw();
tevt->Project("truemultmuCCRes","_truemultmu","nu_ccnc == 0 && nu_mode == 1");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuCCRes->GetNbinsX(); i++) {
    int binEntries = truemultmuCCRes->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuCCRes->GetBinLowEdge(i), binEntries);
    truemultmuCCRes->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuCCRes->SetTitle(" ");
truemultmuCCRes->GetXaxis()->SetTitle("True muon multiplicity for CCRes within acceptance");
truemultmuCCRes->GetYaxis()->SetTitle("Number of particles");
truemultmuCCRes->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCRes->SetLineColor(kBlue);
truemultmuCCRes->Draw("HISTE1");
c2.Print("mult_muCCRes.png");


TH1D *truemultmuCCDIS=new TH1D("truemultmuCCDIS","truemultmuCCDIS",5,0,5);
TCanvas c3=TCanvas();
c3.Draw();
tevt->Project("truemultmuCCDIS","_truemultmu","nu_ccnc == 0 && nu_mode == 2");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuCCDIS->GetNbinsX(); i++) {
    int binEntries = truemultmuCCDIS->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuCCDIS->GetBinLowEdge(i), binEntries);
    truemultmuCCDIS->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuCCDIS->SetTitle(" ");
truemultmuCCDIS->GetXaxis()->SetTitle("True muon multiplicity for CCDIS within acceptance");
truemultmuCCDIS->GetYaxis()->SetTitle("Number of particles");
truemultmuCCDIS->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCDIS->SetLineColor(kBlue);
truemultmuCCDIS->Draw("HISTE1");
c3.Print("mult_muCCDIS.png");


TH1D *truemultmuCCCOH=new TH1D("truemultmuCCCOH","truemultmuCCCOH",5,0,5);
TCanvas c4=TCanvas();
c4.Draw();
tevt->Project("truemultmuCCCOH","_truemultmu","nu_ccnc == 0 && nu_mode == 3");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuCCCOH->GetNbinsX(); i++) {
    int binEntries = truemultmuCCCOH->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuCCCOH->GetBinLowEdge(i), binEntries);
    truemultmuCCCOH->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuCCCOH->SetTitle(" ");
truemultmuCCCOH->GetXaxis()->SetTitle("True muon multiplicity for CCCOH within acceptance");
truemultmuCCCOH->GetYaxis()->SetTitle("Number of particles");
truemultmuCCCOH->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCCOH->SetLineColor(kBlue);
truemultmuCCCOH->Draw("HISTE1");
c4.Print("mult_muCCCOH.png");


TH1D *truemultmuCCMEC=new TH1D("truemultmuCCMEC","truemultmuCCMEC",5,0,5);
TCanvas c5=TCanvas();
c5.Draw();
tevt->Project("truemultmuCCMEC","_truemultmu","nu_ccnc == 0 && nu_mode == 10");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuCCMEC->GetNbinsX(); i++) {
    int binEntries = truemultmuCCMEC->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuCCMEC->GetBinLowEdge(i), binEntries);
    truemultmuCCMEC->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuCCMEC->SetTitle(" ");
truemultmuCCMEC->GetXaxis()->SetTitle("True muon multiplicity for CCMEC within acceptance");
truemultmuCCMEC->GetYaxis()->SetTitle("Number of particles");
truemultmuCCMEC->GetYaxis()->SetTitleOffset(1.2);
truemultmuCCMEC->SetLineColor(kBlue);
truemultmuCCMEC->Draw("HISTE1");
c5.Print("mult_muCCMEC.png");








}


