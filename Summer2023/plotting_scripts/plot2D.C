// This script is used to plot 2D histogram for two variables from the same tree.

#include <TFile.h>
#include <TCanvas.h>
#include <TH2F.h>
#include <TLegend.h>

void plot2D() {


gROOT->LoadMacro("protoDUNEStyle.C");
gROOT->SetStyle("protoDUNEStyle");
gROOT->ForceStyle();
gStyle->SetTitleX(0.35);
gStyle->SetOptFit(111);
gStyle->SetPadRightMargin(0.15);
gStyle->SetPadLeftMargin(0.15);
gStyle->SetOptStat("emr");  //stats box
gStyle->SetStatY(0.9);  // Set y-position (fraction of pad size)
gStyle->SetStatX(0.9);  // Set x-position (fraction of pad size)
gStyle->SetStatW(0.2);  // Set width of stat-box (fraction of pad size)
gStyle->SetStatH(0.2);  // Set height of stat-box (fraction of pad size)
gStyle->SetOptTitle(2);  //no title
gStyle->SetTextFont(42);
gStyle->SetTextSize(0.05);
	
    TFile *file = new TFile("TrackMult2x2wTruth.root", "READ");
    TTree *treemcp = (TTree*)file->Get("mcpTree");
    TTree *treesed = (TTree*)file->Get("sedTree");
	TTree* treeevt=(TTree*)file->Get("evtTree");
	
    double mcpstartx, mcpendx;
    double mcpstarty, mcpendy;
    double mcpstartz, mcpendz;

    double sedstartx, sedendx;
    double sedstarty, sedendy;
    double sedstartz, sedendz;
	
	double nu_Q2, nu_W;

    treemcp->SetBranchAddress("mcpstartx", &mcpstartx);
    treemcp->SetBranchAddress("mcpstarty", &mcpstarty);
    treemcp->SetBranchAddress("mcpstartz", &mcpstartz);
    treemcp->SetBranchAddress("mcpendx", &mcpendx);
    treemcp->SetBranchAddress("mcpendy", &mcpendy);
    treemcp->SetBranchAddress("mcpendz", &mcpendz);
	
	treesed->SetBranchAddress("sedstartx", &sedstartx);
    treesed->SetBranchAddress("sedstarty", &sedstarty);
    treesed->SetBranchAddress("sedstartz", &sedstartz);
    treesed->SetBranchAddress("sedendx", &sedendx);
    treesed->SetBranchAddress("sedendy", &sedendy);
    treesed->SetBranchAddress("sedendz", &sedendz);
	
	treeevt->SetBranchAddress("nu_Q2", &nu_Q2);
    treeevt->SetBranchAddress("nu_W", &nu_W);
	 
 
    TH2F *mcpstartendx = new TH2F("mcpstartendx", "mcpstartx vs mcpendx", 20,-80,80, 30, -1000, 1000);
    for (int i = 0; i < treemcp->GetEntries(); i++) {
        treemcp->GetEntry(i);
        mcpstartendx->Fill(mcpstartx, mcpendx);
	}
    mcpstartendx->SetTitle(" ");
	mcpstartendx->GetXaxis()->SetTitle("MC Particle Start x (cm)");
	mcpstartendx->GetYaxis()->SetTitle("MC Particle End x (cm)");
	mcpstartendx->GetYaxis()->SetTitleOffset(1.5); // Increase distance here
    TCanvas *c1 = new TCanvas("c1", "2D Histogram", 1000, 800);
    mcpstartendx->Draw("colz2");
    // TLegend *l1 = new TLegend(0.7, 0.8, 0.9, 0.9);
    // l1->AddEntry(hist, "mcpstartx vs mcpendx", "l");
    // l1->Draw();
    c1->SaveAs("2Dmcpstartendx.png");


TH2F *mcpstartendy = new TH2F("mcpstartendy", "mcpstarty vs mcpendy", 20,-50,150, 30, -1000, 1000);
    for (int i = 0; i < treemcp->GetEntries(); i++) {
        treemcp->GetEntry(i);
        mcpstartendy->Fill(mcpstarty, mcpendy);
	}
    mcpstartendy->SetTitle(" ");
	mcpstartendy->GetXaxis()->SetTitle("MC Particle Start y (cm)");
	mcpstartendy->GetYaxis()->SetTitle("MC Particle End y (cm)");
mcpstartendy->GetYaxis()->SetTitleOffset(1.5); // Increase distance here
    TCanvas *c2 = new TCanvas("c2", "2D Histogram", 1000, 800);
    mcpstartendy->Draw("colz2");
    // TLegend *l1 = new TLegend(0.7, 0.8, 0.9, 0.9);
    // l1->AddEntry(hist, "mcpstarty vs mcpendy", "l");
    // l1->Draw();
    c2->SaveAs("2Dmcpstartendy.png");
	


TH2F *mcpstartendz = new TH2F("mcpstartendz", "mcpstartz vs mcpendz", 20,-80,80, 30, -500, 6000);
    for (int i = 0; i < treemcp->GetEntries(); i++) {
        treemcp->GetEntry(i);
        mcpstartendz->Fill(mcpstartz, mcpendz);
	}
    mcpstartendz->SetTitle(" ");
	mcpstartendz->GetXaxis()->SetTitle("MC Particle Start z (cm)");
	mcpstartendz->GetYaxis()->SetTitle("MC Particle End z (cm)");
mcpstartendz->GetYaxis()->SetTitleOffset(1.5); // Increase distance here
    TCanvas *c3 = new TCanvas("c3", "2D Histogram", 1000, 800);
    mcpstartendz->Draw("colz2");
    // TLegend *l1 = new TLegend(0.7, 0.8, 0.9, 0.9);
    // l1->AddEntrz(hist, "mcpstartz vs mcpendz", "l");
    // l1->Draw();
    c3->SaveAs("2Dmcpstartendz.png");	
	
	
    TH2F *sedstartendx = new TH2F("sedstartendx", "sedstartx vs sedendx", 20,-70,70, 30, -70, 70);
    for (int i = 0; i < treesed->GetEntries(); i++) {
        treesed->GetEntry(i);
        sedstartendx->Fill(sedstartx, sedendx);
	}
    sedstartendx->SetTitle(" ");
	sedstartendx->GetXaxis()->SetTitle("SED Start x (cm)");
	sedstartendx->GetYaxis()->SetTitle("SED End x (cm)");
sedstartendx->GetYaxis()->SetTitleOffset(1.5); // Increase distance here
    TCanvas *c4 = new TCanvas("c4", "2D Histogram", 1000, 800);
    sedstartendx->Draw("colz2");
    // TLegend *l1 = new TLegend(0.7, 0.8, 0.9, 0.9);
    // l1->AddEntry(hist, "sedstartx vs sedendx", "l");
    // l1->Draw();
    c4->SaveAs("2Dsedstartendx.png");


TH2F *sedstartendy = new TH2F("sedstartendy", "sedstarty vs sedendy", 20,-30, 10, 30, -30, 20);
    for (int i = 0; i < treesed->GetEntries(); i++) {
        treesed->GetEntry(i);
        sedstartendy->Fill(sedstarty, sedendy);
	}
    sedstartendy->SetTitle(" ");
	sedstartendy->GetXaxis()->SetTitle("SED Start y (cm)");
	sedstartendy->GetYaxis()->SetTitle("SED End y (cm)");
sedstartendy->GetYaxis()->SetTitleOffset(1.5); // Increase distance here
    TCanvas *c5 = new TCanvas("c5", "2D Histogram", 1000, 800);
    sedstartendy->Draw("colz2");
    // TLegend *l1 = new TLegend(0.7, 0.8, 0.9, 0.9);
    // l1->AddEntry(hist, "sedstarty vs sedendy", "l");
    // l1->Draw();
    c5->SaveAs("2Dsedstartendy.png");
	


TH2F *sedstartendz = new TH2F("sedstartendz", "sedstartz vs sedendz", 20,0,50, 30, -10, 70);
    for (int i = 0; i < treesed->GetEntries(); i++) {
        treesed->GetEntry(i);
        sedstartendz->Fill(sedstartz, sedendz);
	}
    sedstartendz->SetTitle(" ");
	sedstartendz->GetXaxis()->SetTitle("SED Start z (cm)");
	sedstartendz->GetYaxis()->SetTitle("SED End z (cm)");
sedstartendz->GetYaxis()->SetTitleOffset(1.5); // Increase distance here
    TCanvas *c6 = new TCanvas("c6", "2D Histogram", 1000, 800);
    sedstartendz->Draw("colz2");
    // TLegend *l1 = new TLegend(0.7, 0.8, 0.9, 0.9);
    // l1->AddEntrz(hist, "sedstartz vs sedendz", "l");
    // l1->Draw();
    c6->SaveAs("2Dsedstartendz.png");	
	
	
TH2F *nuQ2W = new TH2F("nuQ2W", "nuQ2 vs nuW", 30,0,6,30, 0, 6);
    for (int i = 0; i < treeevt->GetEntries(); i++) {
        treeevt->GetEntry(i);
        nuQ2W->Fill(nu_W, nu_Q2);
	}
    nuQ2W->SetTitle(" ");
	nuQ2W->GetXaxis()->SetTitle("Invariant Mass of Hadronic System (W) [MeV]");
	nuQ2W->GetYaxis()->SetTitle("Momentum Transfer (Q^{2}) [MeV^{2}]");
	////nuQ2W->GetYaxis()->SetTitleOffset(1.5); // Increase distance here
    TCanvas *c7 = new TCanvas("c7", "2D Histogram", 1000, 800);
    nuQ2W->Draw("colz2");
    //// TLegend *l1 = new TLegend(0.7, 0.8, 0.9, 0.9);
    //// l1->AddEntrz(hist, "sedstartz vs sedendz", "l");
    //// l1->Draw();
    c7->SaveAs("2DnuQ2W.png");		

	
}

	
	
