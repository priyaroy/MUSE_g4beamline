///////////////////////////////////////////////////
// Read the data from the branches of the root file
///////////////////////////////////////////////////

#include <iostream>
#include "TTree.h"
#include "variable.h"

using namespace std;

void setBranches()
{
  //if bname="*", apply to all branches
  // 0 means that the branch will not be processed

  //Set branch status
  
  cerr<<endl<<"Setting branch status"<<endl;
  
  //All branches are read by default?
  
  tree0->SetBranchStatus("x", 1);
  tree0->SetBranchStatus("y", 1);
  tree0->SetBranchStatus("z", 1);
  tree0->SetBranchStatus("Px", 1);
  tree0->SetBranchStatus("Py", 1);
  tree0->SetBranchStatus("Pz", 1);
  tree0->SetBranchStatus("t", 1);
  tree0->SetBranchStatus("PDGid", 1);
  tree0->SetBranchStatus("EventID", 1);
  tree0->SetBranchStatus("TrackID", 1);
 
  tree0a->SetBranchStatus("x", 1);
  tree0a->SetBranchStatus("y", 1);
  tree0a->SetBranchStatus("z", 1);
  tree0a->SetBranchStatus("Px", 1);
  tree0a->SetBranchStatus("Py", 1);
  tree0a->SetBranchStatus("Pz", 1);
  tree0a->SetBranchStatus("t", 1);
  tree0a->SetBranchStatus("PDGid", 1);
  tree0a->SetBranchStatus("EventID", 1);
  tree0a->SetBranchStatus("TrackID", 1);
  
  treeAQTA1->SetBranchStatus("x", 1);
  treeAQTA1->SetBranchStatus("y", 1);
  treeAQTA1->SetBranchStatus("z", 1);
  treeAQTA1->SetBranchStatus("Px", 1);
  treeAQTA1->SetBranchStatus("Py", 1);
  treeAQTA1->SetBranchStatus("Pz", 1);
  treeAQTA1->SetBranchStatus("t", 1);
  treeAQTA1->SetBranchStatus("PDGid", 1);
  treeAQTA1->SetBranchStatus("EventID", 1);
  treeAQTA1->SetBranchStatus("TrackID", 1);
  
  treeAQTB1->SetBranchStatus("x", 1);
  treeAQTB1->SetBranchStatus("y", 1);
  treeAQTB1->SetBranchStatus("z", 1);
  treeAQTB1->SetBranchStatus("Px", 1);
  treeAQTB1->SetBranchStatus("Py", 1);
  treeAQTB1->SetBranchStatus("Pz", 1);
  treeAQTB1->SetBranchStatus("t", 1);
  treeAQTB1->SetBranchStatus("PDGid", 1);
  treeAQTB1->SetBranchStatus("EventID", 1);
  treeAQTB1->SetBranchStatus("TrackID", 1);

  treeAQTB2->SetBranchStatus("x", 1);
  treeAQTB2->SetBranchStatus("y", 1);
  treeAQTB2->SetBranchStatus("z", 1);
  treeAQTB2->SetBranchStatus("Px", 1);
  treeAQTB2->SetBranchStatus("Py", 1);
  treeAQTB2->SetBranchStatus("Pz", 1);
  treeAQTB2->SetBranchStatus("t", 1);
  treeAQTB2->SetBranchStatus("PDGid", 1);
  treeAQTB2->SetBranchStatus("EventID", 1);
  treeAQTB2->SetBranchStatus("TrackID", 1);
  
  tree1->SetBranchStatus("x", 1);
  tree1->SetBranchStatus("y", 1);
  tree1->SetBranchStatus("z", 1);
  tree1->SetBranchStatus("Px", 1);
  tree1->SetBranchStatus("Py", 1);
  tree1->SetBranchStatus("Pz", 1);
  tree1->SetBranchStatus("t", 1);
  tree1->SetBranchStatus("PDGid", 1);
  tree1->SetBranchStatus("EventID", 1);
  tree1->SetBranchStatus("TrackID", 1);
  
  tree2->SetBranchStatus("x", 1);
  tree2->SetBranchStatus("y", 1);
  tree2->SetBranchStatus("z", 1);
  tree2->SetBranchStatus("Px", 1);
  tree2->SetBranchStatus("Py", 1);
  tree2->SetBranchStatus("Pz", 1);
  tree2->SetBranchStatus("t", 1);
  tree2->SetBranchStatus("PDGid", 1);
  tree2->SetBranchStatus("EventID", 1);
  tree2->SetBranchStatus("TrackID", 1);
  
  tree3->SetBranchStatus("x", 1);
  tree3->SetBranchStatus("y", 1);
  tree3->SetBranchStatus("z", 1);
  tree3->SetBranchStatus("Px", 1);
  tree3->SetBranchStatus("Py", 1);
  tree3->SetBranchStatus("Pz", 1);
  tree3->SetBranchStatus("t", 1);
  tree3->SetBranchStatus("PDGid", 1);
  tree3->SetBranchStatus("EventID", 1);
  tree3->SetBranchStatus("TrackID", 1);
  
  tree4->SetBranchStatus("x", 1);
  tree4->SetBranchStatus("y", 1);
  tree4->SetBranchStatus("z", 1);
  tree4->SetBranchStatus("Px", 1);
  tree4->SetBranchStatus("Py", 1);
  tree4->SetBranchStatus("Pz", 1);
  tree4->SetBranchStatus("t", 1);
  tree4->SetBranchStatus("PDGid", 1);
  tree4->SetBranchStatus("EventID", 1);
  tree4->SetBranchStatus("TrackID", 1);
  
  tree5->SetBranchStatus("x", 1);
  tree5->SetBranchStatus("y", 1);
  tree5->SetBranchStatus("z", 1);
  tree5->SetBranchStatus("Px", 1);
  tree5->SetBranchStatus("Py", 1);
  tree5->SetBranchStatus("Pz", 1);
  tree5->SetBranchStatus("t", 1);
  tree5->SetBranchStatus("PDGid", 1);
  tree5->SetBranchStatus("EventID", 1);
  tree5->SetBranchStatus("TrackID", 1);
  
  treeTar->SetBranchStatus("x", 1);
  treeTar->SetBranchStatus("y", 1);
  treeTar->SetBranchStatus("z", 1);
  treeTar->SetBranchStatus("Px", 1);
  treeTar->SetBranchStatus("Py", 1);
  treeTar->SetBranchStatus("Pz", 1);
  treeTar->SetBranchStatus("t", 1);
  treeTar->SetBranchStatus("PDGid", 1);
  treeTar->SetBranchStatus("EventID", 1);
  treeTar->SetBranchStatus("TrackID", 1);
  /*
  tree0->SetBranchStatus("*",1);
  tree3->SetBranchStatus("*",1);
  treeTar->SetBranchStatus("*",1);
*/
  cerr<<endl<<"finished setting branch status"<<endl;

  //Set branch addresses

  tree0->SetBranchAddress("x", &Det0_x);
  tree0->SetBranchAddress("y", &Det0_y);
  tree0->SetBranchAddress("z", &Det0_z);
  tree0->SetBranchAddress("Px", &Det0_Px);
  tree0->SetBranchAddress("Py", &Det0_Py);
  tree0->SetBranchAddress("Pz", &Det0_Pz);
  tree0->SetBranchAddress("t", &Det0_t);
  tree0->SetBranchAddress("PDGid", &Det0_PDGid);
  tree0->SetBranchAddress("EventID", &Det0_EventID);
  tree0->SetBranchAddress("TrackID", &Det0_TrackID);
  
  tree0a->SetBranchAddress("x", &Det0a_x);
  tree0a->SetBranchAddress("y", &Det0a_y);
  tree0a->SetBranchAddress("z", &Det0a_z);
  tree0a->SetBranchAddress("Px", &Det0a_Px);
  tree0a->SetBranchAddress("Py", &Det0a_Py);
  tree0a->SetBranchAddress("Pz", &Det0a_Pz);
  tree0a->SetBranchAddress("t", &Det0a_t);
  tree0a->SetBranchAddress("PDGid", &Det0a_PDGid);
  tree0a->SetBranchAddress("EventID", &Det0a_EventID);
  tree0a->SetBranchAddress("TrackID", &Det0a_TrackID);
  
  treeAQTA1->SetBranchAddress("x", &DetAQTA1_x);
  treeAQTA1->SetBranchAddress("y", &DetAQTA1_y);
  treeAQTA1->SetBranchAddress("z", &DetAQTA1_z);
  treeAQTA1->SetBranchAddress("Px", &DetAQTA1_Px);
  treeAQTA1->SetBranchAddress("Py", &DetAQTA1_Py);
  treeAQTA1->SetBranchAddress("Pz", &DetAQTA1_Pz);
  treeAQTA1->SetBranchAddress("t", &DetAQTA1_t);
  treeAQTA1->SetBranchAddress("PDGid", &DetAQTA1_PDGid);
  treeAQTA1->SetBranchAddress("EventID", &DetAQTA1_EventID);
  treeAQTA1->SetBranchAddress("TrackID", &DetAQTA1_TrackID);
  
  treeAQTB1->SetBranchAddress("x", &DetAQTB1_x);
  treeAQTB1->SetBranchAddress("y", &DetAQTB1_y);
  treeAQTB1->SetBranchAddress("z", &DetAQTB1_z);
  treeAQTB1->SetBranchAddress("Px", &DetAQTB1_Px);
  treeAQTB1->SetBranchAddress("Py", &DetAQTB1_Py);
  treeAQTB1->SetBranchAddress("Pz", &DetAQTB1_Pz);
  treeAQTB1->SetBranchAddress("t", &DetAQTB1_t);
  treeAQTB1->SetBranchAddress("PDGid", &DetAQTB1_PDGid);
  treeAQTB1->SetBranchAddress("EventID", &DetAQTB1_EventID);
  treeAQTB1->SetBranchAddress("TrackID", &DetAQTB1_TrackID);
  
  treeAQTB2->SetBranchAddress("x", &DetAQTB2_x);
  treeAQTB2->SetBranchAddress("y", &DetAQTB2_y);
  treeAQTB2->SetBranchAddress("z", &DetAQTB2_z);
  treeAQTB2->SetBranchAddress("Px", &DetAQTB2_Px);
  treeAQTB2->SetBranchAddress("Py", &DetAQTB2_Py);
  treeAQTB2->SetBranchAddress("Pz", &DetAQTB2_Pz);
  treeAQTB2->SetBranchAddress("t", &DetAQTB2_t);
  treeAQTB2->SetBranchAddress("PDGid", &DetAQTB2_PDGid);
  treeAQTB2->SetBranchAddress("EventID", &DetAQTB2_EventID);
  treeAQTB2->SetBranchAddress("TrackID", &DetAQTB2_TrackID);
  
  tree1->SetBranchAddress("x", &Det1_x);
  tree1->SetBranchAddress("y", &Det1_y);
  tree1->SetBranchAddress("z", &Det1_z);
  tree1->SetBranchAddress("Px", &Det1_Px);
  tree1->SetBranchAddress("Py", &Det1_Py);
  tree1->SetBranchAddress("Pz", &Det1_Pz);
  tree1->SetBranchAddress("t", &Det1_t);
  tree1->SetBranchAddress("PDGid", &Det1_PDGid);
  tree1->SetBranchAddress("EventID", &Det1_EventID);
  tree1->SetBranchAddress("TrackID", &Det1_TrackID);
  
  tree2->SetBranchAddress("x", &Det2_x);
  tree2->SetBranchAddress("y", &Det2_y);
  tree2->SetBranchAddress("z", &Det2_z);
  tree2->SetBranchAddress("Px", &Det2_Px);
  tree2->SetBranchAddress("Py", &Det2_Py);
  tree2->SetBranchAddress("Pz", &Det2_Pz);
  tree2->SetBranchAddress("t", &Det2_t);
  tree2->SetBranchAddress("PDGid", &Det2_PDGid);
  tree2->SetBranchAddress("EventID", &Det2_EventID);
  tree2->SetBranchAddress("TrackID", &Det2_TrackID);

  tree3->SetBranchAddress("x", &Det3_x);
  tree3->SetBranchAddress("y", &Det3_y);
  tree3->SetBranchAddress("z", &Det3_z);
  tree3->SetBranchAddress("Px", &Det3_Px);
  tree3->SetBranchAddress("Py", &Det3_Py);
  tree3->SetBranchAddress("Pz", &Det3_Pz);
  tree3->SetBranchAddress("t", &Det3_t);
  tree3->SetBranchAddress("PDGid", &Det3_PDGid);
  tree3->SetBranchAddress("EventID", &Det3_EventID);
  tree3->SetBranchAddress("TrackID", &Det3_TrackID);

  tree4->SetBranchAddress("x", &Det4_x);
  tree4->SetBranchAddress("y", &Det4_y);
  tree4->SetBranchAddress("z", &Det4_z);
  tree4->SetBranchAddress("Px", &Det4_Px);
  tree4->SetBranchAddress("Py", &Det4_Py);
  tree4->SetBranchAddress("Pz", &Det4_Pz);
  tree4->SetBranchAddress("t", &Det4_t);
  tree4->SetBranchAddress("PDGid", &Det4_PDGid);
  tree4->SetBranchAddress("EventID", &Det4_EventID);
  tree4->SetBranchAddress("TrackID", &Det4_TrackID);
  
  tree5->SetBranchAddress("x", &Det5_x);
  tree5->SetBranchAddress("y", &Det5_y);
  tree5->SetBranchAddress("z", &Det5_z);
  tree5->SetBranchAddress("Px", &Det5_Px);
  tree5->SetBranchAddress("Py", &Det5_Py);
  tree5->SetBranchAddress("Pz", &Det5_Pz);
  tree5->SetBranchAddress("t", &Det5_t);
  tree5->SetBranchAddress("PDGid", &Det5_PDGid);
  tree5->SetBranchAddress("EventID", &Det5_EventID);
  tree5->SetBranchAddress("TrackID", &Det5_TrackID);
  
cerr<<endl<<"Reading treeTar variables"<<endl;

  treeTar->SetBranchAddress("x", &DetTar_x);
  treeTar->SetBranchAddress("y", &DetTar_y);
  treeTar->SetBranchAddress("z", &DetTar_z);
  treeTar->SetBranchAddress("Px", &DetTar_Px);
  treeTar->SetBranchAddress("Py", &DetTar_Py);
  treeTar->SetBranchAddress("Pz", &DetTar_Pz);
  treeTar->SetBranchAddress("t", &DetTar_t);
  treeTar->SetBranchAddress("PDGid", &DetTar_PDGid);
  treeTar->SetBranchAddress("EventID", &DetTar_EventID);
  treeTar->SetBranchAddress("TrackID", &DetTar_TrackID);  
  
}
