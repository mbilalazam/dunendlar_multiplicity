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
void plotMult()
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


  
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/withcutonRange/TrackMult2x2wTruth.root");

TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


// // // True Multiplicity (No Cut)

TH1D *truemult=new TH1D("truemult","truemult",10,1,11);

TCanvas c1=TCanvas();
c1.Draw();
tevt->Project("truemult","_truemult");

int numEvents = truemult->GetEntries(); // Get the number of events

double sumMultiplicity = 0.0;
for (int i = 1; i <= truemult->GetNbinsX(); i++) {
    double binContent = truemult->GetBinContent(i);
    sumMultiplicity += binContent;
}

double averageMultiplicity = sumMultiplicity / numEvents;
double averageBins = truemult->GetMean();

cout << "Average Multiplicity: " << averageMultiplicity << endl;
cout << "Average of Bin Values: " << averageBins << endl;    // This is the average Multiplicity that is needed.


truemult->SetTitle(" ");
truemult->GetXaxis()->SetTitle("True Multiplicity");
truemult->GetYaxis()->SetTitle("Number of Events");
// truemult->GetYaxis()->SetRangeUser(0, 3300);
double maxY = 1.5 * truemult->GetMaximum();
truemult->GetYaxis()->SetRangeUser(0, maxY);
truemult->GetYaxis()->SetTitleOffset(1.2);
truemult->SetLineColor(kBlack);
truemult->SetLineStyle(1);

TLegend *l1 = new TLegend(0.4,0.65,0.80,0.88);
l1->AddEntry(truemult,"all ","l");  

truemult->Draw("HIST");
l1->Draw("SAME");
c1.Print("mult.png");

////////// --------------------------------------------------------------- //////////

// // // True Multiplicity CC (No Cut)

TH1D *truemult_CC=new TH1D("truemult_CC","truemult_CC",10,0,10);
// TH1D *truemultmu_CC=new TH1D("truemultmu_CC","truemultmu_CC",10,0,10);
// TH1D *truemultpi_CC=new TH1D("truemultpi_CC","truemultpi_CC",10,0,10);
// TH1D *truemultk_CC=new TH1D("truemultk_CC","truemultk_CC",10,0,10);
// TH1D *truemultp_CC=new TH1D("truemultp_CC","truemultp_CC",10,0,10);
// TH1D *truemultpi0_CC=new TH1D("truemultpi0_CC","truemultpi0_CC",10,0,10);
// TH1D *truemultg_CC=new TH1D("truemultg_CC","truemultg_CC",10,0,10);
// TH1D *truemultn_CC=new TH1D("truemultn_CC","truemultn_CC",10,0,10);
// TH1D *truemulte_CC=new TH1D("truemulte_CC","truemulte_CC",10,0,10);
// TH1D *truemultenu_CC=new TH1D("truemultenu_CC","truemultenu_CC",10,0,10);

TCanvas c7=TCanvas();
c7.Draw();
tevt->Project("truemult_CC","_truemult","nu_ccnc == 0");
// tevt->Project("truemultmu_CC","_truemultmu","nu_ccnc == 0");
// tevt->Project("truemultpi_CC","_truemultpi","nu_ccnc == 0");
// tevt->Project("truemultk_CC","_truemultk","nu_ccnc == 0");
// tevt->Project("truemultp_CC","_truemultp","nu_ccnc == 0");
// tevt->Project("truemultpi0_CC","_truemultpi0","nu_ccnc == 0");
// tevt->Project("truemultg_CC","_truemultg","nu_ccnc == 0");
// tevt->Project("truemultn_CC","_truemultn","nu_ccnc == 0");
// tevt->Project("truemulte_CC","_truemulte","nu_ccnc == 0");
// tevt->Project("truemultenu_CC","_truemultenu","nu_ccnc == 0");

truemult_CC->SetTitle(" ");
truemult_CC->GetXaxis()->SetTitle("True Multiplicity CC (No Cut)");
truemult_CC->GetYaxis()->SetTitle("Number of Events");
truemult_CC->GetYaxis()->SetRangeUser(0, 3300);
truemult_CC->GetYaxis()->SetTitleOffset(1.2);
truemult_CC->SetLineColor(kBlack);
truemult_CC->SetLineStyle(1);
// truemultmu_CC->SetLineColor(kRed);
// truemultmu_CC->SetLineStyle(2);
// truemultpi_CC->SetLineColor(kBlue);
// truemultpi_CC->SetLineStyle(3);
// truemultk_CC->SetLineColor(kGreen);
// truemultk_CC->SetLineStyle(4);
// truemultpi0_CC->SetLineColor(kOrange+1);
// truemultpi0_CC->SetLineStyle(1);
// truemultg_CC->SetLineColor(kCyan+2);
// truemultg_CC->SetLineStyle(1);
// truemultn_CC->SetLineColor(kViolet+2);
// truemultn_CC->SetLineStyle(2);
// truemultp_CC->SetLineColor(kPink+2);
// truemultp_CC->SetLineStyle(4);
// truemulte_CC->SetLineColor(kTeal+1);
// truemulte_CC->SetLineStyle(5);
// truemultenu_CC->SetLineColor(kYellow+2);
// truemultenu_CC->SetLineStyle(6);

// TLegend *l7 = new TLegend(0.4,0.65,0.80,0.88);
// l7->AddEntry(truemult_CC,"all ","l");  
// l7->AddEntry(truemultmu_CC,"muons ","l");
// l7->AddEntry(truemultpi_CC,"pions ","l");
// l7->AddEntry(truemultk_CC,"kaons ","l");
// l7->AddEntry(truemultp_CC,"protons ","l");
// l7->AddEntry(truemultpi0_CC,"pion0 ","l");
// l7->AddEntry(truemultg_CC,"photons ","l");
// l7->AddEntry(truemultn_CC,"neutrons ","l");
// l7->AddEntry(truemulte_CC,"electrons ","l");
// l7->AddEntry(truemultenu_CC,"electron neutrino ","l");

truemult_CC->Draw("HIST");
// truemultmu_CC->Draw("SAME HIST");
// truemultpi_CC->Draw("HIST SAME");
// truemultpi0_CC->Draw("HIST SAME");
// truemultk_CC->Draw("HIST SAME");
// truemultp_CC->Draw("SAME HIST");
// truemultg_CC->Draw("SAME HIST");
// truemultn_CC->Draw("SAME HIST");
// truemulte_CC->Draw("SAME HIST");
// truemultenu_CC->Draw("SAME HIST");
// l7->Draw("SAME");
c7.Print("mult_CC.png");


////////// --------------------------------------------------------------- //////////

// // // True Multiplicity NC (No Cut)

TH1D *truemult_NC=new TH1D("truemult_NC","truemult_NC",10,0,10);
// TH1D *truemultmu_NC=new TH1D("truemultmu_NC","truemultmu_NC",10,0,10);
// TH1D *truemultpi_NC=new TH1D("truemultpi_NC","truemultpi_NC",10,0,10);
// TH1D *truemultk_NC=new TH1D("truemultk_NC","truemultk_NC",10,0,10);
// TH1D *truemultp_NC=new TH1D("truemultp_NC","truemultp_NC",10,0,10);
// TH1D *truemultpi0_NC=new TH1D("truemultpi0_NC","truemultpi0_NC",10,0,10);
// TH1D *truemultg_NC=new TH1D("truemultg_NC","truemultg_NC",10,0,10);
// TH1D *truemultn_NC=new TH1D("truemultn_NC","truemultn_NC",10,0,10);
// TH1D *truemulte_NC=new TH1D("truemulte_NC","truemulte_NC",10,0,10);
// TH1D *truemultenu_NC=new TH1D("truemultenu_NC","truemultenu_NC",10,0,10);

TCanvas c6=TCanvas();
c6.Draw();
tevt->Project("truemult_NC","_truemult","nu_ccnc == 1");
// tevt->Project("truemultmu_NC","_truemultmu","nu_ccnc == 1");
// tevt->Project("truemultpi_NC","_truemultpi","nu_ccnc == 1");
// tevt->Project("truemultk_NC","_truemultk","nu_ccnc == 1");
// tevt->Project("truemultp_NC","_truemultp","nu_ccnc == 1");
// tevt->Project("truemultpi0_NC","_truemultpi0","nu_ccnc == 1");
// tevt->Project("truemultg_NC","_truemultg","nu_ccnc == 1");
// tevt->Project("truemultn_NC","_truemultn","nu_ccnc == 1");
// tevt->Project("truemulte_NC","_truemulte","nu_ccnc == 1");
// tevt->Project("truemultenu_NC","_truemultenu","nu_ccnc == 1");

truemult_NC->SetTitle(" ");
truemult_NC->GetXaxis()->SetTitle("True Multiplicity NC (No Cut)");
truemult_NC->GetYaxis()->SetTitle("Number of Events");
truemult_NC->GetYaxis()->SetRangeUser(0, 3300);
truemult_NC->GetYaxis()->SetTitleOffset(1.2);
truemult_NC->SetLineColor(kBlack);
truemult_NC->SetLineStyle(1);
// truemultmu_NC->SetLineColor(kRed);
// truemultmu_NC->SetLineStyle(2);
// truemultpi_NC->SetLineColor(kBlue);
// truemultpi_NC->SetLineStyle(3);
// truemultk_NC->SetLineColor(kGreen);
// truemultk_NC->SetLineStyle(4);
// truemultpi0_NC->SetLineColor(kOrange+1);
// truemultpi0_NC->SetLineStyle(1);
// truemultg_NC->SetLineColor(kCyan+2);
// truemultg_NC->SetLineStyle(1);
// truemultn_NC->SetLineColor(kViolet+2);
// truemultn_NC->SetLineStyle(2);
// truemultp_NC->SetLineColor(kPink+2);
// truemultp_NC->SetLineStyle(4);
// truemulte_NC->SetLineColor(kTeal+1);
// truemulte_NC->SetLineStyle(5);
// truemultenu_NC->SetLineColor(kYellow+2);
// truemultenu_NC->SetLineStyle(6);

// TLegend *l6 = new TLegend(0.4,0.65,0.80,0.88);
// l6->AddEntry(truemult_NC,"all ","l");  
// l6->AddEntry(truemultmu_NC,"muons ","l");
// l6->AddEntry(truemultpi_NC,"pions ","l");
// l6->AddEntry(truemultk_NC,"kaons ","l");
// l6->AddEntry(truemultp_NC,"protons ","l");
// l6->AddEntry(truemultpi0_NC,"pion0 ","l");
// l6->AddEntry(truemultg_NC,"photons ","l");
// l6->AddEntry(truemultn_NC,"neutrons ","l");
// l6->AddEntry(truemulte_NC,"electrons ","l");
// l6->AddEntry(truemultenu_NC,"electron neutrino ","l");

truemult_NC->Draw("HIST");
// truemultmu_NC->Draw("SAME HIST");
// truemultpi_NC->Draw("HIST SAME");
// truemultpi0_NC->Draw("HIST SAME");
// truemultk_NC->Draw("HIST SAME");
// truemultp_NC->Draw("SAME HIST");
// truemultg_NC->Draw("SAME HIST");
// truemultn_NC->Draw("SAME HIST");
// truemulte_NC->Draw("SAME HIST");
// truemultenu_NC->Draw("SAME HIST");
// l6->Draw("SAME");
c6.Print("mult_NC.png");

////////// --------------------------------------------------------------- //////////


}
