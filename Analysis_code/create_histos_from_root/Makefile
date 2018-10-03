#Created by P. Roy (Sept 30, 2018)

#####################                                                                                
####    LINUX   #####                                                                                
#####################                                                                                

  ROOTCFLAGS   := $(shell root-config --cflags)
  ROOTLIBS     := $(shell root-config --libs)
  ROOTGLIBS    := $(shell root-config --glibs)

  FF          = /d/home/lukasz/gcc-3.2.3/bin/g77
  FFLAGS      = -O2 -pg -c -g -Wall
  FINCLUDES   =
  FFILES      =

# CC          = /d/home/lukasz/gcc-3.2.3/bin/gcc                                                     
  CC          = gcc
  CFLAGS      = -O2 -pg -c -g -Wall
  CFILES      =
  CINCLUDES   =

# CCC         = /d/home/lukasz/gcc-3.2.3/bin/g++                                                     
  CCC         = g++
  CCFLAGS     = -O2 -pg -c -g -Wall
  CCINCLUDES  = $(ROOTCFLAGS) -I.

  CCFILES = analysis.cc defineHistos.cc loadingFiles.cc fillHistos.cc setBranches.cc initialize.cc writeROOT.cc 
  NAME        = analysis1
  DEST        = $(NAME)
  LIBS        = $(ROOTLIBS)

  OTHER      = -lcboff++lib -lbctraklib -lg2c -lm
  OPTIONS    = -frepo -pg -g -o

  #CERNLIBDIR  = /d/grid3/cernlib/i386_rhel3/2003/lib
  #CERNLIBS    = -lpacklib -lkernlib -lmathlib -lnsl
# OTHER       = -lcboff++lib -lbctraklib -lg2c -lm                                                   
  OTHER       = -lg2c -lm
  OPTIONS     = -frepo -pg -g -o

###############################################################              

OFILES     = $(CFILES:.c=.o) $(FFILES:.f=.o) $(CCFILES:.cc=.o)

.SUFFIXES : .cc

.c.o :
	$(CC) $(CFLAGS) $(CINCLUDES) $<

.f.o :
	$(FF) $(FFLAGS) $(FINCLUDES) $<

.cc.o :
	$(CCC) $(CCFLAGS) $(CCINCLUDES) $<

$(NAME): $(OFILES)
	$(CCC) $(OPTIONS) $(DEST) $(OFILES) $(ROOTGLIBS) $(ROOTLIBS)

clean: clean-src
	rm -f *.o *.so $(NAME) logfile 

clean-src:
	rm -f *.bak *~
