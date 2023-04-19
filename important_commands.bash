# Run sample (I like to do this in the parent of dunendlar_tutorial directory)

lar -c prodgenie_nu_dunend2x2.fcl -n 10000 -o out_gen.root
lar -c dunend2x2_g4.fcl out_gen.root -n 10000 
lar -c runsimdumpnew_dunend2x2.fcl out_gen_g4.root -n 10000

# Some plotting commnads
.L plotTrackMult2x2wTruthMuCC.C
plotTrackMult2x2wTruthMuCC()

.L plotTrackMult2x2wTruthMuCuts.C
plotTrackMult2x2wTruthMuCuts()

.L plotTrackMult2x2wTruthmult.C
plotTrackMult2x2wTruthmult()

.L plotTrackMult2x2wTruthMuNC.C
plotTrackMult2x2wTruthMuNC()

.L plotTrackMult2x2wTruthMuNoCut.C
plotTrackMult2x2wTruthMuNoCut()

# Some commands to send email from terminal
echo "These multiplicity plots are without any cut. Only cut is in mult_mu_c0p95.png for cos(theta)<0.95." | mutt -s "nocutonRange" -a *.png *.h *.C -- mazam3@hawk.iit.edu

echo "These multiplicity plots are with cut on range (acceptance). An additional cut is in mult_mu_c0p95.png for cos(theta)<0.95." | mutt -s "withcutonRange" -a *.png *.h *.C -- mazam3@hawk.iit.edu

echo "These are multiplicity plots with cut on particle's track length." | mutt -s "withcutonLength" -a *.png *.h *.C -- mazam3@hawk.iit.edu

echo "These are  multiplicity plots with cuts on range (acceptance) and particle's track length." | mutt -s "withcutonRangeAndLength" -a *.png *.h *.C -- mazam3@hawk.iit.edu



