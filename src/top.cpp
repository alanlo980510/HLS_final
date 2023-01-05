#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "top.h"
#include "filt.h"
#include "HDC.h"

using namespace std;

data_hdc IM[1064] = {   1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,1,-1,
                        -1,1,-1,1,1,1,1,1,-1,1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,
                        -1,1,-1,1,1,-1,-1,1,1,-1,1,1,-1,1,1,1,1,-1,-1,1,-1,1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,
                        -1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,1,
                        -1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,1,1,-1,-1,1,-1,1,1,1,-1,-1,
                        1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,
                        1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,
                        1,1,1,1,-1,-1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,1,1,-1,1,1,-1,-1,1,1,1,
                        -1,-1,-1,1,-1,1,1,1,-1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,
                        1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,1,-1,1,1,-1,1,
                        1,1,-1,1,1,-1,1,1,1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,
                        1,-1,1,-1,1,-1,1,1,1,-1,1,-1,1,-1,1,1,1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,1,-1,
                        -1,1,1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,
                        1,-1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,1,1,-1,
                        1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,
                        1,1,-1,1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,1,1,1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,
                        1,-1,-1,1,-1,1,1,1,-1,1,1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,1,-1,1,1,1,1,
                        -1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,1,1,-1,1,1,1,-1,1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,1,-1,1,1,1,
                        1,-1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,1,1,1,1,1,1,-1,1,1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,1,
                        -1,-1,-1,1,1,1,1,-1,1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,
                        1,1,1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,1,1,
                        1,1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,1,1,1,-1,1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,1,-1,1,-1,
                        -1,1,-1,-1,1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,
                        1,1,-1,1,-1,1,1,-1,1,1,-1,1,-1,1,1,1,-1,1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,
                        -1,-1,1,1,1,1,1,-1,1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,1,-1,1,1,1,-1,1,-1,1,1,-1,1,1,-1,1,-1,1,1,1,-1,1,-1,-1,
                        -1,-1,1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,1,-1,1};


void readdata(data_EMG input, data_t data_in[b2_tap][64], int in_loc){
    #pragma HLS INLINE

    for(int ch=0; ch<64; ch++){
        #pragma HLS UNROLL
        for(int bit=0; bit<22; bit++)
        data_in[in_loc][ch][bit] = input[ch*22+bit];
    }
}

void data_copy(data_t data_out[N*64], data_hdc HDC_vec[320]){
    #pragma HLS INLINE
	for(int i=0; i<64*N; i++){
		for(int bit=0; bit<4; bit++){
			#pragma HLS UNROLL
			HDC_vec[i][bit]=data_out[i][6+bit];
		}
	}

//    for(int row=0; row<N; row++){
//        for(int ch=0; ch<64; ch++){
//			#pragma HLS UNROLL
//        	for(int bit=0; bit<4; bit++){
//        			HDC_vec[row*64+ch][bit] = data_out[row][ch][6+bit];
//        	}
//        }
//    }
}


void top(data_EMG* input, int* in_label, int data_len, data_hdc* AM_out){

    // interface memory for filter
    data_t data_in[b2_tap][64];
    int in_loc=0, in_loc_last=1, out_loc=0, hdc_counter=0;
    bool reset;

    // iterface memory for HDC
    data_hdc HDC_vec[320], AM[5][500];
    int im_temp;
    bool vec_counter=0;
    int label = in_label[0];

    // reset state
    reset = 1;
    filt(0, in_loc, in_loc_last, out_loc, data_in, HDC_vec, reset);

    reset = 0;
Main_Loop:
    for(int data_counter=0; data_counter<Windowsize; data_counter++){
        readdata(input[data_counter], data_in, in_loc);
        filt(data_counter, in_loc, in_loc_last, out_loc, data_in, HDC_vec, reset);
    }
//	data_copy(data_out, HDC_vec);
	hdc_train(HDC_vec, label, IM, AM);




    int counter=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<500; j++){
            #pragma HLS PIPELINE
            AM_out[counter] = AM[i][j];
            counter++;
        }
    }

    return;
}