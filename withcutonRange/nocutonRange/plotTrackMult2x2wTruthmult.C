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


  
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/TrackMult2x2wTruth.root");


TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


TH1D *truemult=new TH1D("truemult","truemult",10,0,10);
TH1D *truemultmu=new TH1D("truemultmu","truemultmu",10,0,10);
TH1D *truemultpi=new TH1D("truemultpi","truemultpi",10,0,10);
TH1D *truemultk=new TH1D("truemultk","truemultk",10,0,10);
TH1D *truemultp=new TH1D("truemultp","truemultp",10,0,10);
TH1D *truemultpi0=new TH1D("truemultpi0","truemultpi0",10,0,10);
TH1D *truemultg=new TH1D("truemultg","truemultg",10,0,10);
TCanvas c1=TCanvas();
c1.Draw();
tevt->Project("truemult","_truemult");
tevt->Project("truemultmu","_truemultmu");
tevt->Project("truemultpi","_truemultpi");
tevt->Project("truemultk","_truemultk");
tevt->Project("truemultp","_truemultp");
tevt->Project("truemultpi0","_truemultpi0");
tevt->Project("truemultg","_truemultg");
truemult->SetTitle(" ");
truemult->GetXaxis()->SetTitle("True multiplicity within acceptance");
truemult->GetYaxis()->SetTitle("Number of events");
truemult->GetYaxis()->SetRangeUser(0, 4000);
truemult->GetYaxis()->SetTitleOffset(1.2);

// Scale the histograms
// truemult->Scale(1.f/truemult->GetEntries());
// truemultmu->Scale(1.f/truemultmu->GetEntries());
// truemultpi->Scale(1.f/truemultpi->GetEntries());
// truemultk->Scale(1.f/truemultk->GetEntries());
// truemultpi0->Scale(1.f/truemultpi0->GetEntries());
// truemultg->Scale(1.f/truemultg->GetEntries());
// truemultp->Scale(1.f/truemultp->GetEntries());


truemultmu->SetLineColor(kRed);
truemultmu->SetLineStyle(2);
truemultpi->SetLineColor(kBlue);
truemultpi->SetLineStyle(3);
truemultk->SetLineColor(kGreen);
truemultk->SetLineStyle(4);
truemultpi0->SetLineColor(kOrange);
truemultpi0->SetLineStyle(1);
truemultg->SetLineColor(kCyan+2);
truemultg->SetLineStyle(1);
truemultp->SetLineColor(6);
truemultp->SetLineStyle(5);
  TLegend *l = new TLegend(0.4,0.65,0.80,0.88);
  l->AddEntry(truemult,"all ","l");  
  l->AddEntry(truemultmu,"muons ","l");
  l->AddEntry(truemultpi,"pions ","l");
  l->AddEntry(truemultk,"kaons ","l");
  l->AddEntry(truemultp,"protons ","l");
  l->AddEntry(truemultpi0,"pion0 ","l");
  l->AddEntry(truemultg,"photons ","l");

truemult->Draw("HIST");
truemultmu->Draw("SAME HIST");
truemultpi->Draw("HIST SAME");
truemultpi0->Draw("HIST SAME");
truemultk->Draw("HIST SAME");
truemultp->Draw("SAME HIST");
truemultg->Draw("SAME HIST");
l->Draw("SAME");
c1.Print("mult.png");



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
hs->GetXaxis()->SetTitle("True multiplicity within acceptance");
hs->GetYaxis()->SetTitle("Number of events");
hs->GetYaxis()->SetRangeUser(0, 500);
  TLegend *l2 = new TLegend(0.65,0.65,0.95,0.88);
  l2->AddEntry(truemultQE,"QE ","F");  
  l2->AddEntry(truemultRES,"RES ","F");
  l2->AddEntry(truemultDIS,"DIS ","F");
  l2->AddEntry(truemultCOH,"COH ","F");
  l2->AddEntry(truemultMEC,"MEC ","F");
l2->Draw("SAME");
c2.Print("mult_mode.png");



}


