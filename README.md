# Instructions for Running the DUNE Multiplicity Analysis Code

## Setup DUNE Software
```
export LANGUAGE=en_US.UTF-8
export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8
export LC_CTYPE=en_US.UTF-8

source /grid/fermiapp/products/dune/setup_dune.sh
```

## Copy the Module
Copy the dunendlar module from `Analysis` folder to your desired directory. This path will be of like this: `/dune/app/users/mazam/working_area/dunendlar_multiplicity/srcs/dunendlar/dunendlar/Analysis`.

## Build the Code
Navigate to your build directory and run the following commands:
```
source ./localProducts_larsoft_v09_58_01_e20_prof/setup
mrbsetenv
mrb i -j8
mrbslp
```

## Generate `simdump.root` File
Run the following commands to generate the `simdump.root` file:
```
lar -c prodgenie_nu_dunend2x2.fcl -n 100 -o out_gen.root
lar -c dunend2x2_g4.fcl out_gen.root -n 100 
lar -c runsimdumpnew_dunend2x2.fcl out_gen_g4.root -n 100
```

## Edit `TrackMult2x2wTruth.h`
In the `TrackMult2x2wTruth.h` file located in the macros directory, specify the path to your `simdump.root` file.


## Run the Analysis Code
Open `root` in your terminal and execute the following commands:
```
root [0] .L TrackMult2x2wTruth.C+
root [1] TrackMult2x2wTruth t
root [2] t.Loop()
```
This will generate a `TrackMult2x2wTruth.root` file.

## Run the Plotting Macros
Feed the `TrackMult2x2wTruth.root` file into the `plotTrackMult2x2wTruthMuCuts.C`, `plotTrackMult2x2wTruthMuNoCut.C`, and `plotTrackMult2x2wTruthmult.C` macros by executing the following commands in root:
```
root [0] .L plotTrackMult2x2wTruthMuCuts.C
root [1] plotTrackMult2x2wTruthMuCuts()
root [2] .L plotTrackMult2x2wTruthMuNoCut.C
root [3] plotTrackMult2x2wTruthMuNoCut()
root [4] .L plotTrackMult2x2wTruthmult.C
root [5] plotTrackMult2x2wTruthmult()
```

This will generate the plots for the DUNE multiplicity analysis.







