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
void plotTrackMult2x2wTruthMuNoCut()
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


TH1D *truemultmu=new TH1D("truemultmu","truemultmu",5,0,5);
TCanvas c3=TCanvas();
c3.Draw();
tevt->Project("truemultmu","_truemultmu");  

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmu->GetNbinsX(); i++) {
    int binEntries = truemultmu->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmu->GetBinLowEdge(i), binEntries);
    truemultmu->GetXaxis()->SetBinLabel(i, binLabel);
}

truemultmu->SetTitle(" ");
truemultmu->GetXaxis()->SetTitle("True muon multiplicity within acceptance");
truemultmu->GetYaxis()->SetTitle("Number of particles");
truemultmu->GetYaxis()->SetTitleOffset(1.2);
truemultmu->SetLineColor(kBlue);
truemultmu->Draw("HISTE1");
c3.Print("mult_mu_nocuts.png");



// It seems muCC and muNC variables are not working. //

TH1D *truemultmuCC=new TH1D("truemultmuCC","truemultmuCC",5,0,5);
TCanvas c4=TCanvas();
c4.Draw();
tevt->Project("truemultmuCC","_truemultmuCC");

// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuCC->GetNbinsX(); i++) {
    int binEntries = truemultmuCC->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuCC->GetBinLowEdge(i), binEntries);
    truemultmuCC->GetXaxis()->SetBinLabel(i, binLabel);
}


truemultmuCC->SetTitle(" ");
truemultmuCC->GetXaxis()->SetTitle("True muon multiplicity for all CC within acceptance");
truemultmuCC->GetYaxis()->SetTitle("Number of particles");
truemultmuCC->GetYaxis()->SetTitleOffset(1.2);
truemultmuCC->SetLineColor(kBlue);
truemultmuCC->Draw("HISTE1");
c4.Print("mult_muCC_branch.png");


TH1D *truemultmuNC=new TH1D("truemultmuNC","truemultmuNC",5,0,5);
TCanvas c5=TCanvas();
c5.Draw();
tevt->Project("truemultmuNC","_truemultmuNC");


// Loop over bins and add number of entries to bin label
for (int i = 1; i <= truemultmuNC->GetNbinsX(); i++) {
    int binEntries = truemultmuNC->GetBinContent(i);
    TString binLabel = Form("%.0f (%d)", truemultmuNC->GetBinLowEdge(i), binEntries);
    truemultmuNC->GetXaxis()->SetBinLabel(i, binLabel);
}


truemultmuNC->SetTitle(" ");
truemultmuNC->GetXaxis()->SetTitle("True muon multiplicity for all NC within acceptance");
truemultmuNC->GetYaxis()->SetTitle("Number of particles");
truemultmuNC->GetYaxis()->SetTitleOffset(1.2);
truemultmuNC->SetLineColor(kBlue);
truemultmuNC->Draw("HISTE1");
c5.Print("mult_muNC_branch.png");

}


