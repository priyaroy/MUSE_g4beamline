#Created by P. Roy (Sept 30, 2018)

ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs)
ROOTGLIBS    := $(shell root-config --glibs)

HOMEDIR      := $(shell pwd)

#FF          = g77
#FFLAGS      = -O0 -pg -c -g -Wall
#FINCLUDES   =
#FFILES      =

#CC          = gcc
#CFLAGS      = -O0 -pg -c -g -Wall
#CFILES      =

CCC         = g++
CCFLAGS     = -O0 -pg -c -g -Wall
CCINCLUDES  = $(ROOTCFLAGS) -I$(HOMEDIR) -I-

CCFILES = *.cc

NAME        = observables
DEST        = $(NAME)
LIBS        = $(ROOTLIBS)

OTHER       = -lcboff++lib -lbctraklib -lg2c -lm
OPTIONS     = -frepo -pg -g -o
#ROOFITLIBS  = -lRooFit -lRooFitCore -lMinuit -lFoam -lMathMore -B/d/home/apps/gsl-1.9/.libs/
 
HEADERS = *.h

objects = *.cc
linkerobjects = event_data.o
#SOURCE = event_data.cc
#Headers = event_data.h
###############################################################                                      

all :$(NAME)

$(NAME): $(objects) Makefile
	$(CCC) -fPIC -ggdb -o $(DEST) $(ROOTGLIBS) $(ROOTCFLAGS)  $(objects) -L.. -I..
	
clean: rm -f *.o *.so $(NAME) logfile 

