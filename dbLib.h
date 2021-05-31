/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
struct TCity {
    // The structure to store city information
    string id;
    string name;
    TCity(){}
    TCity(string _id, string _name):id(_id),name(_name){}
};

struct TLine {
    // The structure to store line information
    string id;
    string city_id;
    TLine(){}
    TLine(string _id, string _city_id):id(_id), city_id(_city_id){}
};
struct TStation{
    string id;
    string name;
    string geometry;
    string city_id;
    TStation(){}
    TStation(string _id, string _name , string _geometry , string _city_id)
    : id(_id),name(_name),geometry(_geometry),city_id(_city_id){}
};
struct TStation_line{
     string station_id;
     string line_id;
     TStation_line(){}
     TStation_line(string _station_id, string _line_id)
     :station_id(_station_id),line_id(_line_id){}
};
struct TTrack {
    // The structure to store track information
    string id;
    string geometry;
    TTrack(){}
    TTrack(string _id, string _geometry):id(_id),geometry(_geometry){}
};
struct TLINESTRING{
    string POINT;
    TLINESTRING(){}
    TLINESTRING(string _POINT):POINT(_POINT){}
};
class TDataset {
    // This class can be a container that help you manage your tables
public:
      L1List<TLine> *lines = new L1List<TLine>();
      L1List<TCity> *cities = new L1List<TCity>();
      L1List<TStation> *stations = new L1List<TStation>();
      L1List<TStation_line> *station_lines = new L1List<TStation_line>();
      L1List<TTrack> *tracks = new L1List<TTrack>();
      L1List<TLINESTRING> *LINESTRING = new L1List<TLINESTRING>();
};

// Please add more or modify as needed
extern TDataset* manager;
void LoadData(void* &);
void ReleaseData(void* &);

#endif //DSA191_A1_DBLIB_H
