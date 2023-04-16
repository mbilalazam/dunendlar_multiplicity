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
void plotTrackMult2x2wTruthMuCuts()
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

TH1D *truemultmu = new TH1D("truemultmu", "truemultmu", 10, -0.5, 9.5);
TCanvas c3 = TCanvas();
c3.Draw();

// Add these lines to create a TEventList with the desired condition
tmcp->Draw(">>eventList", "_truemcpCosTheta < 0.95", "goff");
//tmcp->Draw(">>eventList", "_truemcpCosTheta < 0.95 && _truemcppdg == 13", "goff");
TEventList *eventList = (TEventList*)gDirectory->Get("eventList");

// Add these lines to modify the evtTree to only include events satisfying the condition
tevt->SetBranchStatus("*", 0);
tevt->SetBranchStatus("_truemultmu", 1);
tevt->SetEventList(eventList);

tevt->Project("truemultmu", "_truemultmu");

truemultmu->SetTitle(" ");
truemultmu->GetXaxis()->SetTitle("True muon multiplicity within acceptance and cos(#theta)<0.95");
truemultmu->GetYaxis()->SetTitle("Number of particles");
truemultmu->GetYaxis()->SetTitleOffset(1.2);
truemultmu->SetLineColor(kRed);
truemultmu->Draw("HISTE1");
c3.Print("mult_mu_c0p95.png");



}
