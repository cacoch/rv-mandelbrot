# Copyright (c) 1998-$Date: 2022-03-24 13:31:19 -0700 (Thu, 24 Mar 2022) $ TIBCO Software Inc.
# All Rights Reserved. Confidential & Proprietary.
# TIB/Rendezvous is protected under US Patent No. 5,187,787.
# For more information, please contact:
# TIBCO Software Inc., Palo Alto, California, USA

# TIB/Rendezvous Example code

# UNIX (GNU make)
#
O = .o

RM = rm -f
OUT = -o
OBJOUT = -o
TIBRV_DIR=$(HOME)/tibco/tibrv/8.6.0
CC = cc
LDFLAGS =-L$(TIBRV_DIR)/lib -Wl,-rpath=$(TIBRV_DIR)/lib 
INCFILES = -I$(TIBRV_DIR)/include
CFLAGS = $(INCFILES)
CFLAGS += -g
TIBRV_LIB = -ltibrv
TIBRVFT_LIB = -ltibrvft
TIBRVCM_LIB = -ltibrvcmq -ltibrvcm -ltibrvft
MATH_LIB = -lm

#### UNIX system specific options
system := $(shell uname -s)
ifeq ($(system),Linux)
	TLIBS = -lpthread
endif


######################################################################


LIBS=  $(TIBRV_LIB) $(MATH_LIB) $(SOCKET_LIBS) $(SYS_LIBS) $(TLIBS)

soucefiles =  tibrvlisten.c \
	      tibrvsend.c

all::	tibrvsend \
	tibrvlisten


clean::
	$(RM) tibrvsend

%:	%.o
	$(CC) $(LDFLAGS) tibrvsend$(O)  $(LIBS) $(OUT)$@

tibrvsend:	tibrvsend$(O)
	$(CC) $(LDFLAGS) tibrvsend$(O)  $(LIBS) $(OUT)$@

tibrvlisten:	tibrvlisten$(O)
	$(CC) $(LDFLAGS) tibrvlisten$(O)  $(LIBS) $(OUT)$@

