#define TrackMult2x2wTruth_cxx
#include "TrackMult2x2wTruth.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TMath.h"
#include <iostream>
using namespace std;
void TrackMult2x2wTruth::Loop()
{
//   In a ROOT session, you can do:
//      root> .L TrackMult2x2wTruth.C
//      root> TrackMult2x2wTruth t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
TFile *fout = new TFile(Form("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/withcutonRange/TrackMult2x2wTruth.root"),"RECREATE");
TTree treeevt("evtTree","anaTree");
TTree treemcp("mcpTree","anaTree");
TTree treesed("sedTree","anaTree");

    int nu_ccnc=-999;
    int nu_PDG=-999;
    int nu_mode=-999;
    int nu_inttype=-999;
    float nu_Q2=-999;
    float nu_W=-999;
    float nu_vtxx=-999;
    float nu_vtxy=-999;
    float nu_vtxz=-999;
    float nu_energy=-999;
    int _truemult=-999;
    int _truemultmu=-999;
    int _truemultpi=-999;
    int _truemultk=-999;
    int _truemultp=-999;    
    int _truemultQE=-999;
    int _truemultRES=-999;
    int _truemultDIS=-999;
    int _truemultCOH=-999;
    int _truemultMEC=-999;    

    int _truemultpi0=-999;
	int _truemultg=-999;
	int _truemultn=-999;
	int _truemultmuCC=-999;
	int _truemultmuNC=-999;

	treeevt.Branch("_truemultpi0",&_truemultpi0,"_truemultpi0/I");    
	treeevt.Branch("_truemultg",&_truemultg,"_truemultg/I");    
	treeevt.Branch("_truemultn",&_truemultn,"_truemultn/I");    
	treeevt.Branch("_truemultmuCC",&_truemultmuCC,"_truemultmuCC/I");
	treeevt.Branch("_truemultmuNC",&_truemultmuNC,"_truemultmuNC/I");

	
    int _truemcppdg=-999;
    int _truemcpStatusCode=-999;// if it is a final state stable particle 
    float _truemcpTheta=-999;
    float _truemcpCosTheta=-999;
    float _truemcpSinTheta=-999;
    float _truemcpPhi=-999;
    float _truemcpCosPhi=-999;
    float _truemcpSinPhi=-999;	
    float _truemcpE=-999;
    float _truemcpMass=-999;
    float _truemcpKE=-999;
    float _truemcpEndE=-999;
    float _truemcpPx=-999;
    float _truemcpPy=-999;
    float _truemcpPz=-999;
    float _truemcpP=-999;
    float _truemcpStartx=-999;
    float _truemcpStarty=-999;
    float _truemcpStartz=-999;
    float _truemcpEndx=-999;
    float _truemcpEndy=-999;
    float _truemcpEndz=-999;
    float _truesedStartx=-999;
    float _truesedStarty=-999;
    float _truesedStartz=-999;
    float _truesedEndx=-999;
    float _truesedEndy=-999;
    float _truesedEndz=-999;
    float _truesedE=-999;
    int   _truesedID=-999;
    int   _truesedPdg=-999;
     
	
treeevt.Branch("nu_ccnc",&nu_ccnc,"nu_ccnc/I");
treeevt.Branch("nu_PDG",&nu_PDG,"nu_PDG/I");
treeevt.Branch("nu_mode",&nu_mode,"nu_mode/I");
treeevt.Branch("nu_inttype",&nu_inttype,"nu_inttype/I");
treeevt.Branch("nu_Q2",&nu_Q2,"nu_Q2/F");    
treeevt.Branch("nu_W",&nu_W,"nu_W/F");
treeevt.Branch("nu_vtxx",&nu_vtxx,"nu_vtxx/F");
treeevt.Branch("nu_vtxy",&nu_vtxy,"nu_vtxy/F");
treeevt.Branch("nu_vtxz",&nu_vtxz,"nu_vtxz/F");
treeevt.Branch("nu_energy",&nu_energy,"nu_energy/F");
treeevt.Branch("_truemult",&_truemult,"_truemult/I");    
treeevt.Branch("_truemultmu",&_truemultmu,"_truemultmu/I");
treeevt.Branch("_truemultpi",&_truemultpi,"_truemultpi/I");
treeevt.Branch("_truemultk",&_truemultk,"_truemultk/I");
treeevt.Branch("_truemultp",&_truemultp,"_truemultp/I");
treeevt.Branch("_truemultQE",&_truemultQE,"_truemultQE/I");    
treeevt.Branch("_truemultRES",&_truemultRES,"_truemultRES/I");
treeevt.Branch("_truemultDIS",&_truemultDIS,"_truemultDIS/I");
treeevt.Branch("_truemultCOH",&_truemultCOH,"_truemultCOH/I");
treeevt.Branch("_truemultMEC",&_truemultMEC,"_truemultMEC/I");

treemcp.Branch("_truemcppdg",&_truemcppdg,"_truemcppdg/I");
treemcp.Branch("_truemcpStatusCode",&_truemcpStatusCode,"_truemcpStatusCode/I");
treemcp.Branch("_truemcpTheta",&_truemcpTheta,"_truemcpTheta/F");
treemcp.Branch("_truemcpCosTheta",&_truemcpCosTheta,"_truemcpCosTheta/F");  
treemcp.Branch("_truemcpSinTheta",&_truemcpSinTheta,"_truemcpSinTheta/F");
treemcp.Branch("_truemcpPhi",&_truemcpPhi,"_truemcpPhi/F");
treemcp.Branch("_truemcpCosPhi",&_truemcpCosPhi,"_truemcpCosPhi/F");    
treemcp.Branch("_truemcpSinPhi",&_truemcpSinPhi,"_truemcpSinPhi/F");    
treemcp.Branch("_truemcpE",&_truemcpE,"_truemcpE/F");
treemcp.Branch("_truemcpMass",&_truemcpMass,"_truemcpMass/F");
treemcp.Branch("_truemcpKE",&_truemcpKE,"_truemcpKE/F");
treemcp.Branch("_truemcpEndE",&_truemcpEndE,"_truemcpEndE/F");
treemcp.Branch("_truemcpPx",&_truemcpPx,"_truemcpPx/F");
treemcp.Branch("_truemcpPy",&_truemcpPy,"_truemcpPy/F");
treemcp.Branch("_truemcpPz",&_truemcpPz,"_truemcpPz/F");
treemcp.Branch("_truemcpP",&_truemcpP,"_truemcpP/F");
treemcp.Branch("_truemcpStartx",&_truemcpStartx,"_truemcpStartx/F");
treemcp.Branch("_truemcpStarty",&_truemcpStarty,"_truemcpStarty/F");
treemcp.Branch("_truemcpStartz",&_truemcpStartz,"_truemcpStartz/F");
treemcp.Branch("_truemcpEndx",&_truemcpEndx,"_truemcpEndx/F");
treemcp.Branch("_truemcpEndy",&_truemcpEndy,"_truemcpEndy/F");
treemcp.Branch("_truemcpEndz",&_truemcpEndz,"_truemcpEndz/F");

treesed.Branch("_truesedStartx",&_truesedStartx,"_truesedStartx/F");
treesed.Branch("_truesedStarty",&_truesedStarty,"_truesedStarty/F");
treesed.Branch("_truesedStartz",&_truesedStartz,"_truesedStartz/F");
treesed.Branch("_truesedEndx",&_truesedEndx,"_truesedEndx/F");
treesed.Branch("_truesedEndy",&_truesedEndy,"_truesedEndy/F");
treesed.Branch("_truesedEndz",&_truesedEndz,"_truesedEndz/F");
treesed.Branch("_truesedE",&_truesedE,"_truesedE/F");
treesed.Branch("_truesedID",&_truesedID,"_truesedID/I");
treesed.Branch("_truesedPdg",&_truesedPdg,"_truesedPdg/I");

    int Xnegbound = -67;
    int Xposbound = +67;
    int Ynegbound = -25;
    int Yposbound = 109;
    int Znegbound = -67;
    int Zposbound = +67;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
		if(jentry%1000==0) {
			if(ientry>4000) break; //only read first 10 entries 
			std::cout<<"Event: "<<jentry<<std::endl;
		}
      if(!nuvtxx->size()) continue;
      
      //loop on all the nu veretices
//      for(int k=0; k<nuPDG->size(); k++)
//      {
      nu_ccnc=ccnc->at(0);
      nu_PDG=nuPDG->at(0);
      nu_mode=mode->at(0);
      nu_inttype=inttype->at(0);
      nu_Q2=Q2->at(0);
      nu_W=W->at(0);
      nu_vtxx=nuvtxx->at(0); 
      nu_vtxy=nuvtxy->at(0); 
      nu_vtxz=nuvtxz->at(0);
      nu_energy=enu->at(0);
//      std::cout<<"energy nu: "<<enu->at(0)<<"\n";


     int truemult=0;
     int truemultmu=0;
     int truemultpi=0;
     int truemultk=0;
     int truemultp=0;
	 
	 int truemultpi0=0;
	 int truemultg=0;
	 int truemultn=0;
	 int truemultmuCC=0;
	 int truemultmuNC=0;

     int truemultQE=0;
     int truemultRES=0;
     int truemultDIS=0;
     int truemultCOH=0;
     int truemultMEC=0;

     for(long unsigned int i=0; i<mcp_id->size(); i++)
     {
       bool isNotContained=false;
       if(mcp_mother->at(i)!=0) continue; //mother track id is 0
       if(mcp_statuscode->at(i)==1)
       {
//            float range = 4.5/abs(mcp_costheta->at(i));
	     float range = 4.5;
	     if((abs(mcp_pdg->at(i))==13 && mcp_ke->at(i)>=(11.518*(pow(range,0.555))+0.252*(pow(range,1.289)))/1000) 
	     || (abs(mcp_pdg->at(i))==211 && mcp_ke->at(i)>=(13.069*(pow(range,0.555))+0.233*(pow(range,1.289)))/1000) 
	     || (abs(mcp_pdg->at(i))==321 && mcp_ke->at(i)>=(22.966*(pow(range,0.555))+0.161*(pow(range,1.289)))/1000)
	     || (mcp_pdg->at(i)==2212 && mcp_ke->at(i)>=(30.573*(pow(range,0.555))+0.133*(pow(range,1.289)))/1000))
	      
	     {
	        if(mcp_startx->at(i)>Xnegbound && mcp_startx->at(i)<Xposbound && mcp_starty->at(i)>Ynegbound && mcp_starty->at(i)<Yposbound && mcp_startz->at(i)>Znegbound && mcp_startz->at(i)<Zposbound) //particle is in FV
		{
//	        std::cout<<"found the accepted particle: pdg "<<mcp_pdg->at(i)<<" KE "<<mcp_ke->at(i)<<"\n";
		truemult++;
//		std::cout<<"inside mult "<<trueInAccpmult<<"\n";

		if(abs(mcp_pdg->at(i))==13)truemultmu++; 
		if(abs(mcp_pdg->at(i))==211) truemultpi++;
		if(abs(mcp_pdg->at(i))==321) truemultk++;
		if(mcp_pdg->at(i)==2212) truemultp++;

		if(abs(mcp_pdg->at(i))==111)truemultpi0++;
		if(mcp_pdg->at(i) == 22) truemultg++;		
		if(mcp_pdg->at(i) == 2112) truemultn++;		

		if (ccnc->size() > i) { // check if i is within the valid range of indices for ccnc
			if(abs(ccnc->at(i)) == 0) {
				if(abs(mcp_pdg->at(i)) == 13) {
					truemultmuCC++;
				}
			}
		}
		
		if (ccnc->size() > i) { // check if i is within the valid range of indices for ccnc
			if(abs(ccnc->at(i)) == 1) {
				if(abs(mcp_pdg->at(i)) == 13) {
					truemultmuNC++;
				}
			}
		}
		
		
		 //if (!sed_endy->empty())   { sedendy = sed_endy->at(0); 	   }
	  
       	    if(mode->at(0)==0)truemultQE++;
	        if(mode->at(0)==1)truemultRES++;
	        if(mode->at(0)==2)truemultDIS++;
	        if(mode->at(0)==3)truemultCOH++;
	        if(mode->at(0)==10)truemultMEC++;
		
	        _truemcppdg = mcp_pdg->at(i);
	        _truemcpStatusCode = mcp_statuscode->at(i);
	        _truemcpTheta = mcp_theta->at(i);
	        _truemcpCosTheta = mcp_costheta->at(i);	
	        _truemcpSinTheta = mcp_sintheta->at(i);	
	        _truemcpE = mcp_energy->at(i);
	        _truemcpMass = mcp_mass->at(i);
	        _truemcpKE = mcp_ke->at(i);
	        _truemcpEndE = mcp_endenergy->at(i);
            _truemcpPx = mcp_px->at(i);
	        _truemcpPy = mcp_py->at(i);
	        _truemcpPz = mcp_pz->at(i);
	        _truemcpP = mcp_p->at(i);
	        _truemcpStartx = mcp_startx->at(i);
	        _truemcpStarty = mcp_starty->at(i);
	        _truemcpStartz = mcp_startz->at(i);
	        _truemcpEndx = mcp_endx->at(i);
	        _truemcpEndy = mcp_endy->at(i);
	        _truemcpEndz = mcp_endz->at(i);
	        _truemcpPhi = mcp_phi->at(i);
	        _truemcpCosPhi = mcp_cosphi->at(i);
	        _truemcpSinPhi = mcp_sinphi->at(i);
                
		treemcp.Fill();
		}
	      }
	    }//if(mcp_statuscode->at(i)==1)
	  } //for(long unsigned int i=0; i<mcp_id->size(); i++) 
	  
	  for(long unsigned int i=0; i<sed_id->size(); i++)
          {
	    _truesedStartx = sed_startx->at(i);
	    _truesedStarty = sed_starty->at(i);
	    _truesedStartz = sed_startz->at(i);
	    _truesedEndx = sed_endx->at(i);
	    _truesedEndy = sed_endy->at(i);
	    _truesedEndz = sed_endz->at(i);
	    _truesedE = sed_energy->at(i);
	    _truesedID = sed_id->at(i);
	    _truesedPdg = sed_pdg->at(i);
	    
	    treesed.Fill();
	  }

//	  std::cout<<"outside mult "<<trueInAccpmult<<"\n";
	  _truemult=truemult;
	  _truemultmu=truemultmu;
	  _truemultpi=truemultpi;
	  _truemultk=truemultk;
	  _truemultp=truemultp;
	  
	  _truemultpi0=truemultpi0;	  
	  _truemultg=truemultg;	  
	  _truemultn=truemultn;	  
 	  _truemultmuCC=truemultmuCC; 
	  _truemultmuNC=truemultmuNC; 
	  
	  _truemultQE = truemultQE;
	  _truemultRES = truemultRES;
	  _truemultDIS = truemultDIS;
	  _truemultCOH = truemultCOH;
	  _truemultMEC = truemultMEC;

    treeevt.Fill();

}//for (Long64_t jentry=0; jentry<nentries;jentry++) {
fout->Write();
}//void TrackMult2x2wTruth::Loop()
