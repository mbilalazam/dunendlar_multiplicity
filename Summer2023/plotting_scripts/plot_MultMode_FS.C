// This script is used to plot the different final state particles for conditions from different trees for different interaction types and interaction modes.
// vector<int> ccnc;             //0: CC; 1: NC
// vector<int> mode;             //0: QE; 1: Resonance; 2: DIS; 3: Coherent pion; 10: MEC
// It also calculates the total number of enteries and their percentage in each bin.


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
void plot_MultMode_FS()
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


// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth_morethan50MeVke.root");
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");


TTree* tevt = (TTree*)f.Get("evtTree");
TTree* tmcp = (TTree*)f.Get("mcpTree");
TTree* tsed = (TTree*)f.Get("sedTree");

// Multiplicity CC

int numBins = 10; // Number of bins (50 MeV per bin)
double minRange = 1; // Minimum range in MeV
double maxRange = 11; // Maximum range in MeV

TH1D *truekeQE_CC = new TH1D("truekeQE_CC", "truekeQE_CC", numBins, minRange, maxRange);
TH1D *truekeRES_CC = new TH1D("truekeRES_CC", "truekeRES_CC", numBins, minRange, maxRange);
TH1D *truekeDIS_CC = new TH1D("truekeDIS_CC", "truekeDIS_CC", numBins, minRange, maxRange);
TH1D *truekeCOH_CC = new TH1D("truekeCOH_CC", "truekeCOH_CC", numBins, minRange, maxRange);
TH1D *truekeMEC_CC = new TH1D("truekeMEC_CC", "truekeMEC_CC", numBins, minRange, maxRange);

THStack *hs_CC = new THStack("hs_CC", "Interaction Types in Observed Multiplicity Bins");
TCanvas c3;
c3.Draw();

// Add these lines to create a TEventList with the desired condition
tevt->Draw(">>eventList_CCQE", "nu_ccnc == 0 && nu_mode == 0", "goff");
TEventList *eventList_CCQE = (TEventList*)gDirectory->Get("eventList_CCQE");

tevt->Draw(">>eventList_CCRES", "nu_ccnc == 0 && nu_mode == 1", "goff");
TEventList *eventList_CCRES = (TEventList*)gDirectory->Get("eventList_CCRES");

tevt->Draw(">>eventList_CCDIS", "nu_ccnc == 0 && nu_mode == 2", "goff");
TEventList *eventList_CCDIS = (TEventList*)gDirectory->Get("eventList_CCDIS");

tevt->Draw(">>eventList_CCCOH", "nu_ccnc == 0 && nu_mode == 3", "goff");
TEventList *eventList_CCCOH = (TEventList*)gDirectory->Get("eventList_CCCOH");

tevt->Draw(">>eventList_CCMEC", "nu_ccnc == 0 && nu_mode == 10", "goff");
TEventList *eventList_CCMEC = (TEventList*)gDirectory->Get("eventList_CCMEC");

    // Modify the evtTree to only include events satisfying the condition
    tevt->SetBranchStatus("*", 0);
    tevt->SetBranchStatus("_truemultn", 1);

    Int_t _truemultn;
	Int_t _truemcppdg;
    Float_t _truemcpKE;

    tevt->SetBranchAddress("_truemultn", &_truemultn);
    tmcp->SetBranchAddress("_truemcpKE", &_truemcpKE);
    tmcp->SetBranchAddress("_truemcppdg", &_truemcppdg);


    // QE: Loop over the entries and fill histograms
    Long64_t numEntries_CCQE = eventList_CCQE->GetN();
    for (Long64_t i = 0; i < numEntries_CCQE; ++i) {
        Long64_t entry_CCQE = eventList_CCQE->GetEntry(i);
        tevt->GetEntry(entry_CCQE);

        // Retrieve _truemcpKE from mcpTree
        if (tmcp->GetEntry(entry_CCQE) > 0 && _truemcpKE > 0.05) {
        // if (tmcp->GetEntry(entry_CCQE) > 0) {
            truekeQE_CC->Fill(_truemultn);
        }
    }

    // RES
    Long64_t numEntries_CCRES = eventList_CCRES->GetN();
    for (Long64_t i = 0; i < numEntries_CCRES; ++i) {
        Long64_t entry_CCRES = eventList_CCRES->GetEntry(i);
        tevt->GetEntry(entry_CCRES);

        // Retrieve _truemcpKE from mcpTree
        if (tmcp->GetEntry(entry_CCRES) > 0 && _truemcpKE > 0.05) {
        // if (tmcp->GetEntry(entry_CCRES) > 0) {
            truekeRES_CC->Fill(_truemultn);
        }
    }

    // DIS
    Long64_t numEntries_CCDIS = eventList_CCDIS->GetN();
    for (Long64_t i = 0; i < numEntries_CCDIS; ++i) {
        Long64_t entry_CCDIS = eventList_CCDIS->GetEntry(i);
        tevt->GetEntry(entry_CCDIS);

        // Retrieve _truemcpKE from mcpTree
        if (tmcp->GetEntry(entry_CCDIS) > 0 && _truemcpKE > 0.05) {
        // if (tmcp->GetEntry(entry_CCDIS) > 0) {
            truekeDIS_CC->Fill(_truemultn);
        }
    }

    // COH
    Long64_t numEntries_CCCOH = eventList_CCCOH->GetN();
    for (Long64_t i = 0; i < numEntries_CCCOH; ++i) {
        Long64_t entry_CCCOH = eventList_CCCOH->GetEntry(i);
        tevt->GetEntry(entry_CCCOH);

        // Retrieve _truemcpKE from mcpTree
        if (tmcp->GetEntry(entry_CCCOH) > 0 && _truemcpKE > 0.05) {
        // if (tmcp->GetEntry(entry_CCCOH) > 0) {
            truekeCOH_CC->Fill(_truemultn);
        }
    }

    // MEC
    Long64_t numEntries_CCMEC = eventList_CCMEC->GetN();
    for (Long64_t i = 0; i < numEntries_CCMEC; ++i) {
        Long64_t entry_CCMEC = eventList_CCMEC->GetEntry(i);
        tevt->GetEntry(entry_CCMEC);

        // Retrieve _truemcpKE from mcpTree
        if (tmcp->GetEntry(entry_CCMEC) > 0 && _truemcpKE > 0.05) {
        // if (tmcp->GetEntry(entry_CCMEC) > 0) {
            truekeMEC_CC->Fill(_truemultn);
        }
    }

hs_CC->Add(truekeQE_CC);
hs_CC->Add(truekeRES_CC);
hs_CC->Add(truekeDIS_CC);
hs_CC->Add(truekeCOH_CC);
hs_CC->Add(truekeMEC_CC);
truekeQE_CC->SetFillColor(kBlack);
truekeRES_CC->SetFillColor(kRed);
truekeDIS_CC->SetFillColor(kBlue);
truekeCOH_CC->SetFillColor(kGreen);
truekeMEC_CC->SetFillColor(6);
hs_CC->Draw("hist");
hs_CC->SetTitle(" ");
hs_CC->GetXaxis()->SetTitle("Multiplicity");
hs_CC->GetYaxis()->SetTitle("Number of Final State CC Neutrons");
hs_CC->GetYaxis()->SetRangeUser(0, 500);
TLegend *l3 = new TLegend(0.65, 0.65, 0.95, 0.88);

double totalEvents = truekeQE_CC->Integral() + truekeRES_CC->Integral() + truekeDIS_CC->Integral() + truekeCOH_CC->Integral() + truekeMEC_CC->Integral();

double percentageQE = (truekeQE_CC->Integral() / totalEvents) * 100;
double percentageRES = (truekeRES_CC->Integral() / totalEvents) * 100;
double percentageDIS = (truekeDIS_CC->Integral() / totalEvents) * 100;
double percentageCOH = (truekeCOH_CC->Integral() / totalEvents) * 100;
double percentageMEC = (truekeMEC_CC->Integral() / totalEvents) * 100;

l3->AddEntry(truekeQE_CC, Form("QE (%.2f%%, %g)", percentageQE, truekeQE_CC->GetEntries()), "F");
l3->AddEntry(truekeRES_CC, Form("RES (%.2f%%, %g)", percentageRES, truekeRES_CC->GetEntries()), "F");
l3->AddEntry(truekeDIS_CC, Form("DIS (%.2f%%, %g)", percentageDIS, truekeDIS_CC->GetEntries()), "F");
l3->AddEntry(truekeCOH_CC, Form("COH (%.2f%%, %g)", percentageCOH, truekeCOH_CC->GetEntries()), "F");
l3->AddEntry(truekeMEC_CC, Form("MEC (%.2f%%, %g)", percentageMEC, truekeMEC_CC->GetEntries()), "F");
l3->Draw("SAME");

// c3.Print("FS_n_multModeCC_noCut.png");
c3.Print("FS_n_multModeCC_noCut_cutOn50MeVke.png");
// c3.Print("FS_n_multModeCC_morethan50MeVke_onAllParticles.png");

}
