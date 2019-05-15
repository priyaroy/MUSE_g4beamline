#include <iostream>
#include <math.h>
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"

//Spatial distributions

extern TH1F *xDet0;
extern TH1F *xDet0a;
extern TH1F *xDetAQTA1; 
extern TH1F *xDetAQTB1;
extern TH1F *xDetAQTB2;
extern TH1F *xDet1;
extern TH1F *xDet2;
extern TH1F *xDet3;
extern TH1F *xDet4;
extern TH1F *xDet5;
extern TH1F *xDetTar;

extern TH1F *yDet0;
extern TH1F *yDet0a;
extern TH1F *yDetAQTA1; 
extern TH1F *yDetAQTB1;
extern TH1F *yDetAQTB2;
extern TH1F *yDet1;
extern TH1F *yDet2;
extern TH1F *yDet3;
extern TH1F *yDet4;
extern TH1F *yDet5;
extern TH1F *yDetTar;

extern TH1F *pxDet0;
extern TH1F *pxDet0a;
extern TH1F *pxDetAQTA1; 
extern TH1F *pxDetAQTB1;
extern TH1F *pxDetAQTB2;
extern TH1F *pxDet1;
extern TH1F *pxDet2;
extern TH1F *pxDet3;
extern TH1F *pxDet4;
extern TH1F *pxDet5;
extern TH1F *pxDetTar;

extern TH1F *pyDet0;
extern TH1F *pyDet0a;
extern TH1F *pyDetAQTA1; 
extern TH1F *pyDetAQTB1;
extern TH1F *pyDetAQTB2;
extern TH1F *pyDet1;
extern TH1F *pyDet2;
extern TH1F *pyDet3;
extern TH1F *pyDet4;
extern TH1F *pyDet5;
extern TH1F *pyDetTar;

extern TH1F *pDet0;
extern TH1F *pDet0a;
extern TH1F *pDetAQTA1; 
extern TH1F *pDetAQTB1;
extern TH1F *pDetAQTB2;
extern TH1F *pDet1;
extern TH1F *pDet2;
extern TH1F *pDet3;
extern TH1F *pDet4;
extern TH1F *pDet5;
extern TH1F *pDetTar;

extern TH1F *dpDet0;
extern TH1F *dpDet0a;
extern TH1F *dpDetAQTA1; 
extern TH1F *dpDetAQTB1;
extern TH1F *dpDetAQTB2;
extern TH1F *dpDet1;
extern TH1F *dpDet2;
extern TH1F *dpDet3;
extern TH1F *dpDet4;
extern TH1F *dpDet5;
extern TH1F *dpDetTar;

extern TH2F *pxpy_Det0;
extern TH2F *pxpy_Det0a;
extern TH2F *pxpy_DetAQTA1; 
extern TH2F *pxpy_DetAQTB1;
extern TH2F *pxpy_DetAQTB2;
extern TH2F *pxpy_Det1;
extern TH2F *pxpy_Det2;
extern TH2F *pxpy_Det3;
extern TH2F *pxpy_Det4;
extern TH2F *pxpy_Det5;
extern TH2F *pxpy_DetTar;


extern TH2F *beamspot_Det0;
extern TH2F *beamspot_Det0a;
extern TH2F *beamspot_DetAQTA1; 
extern TH2F *beamspot_DetAQTB1;
extern TH2F *beamspot_DetAQTB2;
extern TH2F *beamspot_Det1;
extern TH2F *beamspot_Det2;
extern TH2F *beamspot_Det3;
extern TH2F *beamspot_Det4;
extern TH2F *beamspot_Det5;
extern TH2F *beamspot_DetTar;

extern TH2F *dispersion_Det0;
extern TH2F *dispersion_Det0a;
extern TH2F *dispersion_DetAQTA1; 
extern TH2F *dispersion_DetAQTB1;
extern TH2F *dispersion_DetAQTB2;
extern TH2F *dispersion_Det1;
extern TH2F *dispersion_Det2;
extern TH2F *dispersion_IFP;
extern TH2F *dispersion_Det4;
extern TH2F *dispersion_Det5;
extern TH2F *dispersion_Tar;

extern TH2F *xPx_Det0;
extern TH2F *xPx_Det0a;
extern TH2F *xPx_DetAQTA1; 
extern TH2F *xPx_DetAQTB1;
extern TH2F *xPx_DetAQTB2;
extern TH2F *xPx_Det1;
extern TH2F *xPx_Det2;
extern TH2F *xPx_Det3;
extern TH2F *xPx_Det4;
extern TH2F *xPx_Det5;
extern TH2F *xPx_DetTar;

extern TH2F *yPy_Det0;
extern TH2F *yPy_Det0a;
extern TH2F *yPy_DetAQTA1; 
extern TH2F *yPy_DetAQTB1;
extern TH2F *yPy_DetAQTB2;
extern TH2F *yPy_Det1;
extern TH2F *yPy_Det2;
extern TH2F *yPy_Det3;
extern TH2F *yPy_Det4;
extern TH2F *yPy_Det5;
extern TH2F *yPy_DetTar;

extern TH2F *dpPx_Det0;
extern TH2F *dpPx_Det0a;
extern TH2F *dpPx_DetAQTA1; 
extern TH2F *dpPx_DetAQTB1;
extern TH2F *dpPx_DetAQTB2;
extern TH2F *dpPx_Det1;
extern TH2F *dpPx_Det2;
extern TH2F *dpPx_Det3;
extern TH2F *dpPx_Det4;
extern TH2F *dpPx_Det5;
extern TH2F *dpPx_DetTar;

extern TH2F *ydp_Det0;
extern TH2F *ydp_Det0a;
extern TH2F *ydp_DetAQTA1; 
extern TH2F *ydp_DetAQTB1;
extern TH2F *ydp_DetAQTB2;
extern TH2F *ydp_Det1;
extern TH2F *ydp_Det2;
extern TH2F *ydp_Det3;
extern TH2F *ydp_Det4;
extern TH2F *ydp_Det5;
extern TH2F *ydp_DetTar;

extern TH2F *dpPy_Det0;
extern TH2F *dpPy_Det0a;
extern TH2F *dpPy_DetAQTA1; 
extern TH2F *dpPy_DetAQTB1;
extern TH2F *dpPy_DetAQTB2;
extern TH2F *dpPy_Det1;
extern TH2F *dpPy_Det2;
extern TH2F *dpPy_Det3;
extern TH2F *dpPy_Det4;
extern TH2F *dpPy_Det5;
extern TH2F *dpPy_DetTar;

//Summer 2018 data Ethan

extern TH1D *xifp__2;
extern TH1D *xpifp__6;
extern TH1D *yifp__4;
extern TH1D *ypifp__8;

extern TH1D *xtarg__1;
extern TH1D *xp__5;
extern TH1D *ytarg__3;
extern TH1D *yp__7;
