// This script is used to count the number of events in each.
//   vector<int> ccnc;             //0: CC; 1: NC

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
void plotMultModeCount()
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


TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth_morethan50MeVke.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");


TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


// // // Interaction Modes CC

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


// c3.Print("mult_mode_CC_0to10MeV.png");
c3.Print("mult_mode_CC_morethan50MeVke.png");


int _truemultRES;
int _truemultQE;
tevt->SetBranchAddress("_truemultRES", &_truemultRES);
tevt->SetBranchAddress("_truemultQE", &_truemultQE);

double bin1Value = truemultQE_CC->GetBinContent(3); // Get the bin 1 values of _truemultRES_CC

// Int_t _truemcppdg[3]; // Array to store the PDG codes of three particles
// Float_t _truemcpKE[3]; // Array to store the kinetic energies of three particles
// tmcp->SetBranchAddress("_truemcppdg", &_truemcppdg);
// tmcp->SetBranchAddress("_truemcpKE", &_truemcpKE);

// for (Long64_t i = 0; i < tevt->GetEntries(); ++i) {
    // tevt->GetEntry(i);
    // if (truemultQE_CC->GetBinContent(_truemultQE) == bin1Value) {
        // tmcp->GetEntry(i);
        // for (int j = 0; j < _truemultQE; ++j) {
            // if (_truemcppdg[j] != 0) { // Check if PDG code is non-zero (valid)
                // std::cout << "Event " << i << ", Particle " << j << ": PDG code = " << _truemcppdg[j] << std::endl;
            // }
        // }
    // }
// }

Int_t _truemcppdg; 
Float_t _truemcpKE; 
tmcp->SetBranchAddress("_truemcppdg", &_truemcppdg);
tmcp->SetBranchAddress("_truemcpKE", &_truemcpKE);

for (Long64_t i = 0; i < tevt->GetEntries(); ++i) {
    tevt->GetEntry(i);
    if (truemultQE_CC->GetBinContent(_truemultQE) == bin1Value) {
        tmcp->GetEntry(i);
        for (int j = 0; j < _truemultQE; ++j) {
            if (_truemcppdg != 0) { // Check if PDG code is non-zero (valid)
                // std::cout << "Event " << i << ", Particle " << j << ": PDG code = " << _truemcppdg[j] << std::endl;
                std::cout << _truemcpKE << std::endl;
            }
        }
    }
}





////////// --------------------------------------------------------------- //////////


}
