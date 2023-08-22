# Run sample (I like to do this in the parent of dunendlar_tutorial directory)

lar -c prodgenie_nu_dunend2x2.fcl -n 1000 -o out_gen.root
lar -c dunend2x2_g4.fcl out_gen.root -n 1000 
lar -c runsimdumpnew_dunend2x2.fcl out_gen_g4.root -n 1000

# Some plotting commnads
.L plotTrackMult2x2wTruthMuCC.C
plotTrackMult2x2wTruthMuCC()

# Some commands to send email from terminal
echo "These multiplicity plots are without any cut. Only cut is in mult_mu_c0p95.png for cos(theta)<0.95." | mutt -s "nocutonRange" -a *.png *.h *.C -- mazam3@hawk.iit.edu


