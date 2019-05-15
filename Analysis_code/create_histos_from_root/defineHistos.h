#include <iostream>
#include <math.h>
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"

//Spatial distributions

TH1F *xDet0;
TH1F *xDet0a;
TH1F *xDetAQTA1; 
TH1F *xDetAQTB1;
TH1F *xDetAQTB2;
TH1F *xDet1;
TH1F *xDet2;
TH1F *xDet3;
TH1F *xDet4;
TH1F *xDet5;
TH1F *xDetTar;

TH1F *yDet0;
TH1F *yDet0a;
TH1F *yDetAQTA1; 
TH1F *yDetAQTB1;
TH1F *yDetAQTB2;
TH1F *yDet1;
TH1F *yDet2;
TH1F *yDet3;
TH1F *yDet4;
TH1F *yDet5;
TH1F *yDetTar;

TH1F *pxDet0;
TH1F *pxDet0a;
TH1F *pxDetAQTA1; 
TH1F *pxDetAQTB1;
TH1F *pxDetAQTB2;
TH1F *pxDet1;
TH1F *pxDet2;
TH1F *pxDet3;
TH1F *pxDet4;
TH1F *pxDet5;
TH1F *pxDetTar;

TH1F *pyDet0;
TH1F *pyDet0a;
TH1F *pyDetAQTA1; 
TH1F *pyDetAQTB1;
TH1F *pyDetAQTB2;
TH1F *pyDet1;
TH1F *pyDet2;
TH1F *pyDet3;
TH1F *pyDet4;
TH1F *pyDet5;
TH1F *pyDetTar;

TH1F *pDet0;
TH1F *pDet0a;
TH1F *pDetAQTA1; 
TH1F *pDetAQTB1;
TH1F *pDetAQTB2;
TH1F *pDet1;
TH1F *pDet2;
TH1F *pDet3;
TH1F *pDet4;
TH1F *pDet5;
TH1F *pDetTar;

TH1F *dpDet0;
TH1F *dpDet0a;
TH1F *dpDetAQTA1; 
TH1F *dpDetAQTB1;
TH1F *dpDetAQTB2;
TH1F *dpDet1;
TH1F *dpDet2;
TH1F *dpDet3;
TH1F *dpDet4;
TH1F *dpDet5;
TH1F *dpDetTar;

TH2F *pxpy_Det0;
TH2F *pxpy_Det0a;
TH2F *pxpy_DetAQTA1; 
TH2F *pxpy_DetAQTB1;
TH2F *pxpy_DetAQTB2;
TH2F *pxpy_Det1;
TH2F *pxpy_Det2;
TH2F *pxpy_Det3;
TH2F *pxpy_Det4;
TH2F *pxpy_Det5;
TH2F *pxpy_DetTar;

TH2F *beamspot_Det0;
TH2F *beamspot_Det0a;
TH2F *beamspot_DetAQTA1; 
TH2F *beamspot_DetAQTB1;
TH2F *beamspot_DetAQTB2;
TH2F *beamspot_Det1;
TH2F *beamspot_Det2;
TH2F *beamspot_Det3;
TH2F *beamspot_Det4;
TH2F *beamspot_Det5;
TH2F *beamspot_DetTar;

TH2F *dispersion_Det0;
TH2F *dispersion_Det0a;
TH2F *dispersion_DetAQTA1; 
TH2F *dispersion_DetAQTB1;
TH2F *dispersion_DetAQTB2;
TH2F *dispersion_Det1;
TH2F *dispersion_Det2;
TH2F *dispersion_IFP;
TH2F *dispersion_Det4;
TH2F *dispersion_Det5;
TH2F *dispersion_Tar;

TH2F *xPx_Det0;
TH2F *xPx_Det0a;
TH2F *xPx_DetAQTA1; 
TH2F *xPx_DetAQTB1;
TH2F *xPx_DetAQTB2;
TH2F *xPx_Det1;
TH2F *xPx_Det2;
TH2F *xPx_Det3;
TH2F *xPx_Det4;
TH2F *xPx_Det5;
TH2F *xPx_DetTar;

TH2F *yPy_Det0;
TH2F *yPy_Det0a;
TH2F *yPy_DetAQTA1; 
TH2F *yPy_DetAQTB1;
TH2F *yPy_DetAQTB2;
TH2F *yPy_Det1;
TH2F *yPy_Det2;
TH2F *yPy_Det3;
TH2F *yPy_Det4;
TH2F *yPy_Det5;
TH2F *yPy_DetTar;

TH2F *dpPx_Det0;
TH2F *dpPx_Det0a;
TH2F *dpPx_DetAQTA1; 
TH2F *dpPx_DetAQTB1;
TH2F *dpPx_DetAQTB2;
TH2F *dpPx_Det1;
TH2F *dpPx_Det2;
TH2F *dpPx_Det3;
TH2F *dpPx_Det4;
TH2F *dpPx_Det5;
TH2F *dpPx_DetTar;

TH2F *ydp_Det0;
TH2F *ydp_Det0a;
TH2F *ydp_DetAQTA1; 
TH2F *ydp_DetAQTB1;
TH2F *ydp_DetAQTB2;
TH2F *ydp_Det1;
TH2F *ydp_Det2;
TH2F *ydp_Det3;
TH2F *ydp_Det4;
TH2F *ydp_Det5;
TH2F *ydp_DetTar;

TH2F *dpPy_Det0;
TH2F *dpPy_Det0a;
TH2F *dpPy_DetAQTA1; 
TH2F *dpPy_DetAQTB1;
TH2F *dpPy_DetAQTB2;
TH2F *dpPy_Det1;
TH2F *dpPy_Det2;
TH2F *dpPy_Det3;
TH2F *dpPy_Det4;
TH2F *dpPy_Det5;
TH2F *dpPy_DetTar;

//summer 2018 data Ethan

TH1D *xifp__2;
TH1D *xpifp__6;
TH1D *yifp__4;
TH1D *ypifp__8;

TH1D *xtarg__1;
TH1D *xp__5;
TH1D *ytarg__3;
TH1D *yp__7;


