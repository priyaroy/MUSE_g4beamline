//////////////////////////////////////////
//  Initialize Variables
/////////////////////////////////////////

#include <iostream>
#include "variable.h"

using namespace std;

void initialize()
{
  //the first virtual detector in the beamline

  //spatial info
 
  Det0_x = -99.99;
  Det0_y = -99.99;
  Det0_z = -99.99;

  //momentum info
  
  Det0_Px = -99.99;
  Det0_Py = -99.99;
  Det0_Pz = -99.99;

  //timing info

  Det0_t = -99.99;

  //track, particle ID, event ID info

  Det0_PDGid = -100;
  Det0_EventID = -100;
  Det0_TrackID = -100;
  
 //the virtual detector at start of QTA11 in the beamline

  //spatial info
 
  Det0a_x = -99.99;
  Det0a_y = -99.99;
  Det0a_z = -99.99;

  //momentum info
  
  Det0a_Px = -99.99;
  Det0a_Py = -99.99;
  Det0a_Pz = -99.99;

  //timing info

  Det0a_t = -99.99;

  //track, particle ID, event ID info

  Det0a_PDGid = -100;
  Det0a_EventID = -100;
  Det0a_TrackID = -100;
  
//the virtual detector at between QTA11 & QTB1 in the beamline

  //spatial info
 
  DetAQTA1_x = -99.99;
  DetAQTA1_y = -99.99;
  DetAQTA1_z = -99.99;

  //momentum info
  
  DetAQTA1_Px = -99.99;
  DetAQTA1_Py = -99.99;
  DetAQTA1_Pz = -99.99;

  //timing info

  DetAQTA1_t = -99.99;

  //track, particle ID, event ID info

  DetAQTA1_PDGid = -100;
  DetAQTA1_EventID = -100;
  DetAQTA1_TrackID = -100;
  
 //the virtual detector at between QTB1 & QTB2 in the beamline

  //spatial info
 
  DetAQTB1_x = -99.99;
  DetAQTB1_y = -99.99;
  DetAQTB1_z = -99.99;

  //momentum info
  
  DetAQTB1_Px = -99.99;
  DetAQTB1_Py = -99.99;
  DetAQTB1_Pz = -99.99;

  //timing info

  DetAQTB1_t = -99.99;

  //track, particle ID, event ID info

  DetAQTB1_PDGid = -100;
  DetAQTB1_EventID = -100;
  DetAQTB1_TrackID = -100;

 //the virtual detector at end of QTB2 in the beamline

  //spatial info
 
  DetAQTB2_x = -99.99;
  DetAQTB2_y = -99.99;
  DetAQTB2_z = -99.99;

  //momentum info
  
  DetAQTB2_Px = -99.99;
  DetAQTB2_Py = -99.99;
  DetAQTB2_Pz = -99.99;

  //timing info

  DetAQTB2_t = -99.99;

  //track, particle ID, event ID info

  DetAQTB2_PDGid = -100;
  DetAQTB2_EventID = -100;
  DetAQTB2_TrackID = -100;
  
  //the 2nd virtual detector in the beamline

  //spatial info
 
  Det1_x = -99.99;
  Det1_y = -99.99;
  Det1_z = -99.99;

  //momentum info
  
  Det1_Px = -99.99;
  Det1_Py = -99.99;
  Det1_Pz = -99.99;

  //timing info

  Det1_t = -99.99;

  //track, particle ID, event ID info

  Det1_PDGid = -100;
  Det1_EventID = -100;
  Det1_TrackID = -100;
  
  //the 3rd virtual detector in the beamline

  //spatial info
 
  Det2_x = -99.99;
  Det2_y = -99.99;
  Det2_z = -99.99;

  //momentum info
  
  Det2_Px = -99.99;
  Det2_Py = -99.99;
  Det2_Pz = -99.99;

  //timing info

  Det2_t = -99.99;

  //track, particle ID, event ID info

  Det2_PDGid = -100;
  Det2_EventID = -100;
  Det2_TrackID = -100;

  ///// The virtual detector at the IFP ////////////////////////////

  //spatial info
 
  Det3_x = -99.99;
  Det3_y = -99.99;
  Det3_z = -99.99;

  //momentum info
  
  Det3_Px = -99.99;
  Det3_Py = -99.99;
  Det3_Pz = -99.99;

  //timing info

  Det3_t = -99.99;

  //track, particle ID, event ID info

  Det3_PDGid = -100;
  Det3_EventID = -100;
  Det3_TrackID = -100;
  
  
  ///// The 4th virtual detector ////////////////////////////

  //spatial info
 
  Det4_x = -99.99;
  Det4_y = -99.99;
  Det4_z = -99.99;

  //momentum info
  
  Det4_Px = -99.99;
  Det4_Py = -99.99;
  Det4_Pz = -99.99;

  //timing info

  Det4_t = -99.99;

  //track, particle ID, event ID info

  Det4_PDGid = -100;
  Det4_EventID = -100;
  Det4_TrackID = -100;
  
  ///// The 5th virtual detector ////////////////////////////

  //spatial info
 
  Det5_x = -99.99;
  Det5_y = -99.99;
  Det5_z = -99.99;

  //momentum info
  
  Det5_Px = -99.99;
  Det5_Py = -99.99;
  Det5_Pz = -99.99;

  //timing info

  Det5_t = -99.99;

  //track, particle ID, event ID info

  Det5_PDGid = -100;
  Det5_EventID = -100;
  Det5_TrackID = -100;
  
  /////////// The virtual detector at the target ///////////////

  //spatial info
 
  DetTar_x = -99.99;
  DetTar_y = -99.99;
  DetTar_z = -99.99;

  //momentum info
  
  DetTar_Px = -99.99;
  DetTar_Py = -99.99;
  DetTar_Pz = -99.99;

  //timing info

  DetTar_t = -99.99;

  //track, particle ID, event ID info

  DetTar_PDGid = -100;
  DetTar_EventID = -100;
  DetTar_TrackID = -100;
  
  //# entries at PiM1 Tar
  
  nentries_Tar = 1;

}
