// Code to read and print the values of a branch 
#include <iostream>
#include <TFile.h>
#include <TTree.h>

void printBranchValues() {

  // Open the ROOT file
  TFile *file = TFile::Open("TrackMult2x2wTruth.root", "READ");

  // Get the tree from the file
  TTree *treeevt = (TTree*)file->Get("evtTree");

  // Declare variables for the branch data

int _truemultg;
int nu_ccnc;

  // Set the branch address to the variables
  treeevt->SetBranchAddress("_truemultg", &_truemultg);
  treeevt->SetBranchAddress("nu_ccnc", &nu_ccnc);

  
 
  // Loop over the entries in the tree and print the branch values
  for (Long64_t iEntry=0; iEntry<treeevt->GetEntries(); iEntry++) {
    treeevt->GetEntry(iEntry);
    std::cout << "Entry " << iEntry << ": _truemultg = " << _truemultg << ": nu_ccnc = " << nu_ccnc << std::endl;
  }

  // Close the file
  file->Close();
}


// run this code using
// root -l -b
// .L printBranchValues.C
// printBranchValues()
