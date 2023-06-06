######
#You do all development in the srcs directory, you do not need to git clone again unless you want an entirely different build. When you login again:
######
# Set the language and locale variables to UTF-8
export LANGUAGE=en_US.UTF-8
export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8
export LC_CTYPE=en_US.UTF-8

# Source the DUNE software setup script
source /grid/fermiapp/products/dune/setup_dune.sh

# Change directory to working area and source the larsoft setup script
cd /dune/app/users/mazam/working_area/dunendlar_multiplicity/
source ./localProducts_larsoft_v09_58_01_e20_prof/setup

# Set up the mrb environment
mrbsetenv

# Build the code with 8 threads
mrb i -j8

# Set up the mrbslp script for running the code
mrbslp

cd bilal_work/inProgress/

