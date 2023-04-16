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
void plotTrackMult2x2wTruthMuNC()
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
  
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/TrackMult2x2wTruth.root");


TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


TH1D *truemultmuNCQE=new TH1D("truemultmuNCQE","truemultmuNCQE",5,0,5);
TCanvas c1=TCanvas();
c1.Draw();
tevt->Project("truemultmuNCQE","_truemultmu","nu_ccnc == 1 && nu_mode == 0");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuNCQE->GetNbinsX(); i++) {
    int binEntries = truemultmuNCQE->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuNCQE->GetBinLowEdge(i), binEntries);
    truemultmuNCQE->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuNCQE->SetTitle(" ");
truemultmuNCQE->GetXaxis()->SetTitle("True muon multiplicity for CCMEC within acceptance");
truemultmuNCQE->GetYaxis()->SetTitle("Number of particles");
truemultmuNCQE->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCQE->SetLineColor(kBlue);
truemultmuNCQE->Draw("HISTE1");
c1.Print("mult_muNCQE.png");


TH1D *truemultmuNCRes=new TH1D("truemultmuNCRes","truemultmuNCRes",5,0,5);
TCanvas c2=TCanvas();
c2.Draw();
tevt->Project("truemultmuNCRes","_truemultmu","nu_ccnc == 1 && nu_mode == 1");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuNCRes->GetNbinsX(); i++) {
    int binEntries = truemultmuNCRes->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuNCRes->GetBinLowEdge(i), binEntries);
    truemultmuNCRes->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuNCRes->SetTitle(" ");
truemultmuNCRes->GetXaxis()->SetTitle("True muon multiplicity for CCRes within acceptance");
truemultmuNCRes->GetYaxis()->SetTitle("Number of particles");
truemultmuNCRes->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCRes->SetLineColor(kBlue);
truemultmuNCRes->Draw("HISTE1");
c2.Print("mult_muNCRes.png");


TH1D *truemultmuNCDIS=new TH1D("truemultmuNCDIS","truemultmuNCDIS",5,0,5);
TCanvas c3=TCanvas();
c3.Draw();
tevt->Project("truemultmuNCDIS","_truemultmu","nu_ccnc == 1 && nu_mode == 2");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuNCDIS->GetNbinsX(); i++) {
    int binEntries = truemultmuNCDIS->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuNCDIS->GetBinLowEdge(i), binEntries);
    truemultmuNCDIS->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuNCDIS->SetTitle(" ");
truemultmuNCDIS->GetXaxis()->SetTitle("True muon multiplicity for CCDIS within acceptance");
truemultmuNCDIS->GetYaxis()->SetTitle("Number of particles");
truemultmuNCDIS->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCDIS->SetLineColor(kBlue);
truemultmuNCDIS->Draw("HISTE1");
c3.Print("mult_muNCDIS.png");


TH1D *truemultmuNCCOH=new TH1D("truemultmuNCCOH","truemultmuNCCOH",5,0,5);
TCanvas c4=TCanvas();
c4.Draw();
tevt->Project("truemultmuNCCOH","_truemultmu","nu_ccnc == 1 && nu_mode == 3");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuNCCOH->GetNbinsX(); i++) {
    int binEntries = truemultmuNCCOH->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuNCCOH->GetBinLowEdge(i), binEntries);
    truemultmuNCCOH->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuNCCOH->SetTitle(" ");
truemultmuNCCOH->GetXaxis()->SetTitle("True muon multiplicity for CCCOH within acceptance");
truemultmuNCCOH->GetYaxis()->SetTitle("Number of particles");
truemultmuNCCOH->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCCOH->SetLineColor(kBlue);
truemultmuNCCOH->Draw("HISTE1");
c4.Print("mult_muNCCOH.png");


TH1D *truemultmuNCMEC=new TH1D("truemultmuNCMEC","truemultmuNCMEC",5,0,5);
TCanvas c5=TCanvas();
c5.Draw();
tevt->Project("truemultmuNCMEC","_truemultmu","nu_ccnc == 1 && nu_mode == 10");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuNCMEC->GetNbinsX(); i++) {
    int binEntries = truemultmuNCMEC->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuNCMEC->GetBinLowEdge(i), binEntries);
    truemultmuNCMEC->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmuNCMEC->SetTitle(" ");
truemultmuNCMEC->GetXaxis()->SetTitle("True muon multiplicity for CCMEC within acceptance");
truemultmuNCMEC->GetYaxis()->SetTitle("Number of particles"); 
truemultmuNCMEC->GetYaxis()->SetTitleOffset(1.2);
truemultmuNCMEC->SetLineColor(kBlue);
truemultmuNCMEC->Draw("HISTE1");
c5.Print("mult_muNCMEC.png");


}


