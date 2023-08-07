// Code to read and print the values of a branch 
#include <iostream>
#include <TFile.h>
#include <TTree.h>

void printBranchValues() {

  // Open the ROOT file
  TFile *file = TFile::Open("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root", "READ");

  // Get the tree from the file
  TTree *treeevt = (TTree*)file->Get("evtTree");
  TTree *treemcp = (TTree*)file->Get("mcpTree");

  // Declare variables for the branch data

int nu_PDG;
int nu_ccnc;
int nu_inttype=-999;
int nu_mode=-999;

float _truemcpKE=-999;
int _truemcppdg=-999;


  // Set the branch address to the variables
  treeevt->SetBranchAddress("nu_PDG", &nu_PDG);
  treeevt->SetBranchAddress("nu_ccnc", &nu_ccnc);
  treeevt->SetBranchAddress("nu_inttype", &nu_inttype);
  treeevt->SetBranchAddress("nu_mode", &nu_mode);

  treemcp->SetBranchAddress("_truemcpKE", &_truemcpKE);
  treemcp->SetBranchAddress("_truemcppdg", &_truemcppdg);

  
 
  // Loop over the entries in the tree and print the branch values
  // for (Long64_t iEntry=0; iEntry<treemcp->GetEntries(); iEntry++) {
    // treemcp->GetEntry(iEntry);
	// if (_truemcpKE >= 2.0 && abs(_truemcppdg) == 13) {
	// std::cout << nu_mode << std::endl;
	// std::cout << _truemcpKE << " ; " << _truemcppdg <<  std::endl;	
	// }
    // std::cout << "Entry " << iEntry << ": nu_PDG = " << nu_PDG << ": nu_ccnc = " << nu_ccnc <<  ": nu_inttype = " << nu_inttype <<  ": nu_mode = " << nu_mode << std::endl;
    // std::cout << nu_mode << std::endl;
  // }


double sum = 0.0;
int count = 0;

for (Long64_t iEntry = 0; iEntry < treemcp->GetEntries(); iEntry++) {
    treemcp->GetEntry(iEntry);
    
    if (_truemcpKE >= 2.0 && abs(_truemcppdg) == 13) {
        std::cout << _truemcpKE << std::endl;
        sum += _truemcpKE;
        count++;
    }
}

double average = sum / count;
std::cout << "Average: " << average << std::endl;

  // Close the file
  file->Close();
}


// run this code using
// root -l -b
// .L printBranchValues.C
// printBranchValues()
