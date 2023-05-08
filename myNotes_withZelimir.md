# Multiplicity Studies Meeting Notes

## Multiplicity Convention
- Multiplicity 0: 1 u + 1 p
- Multiplicity 1: 1 u + 1 p + some other particle
- Convention used by scientists

## Focus on Events with Multiplicity 0 and 3
- Two reconstructions: PANDORA and ML-based approach
- Questions:
  - Can you show high level distributions (Q2, W, etc) and can you eliminate the muon to make CC/NC comparisons more clear? (Artyem)
  - What are distributions for just one module? (Nikolai)
- D22 Generator for nominal production

## 2x2 Simulation and Calibration Meeting
- Friday Mar 17, 2023, 11:00 AM → 12:15 PM US/Central
- indico.fnal.gov/event/58953
- lbnl.zoom.us/j/95329703379

## Comments from Zelimir's Meeting (April 4, 2023)
- NuMI beam is high energy beam: 5 to 7 GeV
- Our ideal range is 2.5 GeV
- ccqe_m2_cuts.png
  - Cut1: cos (theta Muon) < 0.95
  - Cut2: Hadrons < 1.5 GeV
  - Mult 2 (1p + 1u)
  - Black: true E_nu
  - Red: E_nu calculated from E_mu + E_pu
  - Blue: E_nu calculated from muon
  - Green: E_nu calculated from E_p
- ccqe_m2_nocuts.png
- Next step is to optimize cuts and see how these cuts affect the minimal track lengths.
- MC End
  - This might have something to do with the MINERvA planes. These planes are sensitive to neutrinos coming. Most muons will be escaped and will be into MINERva plans. Hard for protons to escape.

## NOvA Meeting (April 11, 2023)
- Slide 3: Study .fcl file to see the start coordinates of beam. Study .gdml file to know the detector boundary.
- Slide 4: Apply energy cut
- Slide 9: No LArTPC. Mention 2x2 geometry
- Slide 10: Second bullet is wrong. x is zero. z is defined (look into it).
- Slide 11: z is defined (look into it).
- Slide 13: Meaningless plot
- Slide 14: No cosmic ray contributions. Also include pi0, photons etc.
- Slide 15: Momentum is along z-axis.
- Slide 17: It could be MINERvA planes and also some vacuum outside the detector.
- Slide 19: Are the start positions of first SED event?

## Comments from Zelimir's Meeting (April 18, 2023)
- Slide 2: Make multiplicity plot of all interaction modes for CC/NC particles separately.
- Slide 4: Check if 0 multiplicity particles are electron or electron neutrino.
- Slide 7: Make multiplicity plots for ending track lengths.
- Correction: It is not detector's length but particle's track length.
- Note: Change all multiplicity bins to integer bins.
