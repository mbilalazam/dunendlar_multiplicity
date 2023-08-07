## Important Bash Commands

# DUNE Parent Directory
cd /cvmfs/

# Main Directory
cd /dune/app/users/mazam
cd /pnfs/dune/persistent/users/mazam

# Environment Variables
export LANGUAGE=en_US.UTF-8
export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8
export LC_CTYPE=en_US.UTF-8

# Security Setups
source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
setup duneutil v09_63_00d00 -q e20:prof 
setup_fnal_security 

# FNAL UPS Environments
ups list -aK+ genie

# Find a file in FNAL Directories
find . -name <filename>

# This is to include GENIE header files
export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:/dune/app/users/mazam/classes_and_headers/genie_with_geant4/

# Path to my personal header files
/dune/app/users/mazam/classes_and_headers/genie_with_geant4 

# edep-sim needs to know where a certain GEANT .cmake file is...
G4_cmake_file=`find ${GEANT4_FQ_DIR}/lib64 -name 'Geant4Config.cmake'`
export Geant4_DIR=`dirname $G4_cmake_file`
export PATH=$PATH:$GEANT4_FQ_DIR/bin

# setup environment which probably defines $GXMLPATH to some combination of locations
# export GXMLPATH=$GXMLPATH:/dune/app/users/kordosky/nd_sim/event_gen
export GXMLPATH=$GXMLPATH:/dune/app/users/mazam/working_area/proposal/genie_v3_02_00b

# The line below gets rid of errors like this when running genie
# Error in cling::AutoloadingVisitor::InsertIntoAutoloadingState:
#	Missing FileEntry for ReWeight/GReWeightI.h
#	requested to autoload type genie::rew::GSyst
export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$GENIE_INC/GENIE

# Comparison of Genie v2 and v3
cd /dune/app/users/mazam/working_area/proposal
gntpc -i genieV30200b.12345.ghep.root -f gst -n 10000 -o genieV3out.root
gntpc -i genieV21210c.12345.ghep.root -f gst -n 10000 -o genieV2out.root

# To save the histogram in png, use the following commands
TCanvas *nf = new TCanvas();
gst->Draw("nf");
nf->Print("genieV3_total_multiplicity.png");

# Important Softwares
export LANGUAGE=en_US.UTF-8
export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8
export LC_CTYPE=en_US.UTF-8

source /grid/fermiapp/products/dune/setup_dune.sh
setup duneutil v09_63_00d00 -q e20:prof 
setup_fnal_security 

setup ifdhc
setup jobsub_client
setup pycurl
setup cmake	v3_24_0
setup gcc v9_3_0
setup root v6_22_08d -q e20:p392:prof
setup geant4 v4_11_0_p01c -q e20:prof
setup edepsim v3_2_0 -q e20:prof
setup genie	v3_02_00b -q e20:prof
setup genie_xsec v3_02_00 -q G1810a0211a:e1000:k250
setup genie_phyopt v3_02_00 -q dkcharm
setup nutools v3_13_02 -q e20:prof
setup dk2nugenie v01_10_00g -q e20:prof

# Send an email via terminal
echo "body" | mutt -s "subject" -a *.png *.h *.C -- mazam3@hawk.iit.edu


## Commit changes to github repository

# Clone the repository
git clone <repository>
 
# Add the file to staging area
# git add <filename> 
# Add all files to staging area
git add . 

# Commit the changes
# Replace Commit message with a brief description of the changes
git commit -m "Commit message" 

# Push the changes to the remote repository
git push
Username for 'https://github.com': mazam3@hawk.iit.edu
Password for 'https://mazam3@hawk.iit.edu@github.com': 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


# Install a custom python package
pip install --user h5py
