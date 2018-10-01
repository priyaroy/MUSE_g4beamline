#include <iostream>
#include "TROOT.h"
#include "TStyle.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TVector3.h"

using namespace std;

//////////////////////////////////////////////
//Input rootfile
//////////////////////////////////////////////

extern Tfile *MuseFile;

/////////////////////////////////////////////////////////////////////
// Input rootfile's tree
////////////////////////////////////////////////////////////////////

extern TTree *tree0; //ntuple for virtual detector 0
extern TTree *tree3; //ntuple for detector at IFP
extern TTree *treeTar;//ntuple for detector at MUSE target

///////////////////////////////////////////////////////////////////////
//variables storing information from branches of input rootfile
///////////////////////////////////////////////////////////////////////

///////////the first virtual detector in the beamline

//spatial info

extern double Det0_x;
extern double Det0_y;
extern double Det0_z;

//momentum info

extern double Det0_Px;
extern double Det0_Py;
extern double Det0_Pz;

// timing info

extern double Det0_t;

//track, particle ID, event ID info

extern int Det0_PDGid;
extern int Det0_EventID;
extern int Det0_TrackID;

///////////the virtual detector at the intermediate focal point in the beamline

//spatial info

extern double Det3_x;
extern double Det3_y;
extern double Det3_z;

//momentum info

extern double Det3_Px;
extern double Det3_Py;
extern double Det3_Pz;

// timing info

extern double Det3_t;

//track, particle ID, event ID info

extern int Det3_PDGid;
extern int Det3_EventID;
extern int Det3_TrackID;

///////////the virtual detector at the MUSE target in the beamline

//spatial info

extern double DetTar_x;
extern double DetTar_y;
extern double DetTar_z;

//momentum info

extern double DetTar_Px;
extern double DetTar_Py;
extern double DetTar_Pz;

// timing info

extern double DetTar_t;

//track, particle ID, event ID info

extern int DetTar_PDGid;
extern int DetTar_EventID;
extern int DetTar_TrackID;

