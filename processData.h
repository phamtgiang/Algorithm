/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Declaration of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_PROCESSDATA_H
#define DSA191_A1_PROCESSDATA_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cassert>

#include "dbLib.h"
using namespace std;
/// Prototype declaration
void Initialization();
void Finalization();

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &);

template <typename T>
void PrintReqOutput(const char* pRequest, T* pOutput, int N) {
    cout << pRequest << ":";
    if (pOutput == nullptr) {
        cout << " error\n";
        return;
    }
    for (int i = 0; i < N; ++i) {
        cout << ' ' << *pOutput++;
    }
    cout << '\n';
}

void Request_CL(const char* pRequest, void* &pData, void* &pOutput, int &N);
void Request_CL_cityName(const char* pRequest, void* &pData, void* &pOutput, int &N);
void Request_LSC_cityName(const char* pRequest, void* &pData, void* &pOutput, int &N);
void Request_LLC_cityName(const char* pRequest, void* &pData, void* &pOutput, int &N);
void Request_LSL_lineid(const char* pRequest, void* &pData, void* &pOutput, int &N);
void Request_FC_cityName(const char* pRequest, void *&pData , void* &pOutput, int &N);
void Request_FS_stationName(const char* pRequest, void *&pData, void* &pOutput, int &N);
void Request_SLP_station_id_track_id(const char* pRequest, void *&pData, void* &pOutput, int &N);
void Request_IS_csv_description(const char* pRequest, void *&pData, void* &pOutput, int &N);
void Request_RS_station_id(const char* pRequest , void* &pData , void* &pOutput ,int& N );
void Request_US_station_id_csv_description(const char* pRequest , void* &pData , void* &pOutput ,int& N );
void Request_ISL_station_id_line_id_p_i(const char* pRequest , void* &pData , void* &pOutput ,int& N );
void Request_RSL_station_id_line_id(const char* pRequest, void *&pData, void* &pOutput, int &N);



#endif //DSA191_A1_PROCESSDATA_H
