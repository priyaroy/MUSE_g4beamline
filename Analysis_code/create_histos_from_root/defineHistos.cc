/////////////////////////////////////////////
// Histograms are defined and created here.
/////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include "TH1.h"
#include "TH2.h"
#include "TROOT.h"
#include "TStyle.h"  //for sStyle
#include "TFile.h"   //for outFile
#include "TGraph.h"
#include "defineHistos.h"
#include "variable.h"

using namespace std;

void defineHistos()
{

  ////////////////Spatial distributions, 1-D

  //in X
  sprintf(name,"xDet0");
  xDet0 = new TH1F(name,name,30,-0.15,0.15);
  xDet0->GetXaxis()->SetTitle("x_ProdTar (cm)");
  
  sprintf(name,"xDet0a");
  xDet0a = new TH1F(name,name,100,-2.5,2.5);
  xDet0a->GetXaxis()->SetTitle("x_startQTA1 (cm)");

  sprintf(name,"xDetAQTA1");
  xDetAQTA1 = new TH1F(name,name,80,-4,4);
  xDetAQTA1->GetXaxis()->SetTitle("x_btw_QTA1_QTB1 (cm)");
  
  sprintf(name,"xDetAQTB1");
  xDetAQTB1 = new TH1F(name,name,80,-8,8);
  xDetAQTB1->GetXaxis()->SetTitle("x_btw_QTB1_QTB2 (cm)");
  
  sprintf(name,"xDetAQTB2");
  xDetAQTB2 = new TH1F(name,name,100,-10,10);
  xDetAQTB2->GetXaxis()->SetTitle("x_endQTB2 (cm)");
  
  sprintf(name,"xDet1");
  xDet1 = new TH1F(name,name,300,-23,34);
  xDet1->GetXaxis()->SetTitle("x_startDipole1 (cm)");
  
  sprintf(name,"xDet2");
  xDet2 = new TH1F(name,name,100,-15,10);
  xDet2->GetXaxis()->SetTitle("x_endDipole1 (cm)");
  
  sprintf(name,"xDet3");
  xDet3 = new TH1F(name,name,24,-2,2);
  xDet3->GetXaxis()->SetTitle("x_IFP (cm)");

  sprintf(name,"xDet4");
  xDet4 = new TH1F(name,name,500,-8,8);
  xDet4->GetXaxis()->SetTitle("x_startDipole2 (cm)");
  
  sprintf(name,"xDet5");
  xDet5 = new TH1F(name,name,500,-8,8);
  xDet5->GetXaxis()->SetTitle("x_endDipole2 (cm)");
  
  sprintf(name,"xDetTar");
  xDetTar = new TH1F(name,name,25,-5,5);
  xDetTar->GetXaxis()->SetTitle("x_PiM1Tar (cm)");

  //in y
  sprintf(name,"yDet0");
  yDet0 = new TH1F(name,name,60,-0.3,0.3);
  yDet0->GetXaxis()->SetTitle("y_ProdTar (cm)");
  
  sprintf(name,"yDet0a");
  yDet0a = new TH1F(name,name,150,-15,15);
  yDet0a->GetXaxis()->SetTitle("y_startQTA1 (cm)");

  sprintf(name,"yDetAQTA1");
  yDetAQTA1 = new TH1F(name,name,100,-6.5,6.5);
  yDetAQTA1->GetXaxis()->SetTitle("y_btw_QTA1_QTB1 (cm)");
  
  sprintf(name,"yDetAQTB1");
  yDetAQTB1 = new TH1F(name,name,65,-6.5,6.5);
  yDetAQTB1->GetXaxis()->SetTitle("y_btw_QTB1_QTB2 (cm)");
  
  sprintf(name,"yDetAQTB2");
  yDetAQTB2 = new TH1F(name,name,50,-5,5);
  yDetAQTB2->GetXaxis()->SetTitle("y_endQTB2 (cm)");
  
  sprintf(name,"yDet1");
  yDet1 = new TH1F(name,name,100,-10,10);
  yDet1->GetXaxis()->SetTitle("y_startDipole1 (cm)");

  sprintf(name,"yDet2");
  yDet2 = new TH1F(name,name,42,-4.2,4.2);
  yDet2->GetXaxis()->SetTitle("y_endDipole1 (cm)");
  
  sprintf(name,"yDet3");
  yDet3 = new TH1F(name,name, 24,-2,2);
  yDet3->GetXaxis()->SetTitle("y_IFP (cm)");
  
  sprintf(name,"yDet4");
  yDet4 = new TH1F(name,name, 600,-3,3);
  yDet4->GetXaxis()->SetTitle("y_startDipole2 (cm)");

  sprintf(name,"yDet5");
  yDet5 = new TH1F(name,name, 600,-3,3);
  yDet5->GetXaxis()->SetTitle("y_endDipole2 (cm)");
  
  sprintf(name,"yDetTar");
  yDetTar = new TH1F(name,name,30,-5, 5);
  yDetTar->GetXaxis()->SetTitle("y_PiM1Tar (cm)");
  
   ////////////////angle distributions, 1-D

  //in X
  sprintf(name,"pxDet0");
  pxDet0 = new TH1F(name,name,50,-25,25);
  pxDet0->GetXaxis()->SetTitle("xprime_ProdTar (mrad)");
  
  sprintf(name,"pxDet0a");
  pxDet0a = new TH1F(name,name,44,-22,22);
  pxDet0a->GetXaxis()->SetTitle("xprime_startQTA1 (mrad)");

  sprintf(name,"pxDetAQTA1");
  pxDetAQTA1 = new TH1F(name,name,140,-70,70);
  pxDetAQTA1->GetXaxis()->SetTitle("xprime_btw_QTA1_QTB1 (mrad)");
  
  sprintf(name,"pxDetAQTB1");
  pxDetAQTB1 = new TH1F(name,name,100,-90,90);
  pxDetAQTB1->GetXaxis()->SetTitle("xprime_btw_QTB1_QTB2 (mrad)");
  
  sprintf(name,"pxDetAQTB2");
  pxDetAQTB2 = new TH1F(name,name,55,-1.1,1.1);
  pxDetAQTB2->GetXaxis()->SetTitle("xprime_endQTB2 (mrad)");
  
  sprintf(name,"pxDet1");
  pxDet1 = new TH1F(name,name,340,-34,34);
  pxDet1->GetXaxis()->SetTitle("xprime_startDipole1 (mrad)");
  
  sprintf(name,"pxDet2");
  pxDet2 = new TH1F(name,name,100,-100,100);
  pxDet2->GetXaxis()->SetTitle("xprime_endDipole1 (mrad)");
  
  sprintf(name,"pxDet3");
  pxDet3 = new TH1F(name,name,40,-40,40);
  pxDet3->GetXaxis()->SetTitle("xprime_IFP (mrad)");

  sprintf(name,"pxDet4");
  pxDet4 = new TH1F(name,name,1500,-70,70);
  pxDet4->GetXaxis()->SetTitle("xprime_startDipole2 (mrad)");
  
  sprintf(name,"pxDet5");
  pxDet5 = new TH1F(name,name,1500,-70,70);
  pxDet5->GetXaxis()->SetTitle("xprime_endDipole2 (mrad)");
  
  sprintf(name,"pxDetTar");
  pxDetTar = new TH1F(name,name,25,-100,100);
  pxDetTar->GetXaxis()->SetTitle("xprime_PiM1Tar (mrad)");

  //in y
  sprintf(name,"pyDet0");
  pyDet0 = new TH1F(name,name,130,-130,130);
  pyDet0->GetXaxis()->SetTitle("yprime_ProdTar (mrad)");
  
  sprintf(name,"pyDet0a");
  pyDet0a = new TH1F(name,name,65,-130,130);
  pyDet0a->GetXaxis()->SetTitle("yprime_startQTA1 (mrad)");

  sprintf(name,"pyDetAQTA1");
  pyDetAQTA1 = new TH1F(name,name,100,-10,10);
  pyDetAQTA1->GetXaxis()->SetTitle("yprime_btw_QTA1_QTB1 (mrad)");
  
  sprintf(name,"pyDetAQTB1");
  pyDetAQTB1 = new TH1F(name,name,65,-65,65);
  pyDetAQTB1->GetXaxis()->SetTitle("yprime_btw_QTB1_QTB2 (mrad)");
  
  sprintf(name,"pyDetAQTB2");
  pyDetAQTB2 = new TH1F(name,name,48,-12,12);
  pyDetAQTB2->GetXaxis()->SetTitle("yprime_endQTB2 (mrad)");
  
  sprintf(name,"pyDet1");
  pyDet1 = new TH1F(name,name,340,-34,34);
  pyDet1->GetXaxis()->SetTitle("yprime_startDipole1 (mrad)");
  
  sprintf(name,"pyDet2");
  pyDet2 = new TH1F(name,name,200,-20,20);
  pyDet2->GetXaxis()->SetTitle("yprime_endDipole1 (mrad)");
  
  sprintf(name,"pyDet3");
  pyDet3 = new TH1F(name,name,30,-60, 30);
  pyDet3->GetXaxis()->SetTitle("yprime_IFP (mrad)");

  sprintf(name,"pyDet4");
  pyDet4 = new TH1F(name,name,1600,-80,80);
  pyDet4->GetXaxis()->SetTitle("yprime_startDipole2 (mrad)");
  
  sprintf(name,"pyDet5");
  pyDet5 = new TH1F(name,name,1600,-80,80);
  pyDet5->GetXaxis()->SetTitle("yprime_endDipole2 (mrad)");
  
  sprintf(name,"pyDetTar");
  pyDetTar = new TH1F(name,name,50,-100,100);
  pyDetTar->GetXaxis()->SetTitle("yprime_PiM1Tar (mrad)");
  
  
  //total P (MeV) (mag.)
  sprintf(name,"pDet0");
  pDet0 = new TH1F(name,name,500, 150, 160);
  pDet0->GetXaxis()->SetTitle("P_ProdTar (MeV)");
  
  sprintf(name,"pDet0a");
  pDet0a = new TH1F(name,name,500,150, 160);
  pDet0a->GetXaxis()->SetTitle("P_startQTA1 (MeV)");

  sprintf(name,"pDetAQTA1");
  pDetAQTA1 = new TH1F(name,name,500,150, 160);
  pDetAQTA1->GetXaxis()->SetTitle("P_btw_QTA1_QTB1 (MeV)");
  
  sprintf(name,"pDetAQTB1");
  pDetAQTB1 = new TH1F(name,name,500,150, 160);
  pDetAQTB1->GetXaxis()->SetTitle("P_btw_QTB1_QTB2 (MeV)");
  
  sprintf(name,"pDetAQTB2");
  pDetAQTB2 = new TH1F(name,name,500,150, 160);
  pDetAQTB2->GetXaxis()->SetTitle("P_endQTB2 (MeV)");
  
  sprintf(name,"pDet1");
  pDet1 = new TH1F(name,name,500,150, 160);
  pDet1->GetXaxis()->SetTitle("P_startDipole1 (MeV)");
  
  sprintf(name,"pDet2");
  pDet2 = new TH1F(name,name,500,150, 160);
  pDet2->GetXaxis()->SetTitle("P_endDipole1 (MeV)");
  
  sprintf(name,"pDet3");
  pDet3 = new TH1F(name,name,500,150, 160);
  pDet3->GetXaxis()->SetTitle("P_IFP (MeV)");

  sprintf(name,"pDet4");
  pDet4 = new TH1F(name,name,500, 150, 160);
  pDet4->GetXaxis()->SetTitle("P_startDipole2 (MeV)");
  
  sprintf(name,"pDet5");
  pDet5 = new TH1F(name,name,500,150, 160);
  pDet5->GetXaxis()->SetTitle("P_endDipole2 (MeV)");
  
  sprintf(name,"pDetTar");
  pDetTar = new TH1F(name,name,500,150, 160);
  pDetTar->GetXaxis()->SetTitle("P_PiM1Tar (MeV)");
  
  //Delta P (percent)
  sprintf(name,"dpDet0");
  dpDet0 = new TH1F(name,name,50, -1.7, 1.7);
  dpDet0->GetXaxis()->SetTitle("dP_ProdTar (%)");
  
  sprintf(name,"dpDet0a");
  dpDet0a = new TH1F(name,name,50,-1.7,1.7);
  dpDet0a->GetXaxis()->SetTitle("dP_startQTA1 (%)");

  sprintf(name,"dpDetAQTA1");
  dpDetAQTA1 = new TH1F(name,name,50,-1.7, 1.7);
  dpDetAQTA1->GetXaxis()->SetTitle("dP_btw_QTA1_QTB1 (%)");
  
  sprintf(name,"dpDetAQTB1");
  dpDetAQTB1 = new TH1F(name,name,50,-1.7,1.7);
  dpDetAQTB1->GetXaxis()->SetTitle("dP_btw_QTB1_QTB2 (%)");
  
  sprintf(name,"dpDetAQTB2");
  dpDetAQTB2 = new TH1F(name,name,50,-1.7,1.7);
  dpDetAQTB2->GetXaxis()->SetTitle("dP_endQTB2 (%)");
  
  sprintf(name,"dpDet1");
  dpDet1 = new TH1F(name,name,50,-5.2,2.1);
  dpDet1->GetXaxis()->SetTitle("dP_startDipole1 (%)");
  
  sprintf(name,"dpDet2");
  dpDet2 = new TH1F(name,name,50,-5.2,2.1);
  dpDet2->GetXaxis()->SetTitle("dP_endDipole1 (%)");
  
  sprintf(name,"dpDet3");
  dpDet3 = new TH1F(name,name,170,-1.7,1.7);
  dpDet3->GetXaxis()->SetTitle("dP_IFP (%)");

  sprintf(name,"dpDet4");
  dpDet4 = new TH1F(name,name,200,-2,2);
  dpDet4->GetXaxis()->SetTitle("dP_startDipole2 (%)");
  
  sprintf(name,"dpDet5");
  dpDet5 = new TH1F(name,name,200,-2,2);
  dpDet5->GetXaxis()->SetTitle("dP_endDipole2 (%)");
  
  sprintf(name,"dpDetTar");
  dpDetTar = new TH1F(name,name,200,-2,2);
  dpDetTar->GetXaxis()->SetTitle("dP_PiM1Tar (%)");

  // Spatial distributions, 2-D
  sprintf(name,"beamspot_Det0");
  beamspot_Det0 = new TH2F(name, name,40,-0.2,0.2, 40,-0.2,0.2);
  beamspot_Det0->GetXaxis()->SetTitle("x_ProdTar (cm)");
  beamspot_Det0->GetYaxis()->SetTitle("y_ProdTar (cm)");
  
  sprintf(name,"beamspot_Det0a");
  beamspot_Det0a = new TH2F(name, name,35,-2.5,2.5, 150,-12,12);
  beamspot_Det0a->GetXaxis()->SetTitle("x_startQTA1 (cm)");
  beamspot_Det0a->GetYaxis()->SetTitle("y_startQTA1 (cm)");
  
  sprintf(name,"beamspot_DetAQTA1");
  beamspot_DetAQTA1 = new TH2F(name, name,20,-4,4, 50,-10,10);
  beamspot_DetAQTA1->GetXaxis()->SetTitle("x_btw_QTA1_QTB1 (cm)");
  beamspot_DetAQTA1->GetYaxis()->SetTitle("y_btw_QTA1_QTB1 (cm)");
  
  sprintf(name,"beamspot_DetAQTB1");
  beamspot_DetAQTB1 = new TH2F(name, name,100,-10,10, 35,-7,7);
  beamspot_DetAQTB1->GetXaxis()->SetTitle("x_btw_QTB1_QTB2 (cm)");
  beamspot_DetAQTB1->GetYaxis()->SetTitle("y_btw_QTB1_QTB2 (cm)");
  
  sprintf(name,"beamspot_DetAQTB2");
  beamspot_DetAQTB2 = new TH2F(name, name,100,-10,10,50,-5,5);
  beamspot_DetAQTB2->GetXaxis()->SetTitle("x_endQTB2 (cm)");
  beamspot_DetAQTB2->GetYaxis()->SetTitle("y_endQTB2 (cm)");
  
  sprintf(name,"beamspot_Det1");
  beamspot_Det1 = new TH2F(name, name,250,-22,34, 100,-10,10);
  beamspot_Det1->GetXaxis()->SetTitle("x_startDipole1 (cm)");
  beamspot_Det1->GetYaxis()->SetTitle("y_startDipole1 (cm)");
  
  sprintf(name,"beamspot_Det2");
  beamspot_Det2 = new TH2F(name, name,120,-15,10,40,-4,4);
  beamspot_Det2->GetXaxis()->SetTitle("x_endDipole1 (cm)");
  beamspot_Det2->GetYaxis()->SetTitle("y_endDipole1 (cm)");
  
  sprintf(name,"beamspot_Det3");
  beamspot_Det3 = new TH2F(name, name,60,-15,15, 30,-3,3);
  beamspot_Det3->GetXaxis()->SetTitle("x_IFP (cm)");
  beamspot_Det3->GetYaxis()->SetTitle("y_IFP (cm)");
  
  sprintf(name,"beamspot_Det4");
  beamspot_Det4 = new TH2F(name, name,5000,-8,8, 5000,-5,5);
  beamspot_Det4->GetXaxis()->SetTitle("x_startDipole2 (cm)");
  beamspot_Det4->GetYaxis()->SetTitle("y_startDipole2 (cm)");
  
  sprintf(name,"beamspot_Det5");
  beamspot_Det5 = new TH2F(name, name,5000,-8,8, 5000,-5,5);
  beamspot_Det5->GetXaxis()->SetTitle("x_endDipole2 (cm)");
  beamspot_Det5->GetYaxis()->SetTitle("y_endDipole2 (cm)");
  
  sprintf(name,"beamspot_DetTar");
  beamspot_DetTar = new TH2F(name, name,600,-6,6,80,-2,2);
  beamspot_DetTar->GetXaxis()->SetTitle("x_PiM1Tar (cm)");
  beamspot_DetTar->GetYaxis()->SetTitle("y_PiM1Tar (cm)");
  
  
  // Px-Py distributions, 2-D
  sprintf(name,"pxpy_Det0");
  pxpy_Det0 = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_Det0->GetXaxis()->SetTitle("Px_ProdTar (MeV)");
  pxpy_Det0->GetYaxis()->SetTitle("Py_ProdTar (MeV)");
  
  sprintf(name,"pxpy_Det0a");
  pxpy_Det0a = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_Det0a->GetXaxis()->SetTitle("Px_startQTA1 (MeV)");
  pxpy_Det0a->GetYaxis()->SetTitle("Py_startQTA1 (MeV)");
  
  sprintf(name,"pxpy_DetAQTA1");
  pxpy_DetAQTA1 = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_DetAQTA1->GetXaxis()->SetTitle("Px_btw_QTA1_QTB1 (MeV)");
  pxpy_DetAQTA1->GetYaxis()->SetTitle("Py_btw_QTA1_QTB1 (MeV)");
  
  sprintf(name,"pxpy_DetAQTB1");
 pxpy_DetAQTB1 = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_DetAQTB1->GetXaxis()->SetTitle("Px_btw_QTB1_QTB2 (MeV)");
  pxpy_DetAQTB1->GetYaxis()->SetTitle("Py_btw_QTB1_QTB2 (MeV)");
  
  sprintf(name,"pxpy_DetAQTB2");
  pxpy_DetAQTB2 = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_DetAQTB2->GetXaxis()->SetTitle("Px_endQTB2 (MeV)");
  pxpy_DetAQTB2->GetYaxis()->SetTitle("Py_endQTB2 (MeV)");
  
  sprintf(name,"pxpy_Det1");
  pxpy_Det1 = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_Det1->GetXaxis()->SetTitle("Px_startDipole1 (MeV)");
  pxpy_Det1->GetYaxis()->SetTitle("Py_startDipole1 (MeV)");
  
  sprintf(name,"pxpy_Det2");
 pxpy_Det2 = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_Det2->GetXaxis()->SetTitle("Px_endDipole1 (MeV)");
  pxpy_Det2->GetYaxis()->SetTitle("Py_endDipole1 (MeV)");
  
  sprintf(name,"pxpy_Det3");
  pxpy_Det3 = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_Det3->GetXaxis()->SetTitle("Px_IFP (MeV)");
  pxpy_Det3->GetYaxis()->SetTitle("Py_IFP (MeV)");
  
  sprintf(name,"pxpy_Det4");
  pxpy_Det4 = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_Det4->GetXaxis()->SetTitle("Px_startDipole2 (MeV)");
  pxpy_Det4->GetYaxis()->SetTitle("Py_startDipole2 (MeV)");
  
  sprintf(name,"pxpy_Det5");
  pxpy_Det5 = new TH2F(name, name,500,-1,1, 500,-1,1);
  pxpy_Det5->GetXaxis()->SetTitle("Px_endDipole2 (MeV)");
  pxpy_Det5->GetYaxis()->SetTitle("Py_endDipole2 (MeV)");
  
  sprintf(name,"pxpy_DetTar");
  pxpy_DetTar = new TH2F(name, name,600,-6,6,60,-0.6,0.6);
  pxpy_DetTar->GetXaxis()->SetTitle("Px_PiM1Tar (MeV)");
  pxpy_DetTar->GetYaxis()->SetTitle("Py_PiM1Tar (MeV)");
  
  /////////// Dispersion distributions, 2-D
  
  //xprime vs x

  sprintf(name,"xPx_Det0");
  xPx_Det0 = new TH2F(name, name,80,-0.2,0.2, 100,-25,25);
  xPx_Det0->GetXaxis()->SetTitle("x_ProdTar (cm)");
  xPx_Det0->GetYaxis()->SetTitle("xprime_ProdTar (mrad)");
  
  sprintf(name,"xPx_Det0a");
  xPx_Det0a = new TH2F(name, name,40,-2.2,2.2, 100,-25,25);
  xPx_Det0a->GetXaxis()->SetTitle("x_startQTA1 (cm)");
  xPx_Det0a->GetYaxis()->SetTitle("xprime_startQTA1 (mrad)");
  
  sprintf(name,"xPx_DetAQTA1");
  xPx_DetAQTA1 = new TH2F(name, name,80,-4,4, 168,-42,42);
  xPx_DetAQTA1->GetXaxis()->SetTitle("x_btw_QTA1_QTB1 (cm)");
  xPx_DetAQTA1->GetYaxis()->SetTitle("xprime_btw_QTA1_QTB1 (mrad)");
  
  sprintf(name,"xPx_DetAQTB1");
  xPx_DetAQTB1 = new TH2F(name, name,160,-8,8, 340,-85,85);
  xPx_DetAQTB1->GetXaxis()->SetTitle("x_btw_QTB1_QTB2 (cm)");
  xPx_DetAQTB1->GetYaxis()->SetTitle("xprime_btw_QTB1_QTB2 (mrad)");
  
  sprintf(name,"xPx_DetAQTB2");
  xPx_DetAQTB2 = new TH2F(name, name,170,-17,17,120,-3.5,3.5);
  xPx_DetAQTB2->GetXaxis()->SetTitle("x_end_QTB2 (cm)");
  xPx_DetAQTB2->GetYaxis()->SetTitle("xprime_end_QTB2 (mrad)");
  
  sprintf(name,"xPx_Det1");
  xPx_Det1 = new TH2F(name, name,80,-8,8, 100,-4,4);
  xPx_Det1->GetXaxis()->SetTitle("x_startDipole1 (cm)");
  xPx_Det1->GetYaxis()->SetTitle("xprime_startDipole1 (mrad)");
  
  sprintf(name,"xPx_Det2");
  xPx_Det2 = new TH2F(name, name,80,-10,9,85,-110,60);
  xPx_Det2->GetXaxis()->SetTitle("x_endDipole1 (cm)");
  xPx_Det2->GetYaxis()->SetTitle("xprime_endDipole1 (mrad)");
  
  sprintf(name,"xPx_Det3");
  xPx_Det3 = new TH2F(name, name,200,-20,20,60,-30,30);
  xPx_Det3->GetXaxis()->SetTitle("x_IFP (cm)");
  xPx_Det3->GetYaxis()->SetTitle("xprime_IFP (mrad)");
  
  sprintf(name,"xPx_Det4");
  xPx_Det4 = new TH2F(name, name,5000,-8,8, 2600,-130,130);
  xPx_Det4->GetXaxis()->SetTitle("x_startDipole2 (cm)");
  xPx_Det4->GetYaxis()->SetTitle("xprime_startDipole2 (mrad)");
  
  sprintf(name,"xPx_Det5");
  xPx_Det5 = new TH2F(name, name,5000,-8,8, 2600,-130,130);
  xPx_Det5->GetXaxis()->SetTitle("x_endDipole2 (cm)");
  xPx_Det5->GetYaxis()->SetTitle("xprime_endDipole2 (mrad)");
  
  sprintf(name,"xPx_DetTar");
  xPx_DetTar = new TH2F(name, name,50,-10,10,150,-30,30);
  xPx_DetTar->GetXaxis()->SetTitle("x_PiM1Tar (cm)");
  xPx_DetTar->GetYaxis()->SetTitle("xprime_PiM1Tar (mrad)");
  
  //yprime vs y

  sprintf(name,"yPy_Det0");
  yPy_Det0 = new TH2F(name, name,60,-0.3,0.3, 130,-130,130);
  yPy_Det0->GetXaxis()->SetTitle("y_ProdTar (cm)");
  yPy_Det0->GetYaxis()->SetTitle("yprime_ProdTar (mrad)");
  
  sprintf(name,"yPy_Det0a");
  yPy_Det0a = new TH2F(name, name,130,-13,13, 130,-130,130);
  yPy_Det0a->GetXaxis()->SetTitle("y_startQTA1 (cm)");
  yPy_Det0a->GetYaxis()->SetTitle("yprime_startQTA1 (mrad)");
  
  sprintf(name,"yPy_DetAQTA1");
  yPy_DetAQTA1 = new TH2F(name, name,100,-10,10, 100,-10,10);
  yPy_DetAQTA1->GetXaxis()->SetTitle("y_btw_QTA1_QTB1 (cm)");
  yPy_DetAQTA1->GetYaxis()->SetTitle("yprime_btw_QTA1_QTB1 (mrad)");
  
  sprintf(name,"yPy_DetAQTB1");
  yPy_DetAQTB1 = new TH2F(name, name,90,-9,9,800,-80,80);
  yPy_DetAQTB1->GetXaxis()->SetTitle("y_btw_QTB1_QTB2 (cm)");
  yPy_DetAQTB1->GetYaxis()->SetTitle("yprime_btw_QTB1_QTB2 (mrad)");
  
  sprintf(name,"yPy_DetAQTB2");
  yPy_DetAQTB2 = new TH2F(name, name,60,-6,6,150,-15,15);
  yPy_DetAQTB2->GetXaxis()->SetTitle("y_end_QTB2 (cm)");
  yPy_DetAQTB2->GetYaxis()->SetTitle("yprime_end_QTB2 (mrad)");
  
  sprintf(name,"yPy_Det1");
  yPy_Det1 = new TH2F(name, name,32,-3.2,3.2,300,-28,34);
  yPy_Det1->GetXaxis()->SetTitle("y_startDipole1 (cm)");
  yPy_Det1->GetYaxis()->SetTitle("yprime_startDipole1 (mrad)");
  
  sprintf(name,"yPy_Det2");
  yPy_Det2 = new TH2F(name, name,40,-4,4,200,-20,20);
  yPy_Det2->GetXaxis()->SetTitle("y_endDipole1 (cm)");
  yPy_Det2->GetYaxis()->SetTitle("yprime_endDipole1 (mrad)");
  
  sprintf(name,"yPy_Det3");
  yPy_Det3 = new TH2F(name, name,150,-5,5,90,-30,30);
  yPy_Det3->GetXaxis()->SetTitle("y_IFP (cm)");
  yPy_Det3->GetYaxis()->SetTitle("yprime_IFP (mrad)");
  
  sprintf(name,"yPy_Det4");
  yPy_Det4 = new TH2F(name, name,5000,-8,8, 1600,-80,80);
  yPy_Det4->GetXaxis()->SetTitle("y_startDipole2 (cm)");
  yPy_Det4->GetYaxis()->SetTitle("yprime_startDipole2 (mrad)");
  
  sprintf(name,"yPy_Det5");
  yPy_Det5 = new TH2F(name, name,5000,-8,8, 1600,-80,80);
  yPy_Det5->GetXaxis()->SetTitle("y_endDipole2 (cm)");
  yPy_Det5->GetYaxis()->SetTitle("yprime_endDipole2 (mrad)");
  
  sprintf(name,"yPy_DetTar");
  yPy_DetTar = new TH2F(name, name,100,-2,2,100,-100,100);
  yPy_DetTar->GetXaxis()->SetTitle("y_PiM1Tar (cm)");
  yPy_DetTar->GetYaxis()->SetTitle("yprime_PiM1Tar (mrad)");

// dp vs x
  sprintf(name,"dispersion_Det0");
  dispersion_Det0 = new TH2F(name, name,80,-0.15,0.15, 34,-1.7,1.7);
  dispersion_Det0->GetXaxis()->SetTitle("x_ProdTar (cm)");
  dispersion_Det0->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dispersion_Det0a");
  dispersion_Det0a = new TH2F(name, name,25,-2.5,2.5, 34,-1.7,1.7);
  dispersion_Det0a->GetXaxis()->SetTitle("x_startQTA1 (cm)");
  dispersion_Det0a->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dispersion_DetAQTA1");
  dispersion_DetAQTA1 = new TH2F(name, name,40,-4,4, 34,-1.7,1.7);
  dispersion_DetAQTA1->GetXaxis()->SetTitle("x_btw_QTA1_QTB1 (cm)");
  dispersion_DetAQTA1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dispersion_DetAQTB1");
  dispersion_DetAQTB1 = new TH2F(name, name,80,-8,8, 34,-1.7,1.7);
  dispersion_DetAQTB1->GetXaxis()->SetTitle("x_btw_QTB1_QTB2 (cm)");
  dispersion_DetAQTB1->GetYaxis()->SetTitle("dP (%)"); 
  
  sprintf(name,"dispersion_DetAQTB2");
  dispersion_DetAQTB2 = new TH2F(name, name,100,-12,12,34,-1.7,1.7);
  dispersion_DetAQTB2->GetXaxis()->SetTitle("x_endQTB2 (cm)");
  dispersion_DetAQTB2->GetYaxis()->SetTitle("dP (%)"); 
  
  sprintf(name,"dispersion_Det1");
  dispersion_Det1 = new TH2F(name, name,90,-9,9,70,-5,2);
  dispersion_Det1->GetXaxis()->SetTitle("x_startDipole1 (cm)");
  dispersion_Det1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dispersion_Det2");
  dispersion_Det2 = new TH2F(name, name,100,-10,9,72,-5.2,2);
  dispersion_Det2->GetXaxis()->SetTitle("x_endDipole1 (cm)");
  dispersion_Det2->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dispersion_DetIFP");
  dispersion_IFP = new TH2F(name, name,100,-10,10,34,-1.7,1.7);
  dispersion_IFP->GetXaxis()->SetTitle("x_IFP (cm)");
  dispersion_IFP->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dispersion_Det4");
  dispersion_Det4 = new TH2F(name, name,500,-10,10, 40,-2,2);
  dispersion_Det4->GetXaxis()->SetTitle("x_startDipole2 (cm)");
  dispersion_Det4->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dispersion_Det5");
  dispersion_Det5 = new TH2F(name, name,60,-6,5,34,-1.7,1.7);
  dispersion_Det5->GetXaxis()->SetTitle("x_endDipole2 (cm)");
  dispersion_Det5->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dispersion_Tar");
  dispersion_Tar = new TH2F(name, name,50,-10,10,34,-1.7,1.7);
  dispersion_Tar->GetXaxis()->SetTitle("x_PiM1Tar (cm)");
  dispersion_Tar->GetYaxis()->SetTitle("dP (%)");
  
  // dp vs xprime
  sprintf(name,"dpPx_Det0");
  dpPx_Det0 = new TH2F(name, name,100,-25,25, 34,-1.7,1.7);
  dpPx_Det0->GetXaxis()->SetTitle("xprime_ProdTar (mrad)");
  dpPx_Det0->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_Det0a");
  dpPx_Det0a = new TH2F(name, name,25,-25,25,17,-1.7,1.7);
  dpPx_Det0a->GetXaxis()->SetTitle("xprime_startQTA1 (mrad)");
  dpPx_Det0a->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_DetAQTA1");
  dpPx_DetAQTA1 = new TH2F(name, name,168,-42,42, 34,-1.7,1.7);
  dpPx_DetAQTA1->GetXaxis()->SetTitle("xprime_btw_QTA1_QTB1 (mrad)");
  dpPx_DetAQTA1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_DetAQTB1");
  dpPx_DetAQTB1 = new TH2F(name, name,80,-85,85, 34,-1.7,1.7);
  dpPx_DetAQTB1->GetXaxis()->SetTitle("xprime_btw_QTB1_QTB2 (mrad)");
  dpPx_DetAQTB1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_DetAQTB2");
  dpPx_DetAQTB2 = new TH2F(name, name,40,-4,4,34,-1.7,1.7);
  dpPx_DetAQTB2->GetXaxis()->SetTitle("xprime__end_QTB2 (mrad)");
  dpPx_DetAQTB2->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_Det1");
  dpPx_Det1 = new TH2F(name, name,500,-22,28,72,-5.2,2);
  dpPx_Det1->GetXaxis()->SetTitle("xprime_startDipole1 (mrad)");
  dpPx_Det1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_Det2");
  dpPx_Det2 = new TH2F(name, name,112,-120,60,72,-5.2,2);
  dpPx_Det2->GetXaxis()->SetTitle("xprime_endDipole1 (mrad)");
  dpPx_Det2->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_Det3");
  dpPx_Det3 = new TH2F(name, name,300,-30,30, 40,-2,2);
  dpPx_Det3->GetXaxis()->SetTitle("xprime_IFP (mrad)");
  dpPx_Det3->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_Det4");
  dpPx_Det4 = new TH2F(name, name,1200,-60,60, 40,-2,2);
  dpPx_Det4->GetXaxis()->SetTitle("xprime_startDipole2 (mrad)");
  dpPx_Det4->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_Det5");
  dpPx_Det5 = new TH2F(name, name,1200,-60,60, 40,-2,2);
  dpPx_Det5->GetXaxis()->SetTitle("xprime_endDipole2 (mrad)");
  dpPx_Det5->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPx_DetTar");
  dpPx_DetTar = new TH2F(name, name,300,-30,30,34,-1.7,1.7);
  dpPx_DetTar->GetXaxis()->SetTitle("xprime_PiM1Tar (mrad)");
  dpPx_DetTar->GetYaxis()->SetTitle("dP (%)");
  
  // dp vs y
  sprintf(name,"ydp_Det0");
  ydp_Det0 = new TH2F(name, name,44,-0.22,0.22, 34,-1.7,1.7);
  ydp_Det0->GetXaxis()->SetTitle("y_ProdTar (cm)");
  ydp_Det0->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"ydp_Det0a");
  ydp_Det0a = new TH2F(name, name,60,-12,12, 34,-1.7,1.7);
  ydp_Det0a->GetXaxis()->SetTitle("y_startQTA1 (cm)");
  ydp_Det0a->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"ydp_DetAQTA1");
  ydp_DetAQTA1 = new TH2F(name, name,50,-10,10, 34,-1.7,1.7);
  ydp_DetAQTA1->GetXaxis()->SetTitle("y_btw_QTA1_QTB1 (cm)");
  ydp_DetAQTA1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"ydp_DetAQTB1");
  ydp_DetAQTB1 = new TH2F(name, name,35,-6.5,6.5,34,-1.7,1.7);
  ydp_DetAQTB1->GetXaxis()->SetTitle("y_btw_QTB1_QTB2 (cm)");
  ydp_DetAQTB1->GetYaxis()->SetTitle("dP (%)"); 
  
  sprintf(name,"ydp_DetAQTB2");
  ydp_DetAQTB2 = new TH2F(name, name,100,-6,6,34,-1.7,1.7);
  ydp_DetAQTB2->GetXaxis()->SetTitle("y_endQTB2 (cm)");
  ydp_DetAQTB2->GetYaxis()->SetTitle("dP (%)"); 
  
  sprintf(name,"ydp_Det1");
  ydp_Det1 = new TH2F(name, name,64,-3.2,3.2,72,-5.2,2);
  ydp_Det1->GetXaxis()->SetTitle("y_startDipole1 (cm)");
  ydp_Det1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"ydp_Det2");
  ydp_Det2 = new TH2F(name, name,40,-4,4,72,-5.2,2);
  ydp_Det2->GetXaxis()->SetTitle("y_endDipole1 (cm)");
  ydp_Det2->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"ydp_DetIFP");
  ydp_Det3 = new TH2F(name, name,90,-3,3,34,-1.7,1.7);
  ydp_Det3->GetXaxis()->SetTitle("y_IFP (cm)");
  ydp_Det3->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"ydp_Det4");
  ydp_Det4 = new TH2F(name, name,500,-10,10, 40,-2,2);
  ydp_Det4->GetXaxis()->SetTitle("y_startDipole2 (cm)");
  ydp_Det4->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"ydp_Det5");
  ydp_Det5 = new TH2F(name, name,500,-10,10, 40,-2,2);
  ydp_Det5->GetXaxis()->SetTitle("x_endDipole2 (cm)");
  dispersion_Det5->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"ydp_DetTar");
  ydp_DetTar = new TH2F(name, name,80,-2,2,34,-1.7,1.7);
  ydp_DetTar->GetXaxis()->SetTitle("y_PiM1Tar (cm)");
  ydp_DetTar->GetYaxis()->SetTitle("dP (%)");
  
  // dp vs yprime
  sprintf(name,"dpPy_Det0");
  dpPy_Det0 = new TH2F(name, name,65,-130,130, 17,-1.7,1.7);
  dpPy_Det0->GetXaxis()->SetTitle("yprime_ProdTar (mrad)");
  dpPy_Det0->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_Det0a");
  dpPy_Det0a = new TH2F(name, name,65,-130,130, 17,-1.7,1.7);
  dpPy_Det0a->GetXaxis()->SetTitle("yprime_startQTA1 (mrad)");
  dpPy_Det0a->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_DetAQTA1");
  dpPy_DetAQTA1 = new TH2F(name, name,50,-12,12, 17,-1.7,1.7);
  dpPy_DetAQTA1->GetXaxis()->SetTitle("yprime_btw_QTA1_QTB1 (mrad)");
  dpPy_DetAQTA1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_DetAQTB1");
  dpPy_DetAQTB1 = new TH2F(name, name,65,-65,65,34,-1.7,1.7);
  dpPy_DetAQTB1->GetXaxis()->SetTitle("yprime_btw_QTB1_QTB2 (mrad)");
  dpPy_DetAQTB1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_DetAQTB2");
  dpPy_DetAQTB2 = new TH2F(name, name,120,-12,12,34,-1.7,1.7);
  dpPy_DetAQTB2->GetXaxis()->SetTitle("yprime_end_QTB2 (mrad)");
  dpPy_DetAQTB2->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_Det1");
  dpPy_Det1 = new TH2F(name, name,340,-28,34,72,-5.2,2);
  dpPy_Det1->GetXaxis()->SetTitle("yprime_startDipole1 (mrad)");
  dpPy_Det1->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_Det2");
  dpPy_Det2 = new TH2F(name, name,250,-20,20,72,-5.2,2);
  dpPy_Det2->GetXaxis()->SetTitle("yprime_endDipole1 (mrad)");
  dpPy_Det2->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_Det3");
  dpPy_Det3 = new TH2F(name, name,300,-30,30,34,-1.7,1.7);
  dpPy_Det3->GetXaxis()->SetTitle("yprime_IFP (mrad)");
  dpPy_Det3->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_Det4");
  dpPy_Det4 = new TH2F(name, name,1600,-80,80, 40,-2,2);
  dpPy_Det4->GetXaxis()->SetTitle("yprime_startDipole2 (mrad)");
  dpPy_Det4->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_Det5");
  dpPy_Det5 = new TH2F(name, name,1600,-80,80, 40,-2,2);
  dpPy_Det5->GetXaxis()->SetTitle("yprime_endDipole2 (mrad)");
  dpPy_Det5->GetYaxis()->SetTitle("dP (%)");
  
  sprintf(name,"dpPy_DetTar");
  dpPy_DetTar = new TH2F(name, name,400,-100,100,34,-1.7,1.7);
  dpPy_DetTar->GetXaxis()->SetTitle("yprime_PiM1Tar (mrad)");
  dpPy_DetTar->GetYaxis()->SetTitle("dP (%)");
  
  //Ethan summer 2018 data
  xifp__2 = new TH1D("xifp__2","xifp",150,-5,5);
  xifp__2->GetXaxis()->SetTitle("x_IFP (cm)");
  
  yifp__4 = new TH1D("yifp__4","yifp",150,-5,5);
  yifp__4->GetXaxis()->SetTitle("y_IFP (cm)");
  
  xtarg__1 = new TH1D("xtarg__1","xtarg",150,-5,5);
  xtarg__1->GetXaxis()->SetTitle("x_PiM1Tar (cm)");
  
  ytarg__3 = new TH1D("ytarg__3","ytarg",150,-5,5);
  ytarg__3->GetXaxis()->SetTitle("y_PiM1Tar (cm)");
  
  xpifp__6 = new TH1D("xpifp__6","xpifp",100,-100,100);
  xpifp__6->GetXaxis()->SetTitle("xprime_IFP (mrad)");
  
  ypifp__8 = new TH1D("ypifp__8","ypifp",100,-100,100);
  ypifp__8->GetXaxis()->SetTitle("yprime_IFP (mrad)");
  
  xp__5 = new TH1D("xp__5","xp",100,-100,100);
  xp__5->GetXaxis()->SetTitle("xprime_PiM1Tar (mrad)");
  
  yp__7 = new TH1D("yp__7","yp",100,-100,100);
  yp__7->GetXaxis()->SetTitle("yprime_PiM1Tar (mrad)");
  
}    
  
    
    
