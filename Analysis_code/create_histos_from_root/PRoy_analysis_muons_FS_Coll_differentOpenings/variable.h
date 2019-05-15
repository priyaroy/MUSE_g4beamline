#include <iostream>
#include "TROOT.h"
#include "TStyle.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TVector3.h"

using namespace std;

extern char name[100];
extern int nentries_Tar;

//////////////////////////////////////////////
//Input rootfile
//////////////////////////////////////////////

extern TFile *MuseFile;

/////////////////////////////////////////////////////////////////////
// Input rootfile's tree
////////////////////////////////////////////////////////////////////

extern TTree *tree0; //ntuple for virtual detector 0
extern TTree *tree0a; //ntuple for virtual detector 0a
extern TTree *treeAQTA1; //ntuple for detector AQTA1
extern TTree *treeAQTB1; //ntuple for detector AQTB1
extern TTree *treeAQTB2; //ntuple for detector AQTB2
extern TTree *tree1; //ntuple for virtual detector 1
extern TTree *tree2; //ntuple for virtual detector 2
extern TTree *tree3; //ntuple for detector at IFP
extern TTree *tree4; //ntuple for virtual detector 4
extern TTree *tree5; //ntuple for virtual detector 5
extern TTree *treeTar;//ntuple for detector at MUSE target

///////////////////////////////////////////////////////////////////////
//variables storing information from branches of input rootfile
///////////////////////////////////////////////////////////////////////

///////////the first virtual detector in the beamline

//spatial info

extern float_t Det0_x;
extern float_t Det0_y;
extern float_t Det0_z;

//momentum info

extern float_t Det0_Px;
extern float_t Det0_Py;
extern float_t Det0_Pz;
extern float_t Det0_P;

// timing info

extern float_t Det0_t;

//track, particle ID, event ID info

extern float_t Det0_PDGid;
extern float_t Det0_EventID;
extern float_t Det0_TrackID;

///////////the virtual detector at start of QTA1 in the beamline

//spatial info

extern float_t Det0a_x;
extern float_t Det0a_y;
extern float_t Det0a_z;

//momentum info

extern float_t Det0a_Px;
extern float_t Det0a_Py;
extern float_t Det0a_Pz;
extern float_t Det0a_P;

// timing info

extern float_t Det0a_t;

//track, particle ID, event ID info

extern float_t Det0a_PDGid;
extern float_t Det0a_EventID;
extern float_t Det0a_TrackID;

///////////the virtual detector between QTA1 & QTB1 in the beamline

//spatial info

extern float_t DetAQTA1_x;
extern float_t DetAQTA1_y;
extern float_t DetAQTA1_z;

//momentum info

extern float_t DetAQTA1_Px;
extern float_t DetAQTA1_Py;
extern float_t DetAQTA1_Pz;
extern float_t DetAQTA1_P;

// timing info

extern float_t DetAQTA1_t;

//track, particle ID, event ID info

extern float_t DetAQTA1_PDGid;
extern float_t DetAQTA1_EventID;
extern float_t DetAQTA1_TrackID;

///////////the virtual detector between QTB1 & QTB2 in the beamline

//spatial info

extern float_t DetAQTB1_x;
extern float_t DetAQTB1_y;
extern float_t DetAQTB1_z;

//momentum info

extern float_t DetAQTB1_Px;
extern float_t DetAQTB1_Py;
extern float_t DetAQTB1_Pz;
extern float_t DetAQTB1_P;

// timing info

extern float_t DetAQTB1_t;

//track, particle ID, event ID info

extern float_t DetAQTB1_PDGid;
extern float_t DetAQTB1_EventID;
extern float_t DetAQTB1_TrackID;

///////////the virtual detector after QTB2 in the beamline

//spatial info

extern float_t DetAQTB2_x;
extern float_t DetAQTB2_y;
extern float_t DetAQTB2_z;

//momentum info

extern float_t DetAQTB2_Px;
extern float_t DetAQTB2_Py;
extern float_t DetAQTB2_Pz;
extern float_t DetAQTB2_P;

// timing info

extern float_t DetAQTB2_t;

//track, particle ID, event ID info

extern float_t DetAQTB2_PDGid;
extern float_t DetAQTB2_EventID;
extern float_t DetAQTB2_TrackID;

/////////// virtual detector at entrance of dipole 1 in the beamline

//spatial info

extern float_t Det1_x;
extern float_t Det1_y;
extern float_t Det1_z;

//momentum info

extern float_t Det1_Px;
extern float_t Det1_Py;
extern float_t Det1_Pz;
extern float_t Det1_P;

// timing info

extern float_t Det1_t;

//track, particle ID, event ID info

extern float_t Det1_PDGid;
extern float_t Det1_EventID;
extern float_t Det1_TrackID;

/////////// virtual detector at exit of dipole 1 in the beamline

//spatial info

extern float_t Det2_x;
extern float_t Det2_y;
extern float_t Det2_z;

//momentum info

extern float_t Det2_Px;
extern float_t Det2_Py;
extern float_t Det2_Pz;
extern float_t Det2_P;

// timing info

extern float_t Det2_t;

//track, particle ID, event ID info

extern float_t Det2_PDGid;
extern float_t Det2_EventID;
extern float_t Det2_TrackID;

///////////the virtual detector at the intermediate focal point in the beamline

//spatial info

extern float_t Det3_x;
extern float_t Det3_y;
extern float_t Det3_z;

//momentum info

extern float_t Det3_Px;
extern float_t Det3_Py;
extern float_t Det3_Pz;
extern float_t Det3_P;

// timing info

extern float_t Det3_t;

//track, particle ID, event ID info

extern float_t Det3_PDGid;
extern float_t Det3_EventID;
extern float_t Det3_TrackID;

///////////the virtual detector at entrance of dipole 2 in the beamline

//spatial info

extern float_t Det4_x;
extern float_t Det4_y;
extern float_t Det4_z;

//momentum info

extern float_t Det4_Px;
extern float_t Det4_Py;
extern float_t Det4_Pz;
extern float_t Det4_P;

// timing info

extern float_t Det4_t;

//track, particle ID, event ID info

extern float_t Det4_PDGid;
extern float_t Det4_EventID;
extern float_t Det4_TrackID;

///////////the virtual detector at exit of dipole 2 in the beamline

//spatial info

extern float_t Det5_x;
extern float_t Det5_y;
extern float_t Det5_z;

//momentum info

extern float_t Det5_Px;
extern float_t Det5_Py;
extern float_t Det5_Pz;
extern float_t Det5_P;

// timing info

extern float_t Det5_t;

//track, particle ID, event ID info

extern float_t Det5_PDGid;
extern float_t Det5_EventID;
extern float_t Det5_TrackID;

///////////the virtual detector at the MUSE target in the beamline

//spatial info

extern float_t DetTar_x;
extern float_t DetTar_y;
extern float_t DetTar_z;

//momentum info

extern float_t DetTar_Px;
extern float_t DetTar_Py;
extern float_t DetTar_Pz;
extern float_t DetTar_P;

// timing info

extern float_t DetTar_t;

//track, particle ID, event ID info

extern float_t DetTar_PDGid;
extern float_t DetTar_EventID;
extern float_t DetTar_TrackID;

