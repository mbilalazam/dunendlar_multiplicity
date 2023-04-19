# Set encoding and locale environment variables
export LANGUAGE=en_US.UTF-8
export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8
export LC_CTYPE=en_US.UTF-8

# Set up DUNE environment
source /grid/fermiapp/products/dune/setup_dune.sh

# Create a new directory and move to it
cd /dune/app/users/mazam
mkdir dunendlar_tutorial
cd dunendlar_tutorial

# Set up dunendlar package
setup dunendlar v01_01_00 -q e20:prof
mrb newDev
source ./localProducts_larsoft_v09_58_01_e20_prof/setup
cd srcs
git clone https://github.com/DUNE/dunendlar.git

# Edit product_deps file and go back to srcs directory
# NOTE: Manual editing is required in this step, so the execution stops here and waits for user intervention
# Once the file is edited, the script can continue
#######
STOP and edit srcs/dunendlar/ups/product_deps at line 25 from LBNFFlux.xml to GNuMIFlux.xml (you can check in the srcs/dunendlar/dunendlar/Generator to see the xmls)
Go back to the dunendlar_tutorial/srcs directory
######

# Unpack the source code and set up the build environment
mrb uc
cd .. # go back to the /dune/app/users/mazam/dunendlar_tutorial directory
source ./localProducts_larsoft_v09_58_01_e20_prof/setup
cd $MRB_BUILDDIR
mrbsetenv
mrb i --generator ninja
mrbslp



