## My Personal Notes from Multiplicity Studies of Muon

### Date: 2023-04-15
- Path: `/dune/app/users/mazam/working_area/dunendlar_multiplicity/work`
- Files: `plotTrackMult2x2wTruthMuCC.C` `plotTrackMult2x2wTruthMuNC.C`

By printing `_ftrueInAccpparmultmu` and `nu_ccnc`, I obtained these sample outputs:
- Entry 2: `_ftrueInAccpparmultmu = 1` : `nu_ccnc = 0` (1 true Muon and CC)
- Entry 3: `_ftrueInAccpparmultmu = 0` : `nu_ccnc = 1` (0 true Muon and NC)

It indicates that there is 0 multiplicity in the code.


### Date: 2023-04-26
#### Slide 5
- (CC): `m = 0` -> Dominated by anti-tau 
- (NC): `m = 0` -> Dominated by anti-leptons 

#### Slide 7
- (NC): `m = 0` -> Dominated by anti-tau, electron anti-neutrinos and muon anti-neutrinos


### Date: 2023-04-26
#### Zelimir's Comments
- Take 3000 events.
- Classify into CC and NC and count (muon vs electron neutrinos).
- Make a CC histogram of muon neutrino and electron neutrino.
- The pattern of CC and NC neutrinos should be the same.
