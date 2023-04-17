// This code is to print all leaves, branches and trees of a root file
#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TLeaf.h>

void findLeavesAndBranches(const char* filename) {
    TFile* file = new TFile(filename, "READ");
    if (!file->IsOpen()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }
    std::cout << "Opened file " << filename << std::endl;
    // Loop over all objects in the file
    TIter next(file->GetListOfKeys());
    TKey* key;
    while ((key = (TKey*)next())) {
        TObject* obj = key->ReadObj();
        if (obj->IsA()->InheritsFrom(TTree::Class())) {
            TTree* tree = (TTree*)obj;
            std::cout << "Tree: " << tree->GetName() << std::endl;
            // Loop over all branches in the tree
            TObjArray* branches = tree->GetListOfBranches();
            for (Int_t i = 0; i < branches->GetEntries(); i++) {
                TBranch* branch = (TBranch*)branches->At(i);
                std::cout << "\tBranch: " << branch->GetName() << std::endl;
                // Loop over all leaves in the branch
                TObjArray* leaves = branch->GetListOfLeaves();
                for (Int_t j = 0; j < leaves->GetEntries(); j++) {
                    TLeaf* leaf = (TLeaf*)leaves->At(j);
                    std::cout << "\t\tLeaf: " << leaf->GetName() << std::endl;
                }
            }
        }
    }
    file->Close();
}

int main() {
    findLeavesAndBranches("TrackMult2x2wTruth.root");
    return 0;
}


// run this code using
// root
// .L FindLeavesAndBranches.C
// FindLeavesAndBranches("out.root")
