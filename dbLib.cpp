/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */

TDataset* manager = new TDataset();

void Load_lines(const char* pFName , void*& pData)
{
	ifstream ifs_lines(pFName, ios::in);
	int count = 0;
	while (ifs_lines.good())
	{
		string id_, city_id_, name_, url_name_, color_, system_id_, transport_mode_id_;

		getline(ifs_lines, id_, ',');
		getline(ifs_lines, city_id_, ',');
		getline(ifs_lines, name_, ',');
		getline(ifs_lines, url_name_, ',');
		getline(ifs_lines, color_, ',');
		getline(ifs_lines, system_id_, ',');
		getline(ifs_lines, transport_mode_id_, '\n');

		if (count != 0)
		{
			/* insert element into linked list TLines*/
            TLine line(id_,city_id_);
			(*(TDataset**)pData)->lines->push_back(line);		
		}
		count++;
	}
	ifs_lines.close();
}
void Load_cities(const char* pFName , void *& pData)
{
	ifstream ifs_lines(pFName, ios::in);
	int count = 0;
	while (ifs_lines.good())
	{
		string id_, name_, coords_, start_year_, url_name_, country_, country_state_;

		getline(ifs_lines, id_, ',');
		getline(ifs_lines, name_, ',');
		getline(ifs_lines, coords_, ',');
		getline(ifs_lines, start_year_, ',');
		getline(ifs_lines, url_name_, ',');;
		getline(ifs_lines, country_, ',');
		getline(ifs_lines, country_state_, '\n');

		if (count != 0)
		{
			/*insert new node(contains value) into linked list TCity */
            TCity cities(id_,name_);
		    (*(TDataset**)pData)->cities->push_back(cities);
		}
		count++;
	}
	ifs_lines.close();
}
void Load_stations(const char* pFName , void *& pData)
{
	ifstream ifs_lines(pFName, ios::in);
	int count = 0;
	while (ifs_lines.good())
	{
		string id_, name_, geometry_, buildstart_, opening_, closure_, city_id_;

		getline(ifs_lines, id_, ',');
		getline(ifs_lines, name_, ',');
		getline(ifs_lines, geometry_, ',');
		getline(ifs_lines, buildstart_, ',');
		getline(ifs_lines, opening_, ',');
		getline(ifs_lines, closure_, ',');
		getline(ifs_lines, city_id_, '\n');


		if (count != 0)
		{
           TStation stations(id_,name_, geometry_,city_id_);
		   (*(TDataset**)pData)->stations->push_back(stations);
		}
		count++;
	}
	ifs_lines.close();
}
void Load_station_lines(const char* pFName , void *& pData)
{
	ifstream ifs_lines(pFName, ios::in);
	int count = 0;
	while (ifs_lines.good())
	{
		string 	id_, station_id_, line_id_, city_id_, created_at_, updated_at_;

		getline(ifs_lines, id_, ',');
		getline(ifs_lines, station_id_, ',');
		getline(ifs_lines, line_id_, ',');
		getline(ifs_lines, city_id_, ',');
		getline(ifs_lines, created_at_, ',');
		getline(ifs_lines, updated_at_, '\n');

		if (count != 0)
		{
            TStation_line station_lines(station_id_,line_id_);
            (*(TDataset**)pData)->station_lines->push_back(station_lines);			
		}
		count++;
	}
	ifs_lines.close();
}

void Load_tracks(const char *pFName, void*& pData)
{
	ifstream ifs_lines(pFName, ios::in);
	int count = 0;
	while (ifs_lines.good())
	{
        string id,_pre_geometry,geometry,app_geometry,buildstart,opening,closure,length,city_id;
      
	    if(count == 0){
		getline(ifs_lines, id , ',');
		getline(ifs_lines, geometry,',');
		getline(ifs_lines, buildstart , ',');
		getline(ifs_lines, opening , ',');
		getline(ifs_lines, closure , ',');
		getline(ifs_lines, length , ',');
		getline(ifs_lines, city_id , '\n');
		}
        else {
		getline(ifs_lines, id , ',');
		getline(ifs_lines,_pre_geometry,'"');
		getline(ifs_lines, geometry,'"');
		getline(ifs_lines,app_geometry,',');
		getline(ifs_lines, buildstart , ',');
		getline(ifs_lines, opening , ',');
		getline(ifs_lines, closure , ',');
		getline(ifs_lines, length , ',');
		getline(ifs_lines, city_id , '\n');
           TTrack tracks(id,geometry);
		   (*(TDataset**)pData)->tracks->push_back(tracks);
		}
		count++;
	}
	ifs_lines.close();
}

void LoadData(void*& pData)
{
	pData = &manager;
	Load_lines("lines.csv" , pData);
	Load_cities("cities.csv",pData);
	Load_stations("stations.csv",pData);
	Load_station_lines("station_lines.csv",pData);
    Load_tracks("tracks.csv",pData);
}
void ReleaseData(void* & pData)
{
	delete (*(TDataset**)pData)->lines;
	delete (*(TDataset**)pData)->cities;
	delete (*(TDataset**)pData)->LINESTRING;
	delete (*(TDataset**)pData)->station_lines;
	delete (*(TDataset**)pData)->stations;
	delete (*(TDataset**)pData)->tracks;
	delete (*(TDataset**)pData);
	pData = nullptr;
}