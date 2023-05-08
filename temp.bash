# Run sample (I like to do this in the parent of dunendlar_tutorial directory)

lar -c prodgenie_nu_dunend2x2.fcl -n 1000 -o out_gen.root
lar -c dunend2x2_g4.fcl out_gen.root -n 1000 
lar -c runsimdumpnew_dunend2x2.fcl out_gen_g4.root -n 1000


## Some Lines from the Output of `lar -c dunend2x2_g4.fcl out_gen.root -n 1000'
TimeReport ---------- Time summary [sec] -------
TimeReport CPU = 255.483326 Real = 261.253009

MemReport  ---------- Memory summary [base-10 MB] ------
MemReport  VmPeak = 2183.16 VmHWM = 1448.87

%MSG-w MCTruthEventAction:  PostEndJob 08-May-2023 16:26:51 CDT ModuleEndJob
The following unknown PDG codes were present in the simb::MCTruth input.
They were not processed by Geant4.
   Unknown PDG code = 2000000101, seen 31 times.  (GENIE specific)
%MSG
%MSG-d MCTruthEventAction:  PostEndJob 08-May-2023 16:26:51 CDT ModuleEndJob
The following PDG codes were present in the simb::MCTruth input with Status != 1.
They were not processed by Geant4.
   PDG code = -2112, seen 1 times.
   PDG code = -323, seen 5 times.
   PDG code = -321, seen 9 times.
   PDG code = -311, seen 10 times.
   PDG code = -213, seen 28 times.
   PDG code = -211, seen 425 times.
   PDG code = -14, seen 21 times.
   PDG code = 0, seen 15 times.
   PDG code = 1, seen 37 times.
   PDG code = 2, seen 182 times.
   PDG code = 3, seen 1 times.
   PDG code = 12, seen 8 times.
   PDG code = 14, seen 971 times.
   PDG code = 92, seen 220 times.
   PDG code = 111, seen 774 times.
   PDG code = 113, seen 49 times.
   PDG code = 130, seen 1 times.
   PDG code = 211, seen 844 times.
   PDG code = 213, seen 55 times.
   PDG code = 221, seen 66 times.
   PDG code = 223, seen 33 times.
   PDG code = 310, seen 1 times.
   PDG code = 311, seen 35 times.
   PDG code = 313, seen 6 times.
   PDG code = 321, seen 39 times.
   PDG code = 323, seen 7 times.
   PDG code = 331, seen 3 times.
   PDG code = 333, seen 2 times.
   PDG code = 411, seen 6 times.
   PDG code = 421, seen 8 times.
   PDG code = 1103, seen 15 times.
   PDG code = 1114, seen 18 times.
   PDG code = 1116, seen 1 times.
   PDG code = 1214, seen 2 times.
   PDG code = 2101, seen 11 times.
   PDG code = 2103, seen 139 times.
   PDG code = 2112, seen 1031 times.
   PDG code = 2114, seen 53 times.
   PDG code = 2118, seen 1 times.
   PDG code = 2122, seen 1 times.
   PDG code = 2124, seen 23 times.
   PDG code = 2126, seen 1 times.
   PDG code = 2203, seen 55 times.
   PDG code = 2212, seen 892 times.
   PDG code = 2214, seen 92 times.
   PDG code = 2216, seen 3 times.
   PDG code = 2218, seen 4 times.
   PDG code = 2224, seen 87 times.
   PDG code = 2226, seen 2 times.
   PDG code = 2228, seen 2 times.
   PDG code = 3112, seen 1 times.
   PDG code = 3114, seen 2 times.
   PDG code = 3122, seen 34 times.
   PDG code = 3212, seen 1 times.
   PDG code = 3214, seen 2 times.
   PDG code = 3222, seen 21 times.
   PDG code = 3224, seen 6 times.
   PDG code = 3312, seen 1 times.
   PDG code = 3324, seen 1 times.
   PDG code = 4122, seen 4 times.
   PDG code = 4212, seen 2 times.
   PDG code = 12112, seen 2 times.
   PDG code = 12114, seen 3 times.
   PDG code = 12116, seen 1 times.
   PDG code = 12212, seen 11 times.
   PDG code = 12214, seen 2 times.
   PDG code = 12216, seen 17 times.
   PDG code = 12224, seen 9 times.
   PDG code = 22112, seen 6 times.
   PDG code = 22124, seen 3 times.
   PDG code = 22212, seen 24 times.
   PDG code = 22214, seen 2 times.
   PDG code = 22222, seen 2 times.
   PDG code = 22224, seen 3 times.
   PDG code = 31214, seen 5 times.
   PDG code = 32124, seen 15 times.
   PDG code = 42212, seen 2 times.
   PDG code = 1000050100, seen 1 times.
   PDG code = 1000050110, seen 13 times.
   PDG code = 1000060110, seen 17 times.
   PDG code = 1000060120, seen 30 times.
   PDG code = 1000070140, seen 1 times.
   PDG code = 1000070150, seen 12 times.
   PDG code = 1000080140, seen 1 times.
   PDG code = 1000080150, seen 30 times.
   PDG code = 1000080160, seen 44 times.
   PDG code = 1000100220, seen 1 times.
   PDG code = 1000110220, seen 2 times.
   PDG code = 1000110230, seen 3 times.
   PDG code = 1000130270, seen 7 times.
   PDG code = 1000140270, seen 17 times.
   PDG code = 1000140280, seen 24 times.
   PDG code = 1000170380, seen 8 times.
   PDG code = 1000170390, seen 290 times.
   PDG code = 1000180380, seen 11 times.
   PDG code = 1000180390, seen 568 times.
   PDG code = 1000180400, seen 876 times.
   PDG code = 1000190380, seen 7 times.
   PDG code = 1000190390, seen 10 times.
   PDG code = 1000210470, seen 1 times.
   PDG code = 1000220470, seen 2 times.
   PDG code = 1000220480, seen 3 times.
   PDG code = 1000290630, seen 3 times.
   PDG code = 1000300630, seen 4 times.
   PDG code = 1000300640, seen 7 times.
   PDG code = 2000000001, seen 626 times.  (GENIE specific)
   PDG code = 2000000002, seen 1002 times.  (GENIE specific)
   PDG code = 2000000200, seen 11 times.  (GENIE specific)
   PDG code = 2000000201, seen 17 times.  (GENIE specific)
   PDG code = 2000000202, seen 8 times.  (GENIE specific)
   PDG code = 2000000300, seen 419 times.  (GENIE specific)
%MSG
%MSG-d MCTruthEventAction:  PostEndJob 08-May-2023 16:26:51 CDT ModuleEndJob
The following PDG codes were present in the simb::MCTruth input with Status = 1 and were processed by Geant4
   PDG code = -2112, seen 1 times.
   PDG code = -321, seen 13 times.
   PDG code = -311, seen 10 times.
   PDG code = -211, seen 491 times.
   PDG code = -14, seen 6 times.
   PDG code = -13, seen 15 times.
   PDG code = -11, seen 1 times.
   PDG code = 11, seen 4 times.
   PDG code = 12, seen 5 times.
   PDG code = 13, seen 736 times.
   PDG code = 14, seen 235 times.
   PDG code = 22, seen 106 times.
   PDG code = 111, seen 700 times.
   PDG code = 130, seen 5 times.
   PDG code = 211, seen 800 times.
   PDG code = 311, seen 35 times.
   PDG code = 321, seen 40 times.
   PDG code = 2112, seen 2118 times.
   PDG code = 2212, seen 2139 times.
   PDG code = 3122, seen 34 times.
   PDG code = 3222, seen 18 times.
   PDG code = 1000060120, seen 1 times.
   PDG code = 1000180400, seen 2 times. 
   %MSG
Art has completed and will exit with status 0.
=======================================================================
======       Pre-compound/De-excitation Physics Parameters     ========
=======================================================================
Type of pre-compound inverse x-section              3
Pre-compound model active                           1
Pre-compound excitation low energy (MeV)            0.1
Pre-compound excitation high energy (MeV)           30
Type of de-excitation inverse x-section             3
Type of de-excitation factory                       Evaporation+GEM
Number of de-excitation channels                    68
Min excitation energy (keV)                         0.01
Min energy per nucleon for multifragmentation (MeV) 2e+05
Limit excitation energy for Fermi BreakUp (MeV)     20
Level density (1/MeV)                               0.075
Use simple level density model                      1
Use discrete excitation energy of the residual      0
Time limit for long lived isomeres (ns)             1e+12
Internal e- conversion flag                         1
Store e- internal conversion data                   0
Electron internal conversion ID                     2
Correlated gamma emission flag                      0
Max 2J for sampling of angular correlations         10
Upload data before 1st event for                Z < 9
=======================================================================

## Some Lines from the Output of `lar -c runsimdumpnew_dunend2x2.fcl out_gen_g4.root -n 1000'
Summary of seeds computed by the NuRandomService
Random policy: 'random'
  master seed: 118780623
  seed within: [ 1 ; 900000000 ]

%MSG

TrigReport ---------- Event summary -------------
TrigReport Events total = 1000 passed = 1000 failed = 0

TrigReport ---------- Modules in End-path ----------
TrigReport        Run    Success      Error Name
TrigReport       1000       1000          0 simdumpnew

TimeReport ---------- Time summary [sec] -------
TimeReport CPU = 319.443728 Real = 371.834406

MemReport  ---------- Memory summary [base-10 MB] ------
MemReport  VmPeak = 2542.04 VmHWM = 1517.7

