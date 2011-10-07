/**
 * Rapid-prototyping protection schemes with IEC 61850
 *
 * Copyright (c) 2011 Steven Blair
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef SV_PACKET_DATA_H
#define SV_PACKET_DATA_H

#include <stdlib.h>
#include <string.h>
#include "ctypes.h"

#define SV_MAX_DATASET_SIZE 	512
//#define SV_MAX_PACKET_SIZE 		1024

struct ASDU {
	unsigned char *svID;
	unsigned char *datset;			// optional
	CTYPE_INT16U smpCnt;
	CTYPE_INT32U confRev;
	//struct UtcTime refrTm;	// optional
	CTYPE_BOOLEAN smpSynch;
	CTYPE_INT16U smpRate;
	struct data {
		unsigned char data[SV_MAX_DATASET_SIZE];
		CTYPE_INT32U size;
	} data;
};

struct svData {
	struct ethHeaderData ethHeaderData;
	short noASDU;
	struct ASDU *ASDU;
	CTYPE_INT16U ASDUCount;			// stores present ASDU count; transmit a packet when equals "noASDU"
	CTYPE_INT16U sampleCountMaster;
};

#endif