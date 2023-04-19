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
	if (fChain == 0) return;
	Long64_t nentries = fChain->GetEntriesFast();

	TFile *fout = new TFile(Form("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/nocutonRange/TrackMult2x2wTruth.root"),"RECREATE");
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
	int _truemulte=-999;
	int _truemultenu=-999;	
	int _truemultmuCC=-999;
	int _truemultmuNC=-999;	
	
	int _numTracks_0cm=-999;
	int _numTracks_4mm=-999; 
	int _numTracks_1cm=-999; 
	int _numTracks_5cm=-999;
	int _numTracks_10cm=-999;
	int _numNotContained=-999;
	double _longestTrack=-999;
	double _longestTrack_startx=-999;
	double _longestTrack_starty=-999;
	double _longestTrack_startz=-999;
	double _longestTrack_endx=-999;
	double _longestTrack_endy=-999;
	double _longestTrack_endz=-999;
		
	int _truemcppdg=-999;
    int _truemcpStatusCode=-999;
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
	
	treeevt.Branch("_truemultpi0",&_truemultpi0,"_truemultpi0/I");    
	treeevt.Branch("_truemultg",&_truemultg,"_truemultg/I");    
	treeevt.Branch("_truemultn",&_truemultn,"_truemultn/I");    
	treeevt.Branch("_truemulte",&_truemulte,"_truemulte/I");    
	treeevt.Branch("_truemultenu",&_truemultenu,"_truemultenu/I");    
	treeevt.Branch("_truemultmuCC",&_truemultmuCC,"_truemultmuCC/I");
	treeevt.Branch("_truemultmuNC",&_truemultmuNC,"_truemultmuNC/I");
	
	treeevt.Branch("_numTracks_0cm",&_numTracks_0cm,"_numTracks_0cm/I");
	treeevt.Branch("_numTracks_4mm",&_numTracks_4mm,"_numTracks_4mm/I");
	treeevt.Branch("_numTracks_1cm",&_numTracks_1cm,"_numTracks_1cm/I");
	treeevt.Branch("_numTracks_5cm",&_numTracks_5cm,"_numTracks_5cm/I");
	treeevt.Branch("_numTracks_10cm",&_numTracks_10cm,"_numTracks_10cm/I");
	treeevt.Branch("_numNotContained",&_numNotContained,"_numNotContained/I");
	treeevt.Branch("_longestTrack",&_longestTrack,"_longestTrack/D");
	treeevt.Branch("_longestTrack_startx",&_longestTrack_startx,"_longestTrack_startx/D");
	treeevt.Branch("_longestTrack_starty",&_longestTrack_starty,"_longestTrack_starty/D");
	treeevt.Branch("_longestTrack_startz",&_longestTrack_startz,"_longestTrack_startz/D");
	treeevt.Branch("_longestTrack_endx",&_longestTrack_endx,"_longestTrack_endx/D");
	treeevt.Branch("_longestTrack_endy",&_longestTrack_endy,"_longestTrack_endy/D");
	treeevt.Branch("_longestTrack_endz",&_longestTrack_endz,"_longestTrack_endz/D");

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

	int _numTracks_0cmMU=-999;
	int _numTracks_4mmMU=-999; 
	int _numTracks_1cmMU=-999; 
	int _numTracks_5cmMU=-999;
	int _numTracks_10cmMU=-999;
	int _numNotContainedMU=-999;
	treeevt.Branch("_numTracks_0cmMU",&_numTracks_0cmMU,"_numTracks_0cmMU/I");
	treeevt.Branch("_numTracks_4mmMU",&_numTracks_4mmMU,"_numTracks_4mmMU/I");
	treeevt.Branch("_numTracks_1cmMU",&_numTracks_1cmMU,"_numTracks_1cmMU/I");
	treeevt.Branch("_numTracks_5cmMU",&_numTracks_5cmMU,"_numTracks_5cmMU/I");
	treeevt.Branch("_numTracks_10cmMU",&_numTracks_10cmMU,"_numTracks_10cmMU/I");
	treeevt.Branch("_numNotContainedMU",&_numNotContainedMU,"_numNotContainedMU/I");	
	
	int _numTracks_0cmPI=-999;
	int _numTracks_4mmPI=-999; 
	int _numTracks_1cmPI=-999; 
	int _numTracks_5cmPI=-999;
	int _numTracks_10cmPI=-999;
	int _numNotContainedPI=-999;
	treeevt.Branch("_numTracks_0cmPI",&_numTracks_0cmPI,"_numTracks_0cmPI/I");
	treeevt.Branch("_numTracks_4mmPI",&_numTracks_4mmPI,"_numTracks_4mmPI/I");
	treeevt.Branch("_numTracks_1cmPI",&_numTracks_1cmPI,"_numTracks_1cmPI/I");
	treeevt.Branch("_numTracks_5cmPI",&_numTracks_5cmPI,"_numTracks_5cmPI/I");
	treeevt.Branch("_numTracks_10cmPI",&_numTracks_10cmPI,"_numTracks_10cmPI/I");
	treeevt.Branch("_numNotContainedPI",&_numNotContainedPI,"_numNotContainedPI/I");	

	int _numTracks_0cmK=-999;
	int _numTracks_4mmK=-999; 
	int _numTracks_1cmK=-999; 
	int _numTracks_5cmK=-999;
	int _numTracks_10cmK=-999;
	int _numNotContainedK=-999;
	treeevt.Branch("_numTracks_0cmK",&_numTracks_0cmK,"_numTracks_0cmK/I");
	treeevt.Branch("_numTracks_4mmK",&_numTracks_4mmK,"_numTracks_4mmK/I");
	treeevt.Branch("_numTracks_1cmK",&_numTracks_1cmK,"_numTracks_1cmK/I");
	treeevt.Branch("_numTracks_5cmK",&_numTracks_5cmK,"_numTracks_5cmK/I");
	treeevt.Branch("_numTracks_10cmK",&_numTracks_10cmK,"_numTracks_10cmK/I");
	treeevt.Branch("_numNotContainedK",&_numNotContainedK,"_numNotContainedK/I");		

	int _numTracks_0cmP=-999;
	int _numTracks_4mmP=-999; 
	int _numTracks_1cmP=-999; 
	int _numTracks_5cmP=-999;
	int _numTracks_10cmP=-999;
	int _numNotContainedP=-999;
	treeevt.Branch("_numTracks_0cmP",&_numTracks_0cmP,"_numTracks_0cmP/I");
	treeevt.Branch("_numTracks_4mmP",&_numTracks_4mmP,"_numTracks_4mmP/I");
	treeevt.Branch("_numTracks_1cmP",&_numTracks_1cmP,"_numTracks_1cmP/I");
	treeevt.Branch("_numTracks_5cmP",&_numTracks_5cmP,"_numTracks_5cmP/I");
	treeevt.Branch("_numTracks_10cmP",&_numTracks_10cmP,"_numTracks_10cmP/I");
	treeevt.Branch("_numNotContainedP",&_numNotContainedP,"_numNotContainedP/I");	
	
	int _numTracks_0cmPI0=-999;
	int _numTracks_4mmPI0=-999; 
	int _numTracks_1cmPI0=-999; 
	int _numTracks_5cmPI0=-999;
	int _numTracks_10cmPI0=-999;
	int _numNotContainedPI0=-999;
	treeevt.Branch("_numTracks_0cmPI0",&_numTracks_0cmPI0,"_numTracks_0cmPI0/I");
	treeevt.Branch("_numTracks_4mmPI0",&_numTracks_4mmPI0,"_numTracks_4mmPI0/I");
	treeevt.Branch("_numTracks_1cmPI0",&_numTracks_1cmPI0,"_numTracks_1cmPI0/I");
	treeevt.Branch("_numTracks_5cmPI0",&_numTracks_5cmPI0,"_numTracks_5cmPI0/I");
	treeevt.Branch("_numTracks_10cmPI0",&_numTracks_10cmPI0,"_numTracks_10cmPI0/I");
	treeevt.Branch("_numNotContainedPI0",&_numNotContainedPI0,"_numNotContainedPI0/I");

	int _numTracks_0cmG=-999;
	int _numTracks_4mmG=-999; 
	int _numTracks_1cmG=-999; 
	int _numTracks_5cmG=-999;
	int _numTracks_10cmG=-999;
	int _numNotContainedG=-999;
	treeevt.Branch("_numTracks_0cmG",&_numTracks_0cmG,"_numTracks_0cmG/I");
	treeevt.Branch("_numTracks_4mmG",&_numTracks_4mmG,"_numTracks_4mmG/I");
	treeevt.Branch("_numTracks_1cmG",&_numTracks_1cmG,"_numTracks_1cmG/I");
	treeevt.Branch("_numTracks_5cmG",&_numTracks_5cmG,"_numTracks_5cmG/I");
	treeevt.Branch("_numTracks_10cmG",&_numTracks_10cmG,"_numTracks_10cmG/I");
	treeevt.Branch("_numNotContainedG",&_numNotContainedG,"_numNotContainedG/I");

	int _numTracks_0cmN=-999;
	int _numTracks_4mmN=-999; 
	int _numTracks_1cmN=-999; 
	int _numTracks_5cmN=-999;
	int _numTracks_10cmN=-999;
	int _numNotContainedN=-999;
	treeevt.Branch("_numTracks_0cmN",&_numTracks_0cmN,"_numTracks_0cmN/I");
	treeevt.Branch("_numTracks_4mmN",&_numTracks_4mmN,"_numTracks_4mmN/I");
	treeevt.Branch("_numTracks_1cmN",&_numTracks_1cmN,"_numTracks_1cmN/I");
	treeevt.Branch("_numTracks_5cmN",&_numTracks_5cmN,"_numTracks_5cmN/I");
	treeevt.Branch("_numTracks_10cmN",&_numTracks_10cmN,"_numTracks_10cmN/I");
	treeevt.Branch("_numNotContainedN",&_numNotContainedN,"_numNotContainedN/I");

    int _truemultmu_0cm=-999;
	int _truemultmu_4mm=-999;
	int _truemultmu_1cm=-999;
	int _truemultmu_5cm=-999;
	int _truemultmu_10cm=-999;
	treeevt.Branch("_truemultmu_0cm",&_truemultmu_0cm,"_truemultmu_0cm/I");
	treeevt.Branch("_truemultmu_4mm",&_truemultmu_4mm,"_truemultmu_4mm/I");
	treeevt.Branch("_truemultmu_1cm",&_truemultmu_1cm,"_truemultmu_1cm/I");
	treeevt.Branch("_truemultmu_5cm",&_truemultmu_5cm,"_truemultmu_5cm/I");
	treeevt.Branch("_truemultmu_10cm",&_truemultmu_10cm,"_truemultmu_10cm/I");	

    int _truemultpi_0cm=-999;
	int _truemultpi_4mm=-999;
	int _truemultpi_1cm=-999;
	int _truemultpi_5cm=-999;
	int _truemultpi_10cm=-999;
	treeevt.Branch("_truemultpi_0cm",&_truemultpi_0cm,"_truemultpi_0cm/I");
	treeevt.Branch("_truemultpi_4mm",&_truemultpi_4mm,"_truemultpi_4mm/I");
	treeevt.Branch("_truemultpi_1cm",&_truemultpi_1cm,"_truemultpi_1cm/I");
	treeevt.Branch("_truemultpi_5cm",&_truemultpi_5cm,"_truemultpi_5cm/I");
	treeevt.Branch("_truemultpi_10cm",&_truemultpi_10cm,"_truemultpi_10cm/I");	
	
    int _truemultk_0cm=-999;
	int _truemultk_4mm=-999;
	int _truemultk_1cm=-999;
	int _truemultk_5cm=-999;
	int _truemultk_10cm=-999;
	treeevt.Branch("_truemultk_0cm",&_truemultk_0cm,"_truemultk_0cm/I");
	treeevt.Branch("_truemultk_4mm",&_truemultk_4mm,"_truemultk_4mm/I");
	treeevt.Branch("_truemultk_1cm",&_truemultk_1cm,"_truemultk_1cm/I");
	treeevt.Branch("_truemultk_5cm",&_truemultk_5cm,"_truemultk_5cm/I");
	treeevt.Branch("_truemultk_10cm",&_truemultk_10cm,"_truemultk_10cm/I");	
	
    int _truemultp_0cm=-999;
	int _truemultp_4mm=-999;
	int _truemultp_1cm=-999;
	int _truemultp_5cm=-999;
	int _truemultp_10cm=-999;
	treeevt.Branch("_truemultp_0cm",&_truemultp_0cm,"_truemultp_0cm/I");
	treeevt.Branch("_truemultp_4mm",&_truemultp_4mm,"_truemultp_4mm/I");
	treeevt.Branch("_truemultp_1cm",&_truemultp_1cm,"_truemultp_1cm/I");
	treeevt.Branch("_truemultp_5cm",&_truemultp_5cm,"_truemultp_5cm/I");
	treeevt.Branch("_truemultp_10cm",&_truemultp_10cm,"_truemultp_10cm/I");	
	
    int _truemultpi0_0cm=-999;
	int _truemultpi0_4mm=-999;
	int _truemultpi0_1cm=-999;
	int _truemultpi0_5cm=-999;
	int _truemultpi0_10cm=-999;
	treeevt.Branch("_truemultpi0_0cm",&_truemultpi0_0cm,"_truemultpi0_0cm/I");
	treeevt.Branch("_truemultpi0_4mm",&_truemultpi0_4mm,"_truemultpi0_4mm/I");
	treeevt.Branch("_truemultpi0_1cm",&_truemultpi0_1cm,"_truemultpi0_1cm/I");
	treeevt.Branch("_truemultpi0_5cm",&_truemultpi0_5cm,"_truemultpi0_5cm/I");
	treeevt.Branch("_truemultpi0_10cm",&_truemultpi0_10cm,"_truemultpi0_10cm/I");	
	
    int _truemultg_0cm=-999;
	int _truemultg_4mm=-999;
	int _truemultg_1cm=-999;
	int _truemultg_5cm=-999;
	int _truemultg_10cm=-999;
	treeevt.Branch("_truemultg_0cm",&_truemultg_0cm,"_truemultg_0cm/I");
	treeevt.Branch("_truemultg_4mm",&_truemultg_4mm,"_truemultg_4mm/I");
	treeevt.Branch("_truemultg_1cm",&_truemultg_1cm,"_truemultg_1cm/I");
	treeevt.Branch("_truemultg_5cm",&_truemultg_5cm,"_truemultg_5cm/I");
	treeevt.Branch("_truemultg_10cm",&_truemultg_10cm,"_truemultg_10cm/I");	
	
    int _truemultn_0cm=-999;
	int _truemultn_4mm=-999;
	int _truemultn_1cm=-999;
	int _truemultn_5cm=-999;
	int _truemultn_10cm=-999;
	treeevt.Branch("_truemultn_0cm",&_truemultn_0cm,"_truemultn_0cm/I");
	treeevt.Branch("_truemultn_4mm",&_truemultn_4mm,"_truemultn_4mm/I");
	treeevt.Branch("_truemultn_1cm",&_truemultn_1cm,"_truemultn_1cm/I");
	treeevt.Branch("_truemultn_5cm",&_truemultn_5cm,"_truemultn_5cm/I");
	treeevt.Branch("_truemultn_10cm",&_truemultn_10cm,"_truemultn_10cm/I");	
	
	int Xnegbound = -67;
    int Xposbound = +67;
    int Ynegbound = -25;
    int Yposbound = 109;
    int Znegbound = -67;
    int Zposbound = +67;

	Long64_t nbytes = 0, 
	nb = 0;
	
	for (Long64_t jentry=0; jentry<nentries;jentry++)
	{
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   
		nbytes += nb;
		
		if(jentry%1000==0) 
		{
			if(ientry>4000) break; 
			std::cout<<"Event: "<<jentry<<std::endl;
		}	// if(jentry%1000==0)
		
		if(!nuvtxx->size()) continue;
		
		nu_ccnc		= ccnc->at(0);
		nu_PDG 		= nuPDG->at(0);
		nu_mode 	= mode->at(0);
		nu_inttype 	= inttype->at(0);
		nu_Q2 		= Q2->at(0);
		nu_W 		= W->at(0);
		nu_vtxx		= nuvtxx->at(0); 
		nu_vtxy		= nuvtxy->at(0); 
		nu_vtxz		= nuvtxz->at(0);
		nu_energy	= enu->at(0);
		
		int truemult=0;
		int truemultmu=0;
		int truemultpi=0;
		int truemultk=0;
		int truemultp=0;
		 
		int truemultpi0=0;
		int truemultg=0;
		int truemultn=0;
		int truemulte=0;
		int truemultenu=0;
		int truemultmuCC=0;
		int truemultmuNC=0;

		int truemultQE=0;
		int truemultRES=0;
		int truemultDIS=0;
		int truemultCOH=0;
		int truemultMEC=0;
		
		int numTracks_0cm=0;
		int numTracks_4mm=0; 
		int numTracks_1cm=0; 
		int numTracks_5cm=0;
		int numTracks_10cm=0; 
		int numNotContained=0;
		double longestTrack=0;
		double longestTrack_startx=0;
		double longestTrack_starty=0;
		double longestTrack_startz=0;
		double longestTrack_endx=0;
		double longestTrack_endy=0;
		double longestTrack_endz=0;

		int numTracks_0cmMU=0;
		int numTracks_4mmMU=0; 
		int numTracks_1cmMU=0; 
		int numTracks_5cmMU=0;
		int numTracks_10cmMU=0; 
		int numNotContainedMU=0;

		int numTracks_0cmPI=0;
		int numTracks_4mmPI=0; 
		int numTracks_1cmPI=0; 
		int numTracks_5cmPI=0;
		int numTracks_10cmPI=0; 
		int numNotContainedPI=0;

		int numTracks_0cmK=0;
		int numTracks_4mmK=0; 
		int numTracks_1cmK=0; 
		int numTracks_5cmK=0;
		int numTracks_10cmK=0; 
		int numNotContainedK=0;

		int numTracks_0cmP=0;
		int numTracks_4mmP=0; 
		int numTracks_1cmP=0; 
		int numTracks_5cmP=0;
		int numTracks_10cmP=0; 
		int numNotContainedP=0;

		int numTracks_0cmPI0=0;
		int numTracks_4mmPI0=0; 
		int numTracks_1cmPI0=0; 
		int numTracks_5cmPI0=0;
		int numTracks_10cmPI0=0; 
		int numNotContainedPI0=0;

		int numTracks_0cmG=0;
		int numTracks_4mmG=0; 
		int numTracks_1cmG=0; 
		int numTracks_5cmG=0;
		int numTracks_10cmG=0; 
		int numNotContainedG=0;

		int numTracks_0cmN=0;
		int numTracks_4mmN=0; 
		int numTracks_1cmN=0; 
		int numTracks_5cmN=0;
		int numTracks_10cmN=0; 
		int numNotContainedN=0;
		
		int truemultmu_0cm=0;
		int truemultmu_4mm=0;
		int truemultmu_1cm=0;
		int truemultmu_5cm=0;
		int truemultmu_10cm=0;

		int truemultpi_0cm=0;
		int truemultpi_4mm=0;
		int truemultpi_1cm=0;
		int truemultpi_5cm=0;
		int truemultpi_10cm=0;

		int truemultk_0cm=0;
		int truemultk_4mm=0;
		int truemultk_1cm=0;
		int truemultk_5cm=0;
		int truemultk_10cm=0;

		int truemultp_0cm=0;
		int truemultp_4mm=0;
		int truemultp_1cm=0;
		int truemultp_5cm=0;
		int truemultp_10cm=0;

		int truemultpi0_0cm=0;
		int truemultpi0_4mm=0;
		int truemultpi0_1cm=0;
		int truemultpi0_5cm=0;
		int truemultpi0_10cm=0;

		int truemultg_0cm=0;
		int truemultg_4mm=0;
		int truemultg_1cm=0;
		int truemultg_5cm=0;
		int truemultg_10cm=0;

		int truemultn_0cm=0;
		int truemultn_4mm=0;
		int truemultn_1cm=0;
		int truemultn_5cm=0;
		int truemultn_10cm=0;


		
		for(long unsigned int i=0; i<mcp_id->size(); i++)
		{
			bool isNotContained=false;
			if(mcp_mother->at(i)!=0) continue;
			
			if(mcp_statuscode->at(i)==1)
			{
				// float range = 4.5;
				// if((abs(mcp_pdg->at(i))==13 && mcp_ke->at(i)>=(11.518*(pow(range,0.555))+0.252*(pow(range,1.289)))/1000) 
				// || (abs(mcp_pdg->at(i))==211 && mcp_ke->at(i)>=(13.069*(pow(range,0.555))+0.233*(pow(range,1.289)))/1000) 
				// || (abs(mcp_pdg->at(i))==321 && mcp_ke->at(i)>=(22.966*(pow(range,0.555))+0.161*(pow(range,1.289)))/1000)
				// || (mcp_pdg->at(i)==2212 && mcp_ke->at(i)>=(30.573*(pow(range,0.555))+0.133*(pow(range,1.289)))/1000))
				// {
				
					if(mcp_startx->at(i)>Xnegbound && mcp_startx->at(i)<Xposbound && mcp_starty->at(i)>Ynegbound && mcp_starty->at(i)<Yposbound && mcp_startz->at(i)>Znegbound && mcp_startz->at(i)<Zposbound) //particle is in FV
					{
						double len_inLAr=0; 
						double dx=mcp_endx->at(i)-mcp_startx->at(i); 
						double dz=mcp_endz->at(i)-mcp_startz->at(i); 
						double dy=mcp_endy->at(i)-mcp_starty->at(i); 
						len_inLAr=TMath::Sqrt(dx*dx+dy*dy+dz*dz);
						
						numTracks_0cm++;
						
						
						if(abs(mcp_pdg->at(i))==13)
						{
							double dx=mcp_endx->at(i)-mcp_startx->at(i); 
							double dz=mcp_endz->at(i)-mcp_startz->at(i); 
							double dy=mcp_endy->at(i)-mcp_starty->at(i); 
							len_inLAr=TMath::Sqrt(dx*dx+dy*dy+dz*dz);							
							numTracks_0cmMU++;
							truemultmu_0cm++;
							truemultpi_0cm++;
							truemultk_0cm++;
							truemultp_0cm++;
							truemultpi0_0cm++;
							truemultg_0cm++;
							truemultn_0cm++;							
						}

						if(abs(mcp_pdg->at(i))==211)
						{
							double dx=mcp_endx->at(i)-mcp_startx->at(i); 
							double dz=mcp_endz->at(i)-mcp_startz->at(i); 
							double dy=mcp_endy->at(i)-mcp_starty->at(i); 
							len_inLAr=TMath::Sqrt(dx*dx+dy*dy+dz*dz);							
							numTracks_0cmPI++;
						}
						
						if(abs(mcp_pdg->at(i))==2212)
						{
							double dx=mcp_endx->at(i)-mcp_startx->at(i); 
							double dz=mcp_endz->at(i)-mcp_startz->at(i); 
							double dy=mcp_endy->at(i)-mcp_starty->at(i); 
							len_inLAr=TMath::Sqrt(dx*dx+dy*dy+dz*dz);							
							numTracks_0cmP++;
						}						
						
						if(abs(mcp_pdg->at(i))==111)
						{
							double dx=mcp_endx->at(i)-mcp_startx->at(i); 
							double dz=mcp_endz->at(i)-mcp_startz->at(i); 
							double dy=mcp_endy->at(i)-mcp_starty->at(i); 
							len_inLAr=TMath::Sqrt(dx*dx+dy*dy+dz*dz);							
							numTracks_0cmPI0++;
						}						
						
						if(abs(mcp_pdg->at(i))==22)
						{
							double dx=mcp_endx->at(i)-mcp_startx->at(i); 
							double dz=mcp_endz->at(i)-mcp_startz->at(i); 
							double dy=mcp_endy->at(i)-mcp_starty->at(i); 
							len_inLAr=TMath::Sqrt(dx*dx+dy*dy+dz*dz);							
							numTracks_0cmG++;
						}

						if(abs(mcp_pdg->at(i))==2112)
						{
							double dx=mcp_endx->at(i)-mcp_startx->at(i); 
							double dz=mcp_endz->at(i)-mcp_startz->at(i); 
							double dy=mcp_endy->at(i)-mcp_starty->at(i); 
							len_inLAr=TMath::Sqrt(dx*dx+dy*dy+dz*dz);							
							numTracks_0cmN++;
						}
						
						
						
						if (abs(mcp_endz->at(i))>67)
						{
							dz=67-mcp_startz->at(i);
							if(mcp_endz->at(i)<0) dz=-67-mcp_startz->at(i);
							isNotContained=true;
						}	// if (abs(mcp_endz->at(i))>67)
							
						if(abs(mcp_endx->at(i))>67)
						{
							dx=67-mcp_startx->at(i);
							if(mcp_endx->at(i)<0) dx=-67-mcp_startx->at(i);
							isNotContained=true;
						}	// if(abs(mcp_endx->at(i))>67)
							
						if(abs(mcp_endy->at(i)-42)>67)
						{
							dy=67+42-mcp_startx->at(i);
							if(mcp_endx->at(i)<0) dy=-67+42-mcp_startx->at(i);
							isNotContained=true;
						}	// if(abs(mcp_endy->at(i)-42)>67)
							
						len_inLAr=TMath::Sqrt(dz*dz+dx*dx+dy*dy);
						
						if(len_inLAr>longestTrack)
						{
							longestTrack=len_inLAr; 
							longestTrack_startx=mcp_startx->at(i);
							longestTrack_starty=mcp_starty->at(i);
							longestTrack_startz=mcp_startz->at(i);
							longestTrack_endx=mcp_endx->at(i);
							longestTrack_endy=mcp_endy->at(i);
							longestTrack_endz=mcp_endz->at(i);
						}	// if(len_inLAr>longestTrack)
							
						truemult++;
						
						if(abs(mcp_pdg->at(i))==13)truemultmu++; 
						if(abs(mcp_pdg->at(i))==211) truemultpi++;
						if(abs(mcp_pdg->at(i))==321) truemultk++;
						if(abs(mcp_pdg->at(i))==2212) truemultp++;
						if(abs(mcp_pdg->at(i))==111)truemultpi0++;
						if(abs(mcp_pdg->at(i))== 22) truemultg++;		
						if(abs(mcp_pdg->at(i))== 2112) truemultn++;	
						if(abs(mcp_pdg->at(i))== 11) truemulte++;	
						if(abs(mcp_pdg->at(i))== 12) truemultenu++;	
						
						if (ccnc->size() > i) 
						{
							if(abs(ccnc->at(i)) == 0)
							{
								if(abs(mcp_pdg->at(i)) == 13) truemultmuCC++;
							}	// if(abs(ccnc->at(i)) == 0)						
						}	// if (ccnc->size() > i)
						
						if (ccnc->size() > i) 
						{
							if(abs(ccnc->at(i)) == 1)
							{
								if(abs(mcp_pdg->at(i)) == 13) truemultmuNC++;
							}	// if(abs(ccnc->at(i)) == 1)						
						}	// if (ccnc->size() > i)
							
						
						if(mode->at(0)==0)truemultQE++;
						if(mode->at(0)==1)truemultRES++;
						if(mode->at(0)==2)truemultDIS++;
						if(mode->at(0)==3)truemultCOH++;
						if(mode->at(0)==10)truemultMEC++;
						
						if(len_inLAr>0.45) numTracks_4mm++; 
						if(len_inLAr>0.45 && isNotContained) numNotContained++;
						if(len_inLAr>1) numTracks_1cm++;
						if(len_inLAr>5) numTracks_5cm++;
						if(len_inLAr>10) numTracks_10cm++;

						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==13) numTracks_4mmMU++; 
						if(len_inLAr>0.45 && isNotContained && abs(mcp_pdg->at(i))==13) numNotContainedMU++;
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==13) numTracks_1cmMU++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==13) numTracks_5cmMU++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==13) numTracks_10cmMU++;						

						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==211) numTracks_4mmPI++; 
						// if(len_inLAr>0.45 && isNotContained && abs(mcp_pdg->at(i))==211) numNotContainedPI++;
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==211) numTracks_1cmPI++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==211) numTracks_5cmPI++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==211) numTracks_10cmPI++;
						
						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==321) numTracks_4mmK++; 
						// if(len_inLAr>0.45 && isNotContained && abs(mcp_pdg->at(i))==321) numNotContainedK++;
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==321) numTracks_1cmK++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==321) numTracks_5cmK++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==321) numTracks_10cmK++;
						
						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==2212) numTracks_4mmP++; 
						// if(len_inLAr>0.45 && isNotContained && abs(mcp_pdg->at(i))==2212) numNotContainedP++;
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==2212) numTracks_1cmP++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==2212) numTracks_5cmP++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==2212) numTracks_10cmP++;
						
						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==111) numTracks_4mmPI0++; 
						// if(len_inLAr>0.45 && isNotContained && abs(mcp_pdg->at(i))==111) numNotContainedPI0++;
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==111) numTracks_1cmPI0++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==111) numTracks_5cmPI0++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==111) numTracks_10cmPI0++;					
						
						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==22) numTracks_4mmG++; 
						// if(len_inLAr>0.45 && isNotContained && abs(mcp_pdg->at(i))==22) numNotContainedG++;
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==22) numTracks_1cmG++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==22) numTracks_5cmG++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==22) numTracks_10cmG++;
						
						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==2112) numTracks_4mmN++; 
						// if(len_inLAr>0.45 && isNotContained && abs(mcp_pdg->at(i))==2112) numNotContainedN++;
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==2112) numTracks_1cmN++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==2112) numTracks_5cmN++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==2112) numTracks_10cmN++;

						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==13) truemultmu_4mm++; 
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==13) truemultmu_1cm++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==13) truemultmu_5cm++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==13) truemultmu_10cm++;	

						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==211) truemultpi_4mm++; 
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==211) truemultpi_1cm++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==211) truemultpi_5cm++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==211) truemultpi_10cm++;	

						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==321) truemultk_4mm++; 
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==321) truemultk_1cm++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==321) truemultk_5cm++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==321) truemultk_10cm++;	
						
						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==2212) truemultp_4mm++; 
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==2212) truemultp_1cm++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==2212) truemultp_5cm++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==2212) truemultp_10cm++;	
				
						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==111) truemultpi0_4mm++; 
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==111) truemultpi0_1cm++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==111) truemultpi0_5cm++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==111) truemultpi0_10cm++;	
						
						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==22) truemultg_4mm++; 
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==22) truemultg_1cm++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==22) truemultg_5cm++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==22) truemultg_10cm++;	
						
						if(len_inLAr>0.45 && abs(mcp_pdg->at(i))==2112) truemultn_4mm++; 
						if(len_inLAr>1 && abs(mcp_pdg->at(i))==2112) truemultn_1cm++;
						if(len_inLAr>5 && abs(mcp_pdg->at(i))==2112) truemultn_5cm++;
						if(len_inLAr>10 && abs(mcp_pdg->at(i))==2112) truemultn_10cm++;	
												
						_truemcppdg			= mcp_pdg->at(i);
						_truemcpStatusCode	= mcp_statuscode->at(i);
						_truemcpTheta		= mcp_theta->at(i);
						_truemcpCosTheta	= mcp_costheta->at(i);	
						_truemcpSinTheta	= mcp_sintheta->at(i);	
						_truemcpE			= mcp_energy->at(i);
						_truemcpMass		= mcp_mass->at(i);
						_truemcpKE			= mcp_ke->at(i);
						_truemcpEndE		= mcp_endenergy->at(i);
						_truemcpPx			= mcp_px->at(i);
						_truemcpPy			= mcp_py->at(i);
						_truemcpPz			= mcp_pz->at(i);
						_truemcpP			= mcp_p->at(i);
						_truemcpStartx		= mcp_startx->at(i);
						_truemcpStarty		= mcp_starty->at(i);
						_truemcpStartz		= mcp_startz->at(i);
						_truemcpEndx		= mcp_endx->at(i);
						_truemcpEndy		= mcp_endy->at(i);
						_truemcpEndz		= mcp_endz->at(i);
						_truemcpPhi			= mcp_phi->at(i);
						_truemcpCosPhi		= mcp_cosphi->at(i);
						_truemcpSinPhi		= mcp_sinphi->at(i);
						
						treemcp.Fill();
												
					}   // particle is in FV
				// }	// range				
			}	// if(mcp_statuscode->at(i)==1)
		}	// for(long unsigned int i=0; i<mcp_id->size(); i++)
			
		for(long unsigned int i=0; i<sed_id->size(); i++)
		{
			_truesedStartx	= sed_startx->at(i);
			_truesedStarty	= sed_starty->at(i);
			_truesedStartz	= sed_startz->at(i);
			_truesedEndx	= sed_endx->at(i);
			_truesedEndy	= sed_endy->at(i);
			_truesedEndz	= sed_endz->at(i);
			_truesedE		= sed_energy->at(i);
			_truesedID		= sed_id->at(i);
			_truesedPdg		= sed_pdg->at(i);
	    
			treesed.Fill();
			
		}	// for(long unsigned int i=0; i<sed_id->size(); i++)
			
		
		_truemult		=truemult;
		_truemultmu		=truemultmu;
		_truemultpi		=truemultpi;
		_truemultk		=truemultk;
		_truemultp		=truemultp;
		_truemultpi0	=truemultpi0;	  
		_truemultg		=truemultg;	  
		_truemultn		=truemultn;	  
		_truemulte		=truemulte;	  
		_truemultenu	=truemultenu;
		
		_truemultmuCC	=truemultmuCC; 
		_truemultmuNC	=truemultmuNC; 
	  
		_truemultQE		= truemultQE;
		_truemultRES	= truemultRES;
		_truemultDIS	= truemultDIS;
		_truemultCOH	= truemultCOH;
		_truemultMEC	= truemultMEC;	
		
		_numTracks_0cm			= numTracks_0cm;
		_numTracks_4mm			= numTracks_4mm; 
		_numTracks_1cm			= numTracks_1cm; 
		_numTracks_5cm			= numTracks_5cm;
		_numTracks_10cm			= numTracks_10cm; 
		_numNotContained		= numNotContained;
		_longestTrack			= longestTrack;
		_longestTrack_startx	= longestTrack_startx;
		_longestTrack_starty	= longestTrack_starty;
		_longestTrack_startz	= longestTrack_startz;
		_longestTrack_endx		= longestTrack_endx;
		_longestTrack_endy		= longestTrack_endy;
		_longestTrack_endz		= longestTrack_endz;

		_numTracks_0cmMU			= numTracks_0cmMU;
		_numTracks_4mmMU			= numTracks_4mmMU; 
		_numTracks_1cmMU			= numTracks_1cmMU; 
		_numTracks_5cmMU			= numTracks_5cmMU;
		_numTracks_10cmMU			= numTracks_10cmMU; 
		_numNotContained			= numNotContainedMU;
		
		_numTracks_0cmPI			= numTracks_0cmPI;
		_numTracks_4mmPI			= numTracks_4mmPI; 
		_numTracks_1cmPI			= numTracks_1cmPI; 
		_numTracks_5cmPI			= numTracks_5cmPI;
		_numTracks_10cmPI			= numTracks_10cmPI; 
		// _numNotContained			= numNotContainedPI;

		_numTracks_0cmK				= numTracks_0cmK;
		_numTracks_4mmK				= numTracks_4mmK; 
		_numTracks_1cmK				= numTracks_1cmK; 
		_numTracks_5cmK				= numTracks_5cmK;
		_numTracks_10cmK			= numTracks_10cmK; 
		// _numNotContained			= numNotContainedK;
		
		_numTracks_0cmP				= numTracks_0cmP;
		_numTracks_4mmP				= numTracks_4mmP; 
		_numTracks_1cmP				= numTracks_1cmP; 
		_numTracks_5cmP				= numTracks_5cmP;
		_numTracks_10cmP			= numTracks_10cmP; 
		// _numNotContained			= numNotContainedP;
		
		_numTracks_0cmPI0			= numTracks_0cmPI0;
		_numTracks_4mmPI0			= numTracks_4mmPI0; 
		_numTracks_1cmPI0			= numTracks_1cmPI0; 
		_numTracks_5cmPI0			= numTracks_5cmPI0;
		_numTracks_10cmPI0			= numTracks_10cmPI0; 
		// _numNotContained			= numNotContainedPI0;
		
		_numTracks_0cmG				= numTracks_0cmG;
		_numTracks_4mmG				= numTracks_4mmG; 
		_numTracks_1cmG				= numTracks_1cmG; 
		_numTracks_5cmG				= numTracks_5cmG;
		_numTracks_10cmG			= numTracks_10cmG; 
		// _numNotContained			= numNotContainedG;

		_numTracks_0cmN				= numTracks_0cmN;
		_numTracks_4mmN				= numTracks_4mmN; 
		_numTracks_1cmN				= numTracks_1cmN; 
		_numTracks_5cmN				= numTracks_5cmN;
		_numTracks_10cmN			= numTracks_10cmN; 
		// _numNotContained			= numNotContainedN;

	    _truemultmu_0cm		= truemultmu_0cm;
		_truemultmu_4mm		= truemultmu_4mm;
		_truemultmu_1cm		= truemultmu_1cm;
		_truemultmu_5cm		= truemultmu_5cm;
		_truemultmu_10cm	= truemultmu_10cm;

	    _truemultpi_0cm		= truemultpi_0cm;
		_truemultpi_4mm		= truemultpi_4mm;
		_truemultpi_1cm		= truemultpi_1cm;
		_truemultpi_5cm		= truemultpi_5cm;
		_truemultpi_10cm	= truemultpi_10cm;
		
	    _truemultk_0cm		= truemultk_0cm;
		_truemultk_4mm		= truemultk_4mm;
		_truemultk_1cm		= truemultk_1cm;
		_truemultk_5cm		= truemultk_5cm;
		_truemultk_10cm		= truemultk_10cm;
		
	    _truemultp_0cm		= truemultp_0cm;
		_truemultp_4mm		= truemultp_4mm;
		_truemultp_1cm		= truemultp_1cm;
		_truemultp_5cm		= truemultp_5cm;
		_truemultp_10cm		= truemultp_10cm;
		
	    _truemultpi0_0cm	= truemultpi0_0cm;
		_truemultpi0_4mm	= truemultpi0_4mm;
		_truemultpi0_1cm	= truemultpi0_1cm;
		_truemultpi0_5cm	= truemultpi0_5cm;
		_truemultpi0_10cm	= truemultpi0_10cm;
		
	    _truemultn_0cm		= truemultn_0cm;
		_truemultn_4mm		= truemultn_4mm;
		_truemultn_1cm		= truemultn_1cm;
		_truemultn_5cm		= truemultn_5cm;
		_truemultn_10cm		= truemultn_10cm;
		
	    _truemultg_0cm		= truemultg_0cm;
		_truemultg_4mm		= truemultg_4mm;
		_truemultg_1cm		= truemultg_1cm;
		_truemultg_5cm		= truemultg_5cm;
		_truemultg_10cm		= truemultg_10cm;
	
		treeevt.Fill();
	
	}	// for (Long64_t jentry=0; jentry<nentries;jentry++)
		
	fout->Write();

}	// void TrackMult2x2wTruth::Loop()
