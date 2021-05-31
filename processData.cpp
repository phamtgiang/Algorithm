/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"


/*
valgrind --leak-check=full --show-leak-kinds=all ./a.out
*/
/* TODO: You can implement methods, functions that support your data structures here.
 * */
using namespace std;



void Initialization() {
    // If you use global variables, please initialize them explicitly in this function.
}

void Finalization() {
    // Release your data before exiting
}

void Request_CL(const char* pRequest, void* &pData, void* &pOutput, int &N)
{
    N = 1;
	pOutput = new int[N];
	*(int*)pOutput = (*(TDataset**)pData)->lines->getSize() - 1; 
}

void Request_CL_cityName(const char* pRequest, void* &pData, void* &pOutput, int &N){
	string city_name = pRequest;
	city_name = city_name.substr(3); 

	bool found = false;
    int idx;

	for (int i = 0; i < (*(TDataset**)pData)->cities->getSize()-1; i++)
		if ((*(TDataset**)pData)->cities->at(i).name == city_name)
		{
			idx = i;
            found = true;
			break; // get first id of city
		} // determine id of city via city_name

	int numberOfLinesInCity = -1;

	if (found) // if city does not exist , return -1
	{
		numberOfLinesInCity = 0;
		for (int i = 0; i < (*(TDataset**)pData)->lines->getSize()-1; i++)
			  if ((*(TDataset**)pData)->lines->at(i).city_id == (*(TDataset**)pData)->cities->at(idx).id)
				 numberOfLinesInCity++;  // number line in given city
	}

    N = 1;
	pOutput = new int[N];
	*(int*)pOutput =  numberOfLinesInCity;
}

void Request_LSC_cityName(const char* pRequest,void* &pData , void* &pOutput, int &N)
{   
	string city_name = pRequest;
	city_name = city_name.substr(4); 

	string id_city ;
	
	for (int i = 0; i < (*(TDataset**)pData)->cities->getSize()-1; i++)
		if ((*(TDataset**)pData)->cities->at(i).name == city_name)
			{
				id_city = (*(TDataset**)pData)->cities->at(i).id; // get first id
				break;
			}

	pOutput = new int[10000]; 
	int index = 0;
	int numberOfStationsInCity = 0;

   TStation * _stations = new TStation[(*(TDataset**)pData)->stations->getSize()];
   (*(TDataset**)pData)->stations->_traverse(_stations,0);
   
   for(int i = 0 ; i < (*(TDataset**)pData)->stations->getSize()-1;i++)
	   if(id_city == _stations[i].city_id)
	   {
		   *((int*)pOutput + index) = stoi(_stations[i].id);
		   numberOfStationsInCity++;
		   index++;
	   }
    
    delete[] _stations;
	N = numberOfStationsInCity;
}

void Request_LLC_cityName(const char* pRequest, void* &pData, void* &pOutput, int &N)
{
	string city_name = pRequest;
	city_name = city_name.substr(4); 

   string id_city;

	for (int i = 0; i < (*(TDataset**)pData)->cities->getSize()-1; i++)
		if ((*(TDataset**)pData)->cities->at(i).name == city_name)
			{
				id_city = (*(TDataset**)pData)->cities->at(i).id; // get first id
				break;
			}

	pOutput = new int[1000]; 
	int index = 0;
	int numberOfLinesInCity = 0;

	for (int i = 1; i < (*(TDataset**)pData)->lines->getSize()-1; i++)
		if (id_city == (*(TDataset**)pData)->lines->at(i).city_id)
		{
			*((int*)pOutput + index) = stoi((*(TDataset**)pData)->lines->at(i).id); 
			numberOfLinesInCity++;
			index++;
		}

	N = numberOfLinesInCity;
}

void Request_LSL_lineid(const char* pRequest, void* &pData, void* &pOutput, int &N)
{
	string line_id = pRequest;
	line_id = line_id.substr(4);

	pOutput = new int[5000];
	int numberOfStation_Line = 0;
	int index = 0;

    TStation_line* _station_lines = new TStation_line[(*(TDataset**)pData)->station_lines->getSize()];
  (*(TDataset**)pData)->station_lines->_traverse(_station_lines,0);
	
	for(int i = 0 ;i < (*(TDataset**)pData)->station_lines->getSize()-1;i++)
		if(line_id == _station_lines[i].line_id)
		{
			*((int*)pOutput + index) = stoi(_station_lines[i].station_id);
			numberOfStation_Line++;
			index++;
		}

    delete []_station_lines;
	N = numberOfStation_Line;
}

void Request_FC_cityName(const char* pRequest, void* &pData , void* &pOutput, int &N)
{
	string city_name = pRequest;
    city_name = city_name.substr(3); 

	string id_city = "-1";

	for (int i = 0; i < (*(TDataset**)pData)->cities->getSize()-1; i++)
		if ((*(TDataset**)pData)->cities->at(i).name == city_name)
		{
			id_city = (*(TDataset**)pData)->cities->at(i).id;
			break; // get first id
		} 
	N = 1;
	pOutput = new int[N];
	*(int*)pOutput = stoi(id_city);
}

void Request_FS_stationName(const char* pRequest, void *&pData, void* &pOutput, int &N)//V
{
    string station_name = pRequest;
    station_name = station_name.substr(3); 


	string id_station = "-1";

	TStation* _stations = new TStation[(*(TDataset**)pData)->stations->getSize()];
	(*(TDataset**)pData)->stations->_traverse(_stations,0);

	for(int i = 0;i < (*(TDataset**)pData)->stations->getSize()-1;i++)
		if(_stations[i].name == station_name)
		{
			id_station = _stations[i].id;
			break; // get first station_id
		}

	delete []_stations;
	N = 1;
	pOutput = new int[N];
	*(int*)pOutput  = stoi(id_station);
}

void Request_RSL_station_id_line_id(const char* pRequest, void *&pData, void* &pOutput, int &N)//Vi
{
	string pRe = pRequest;
	string station_id, line_id;
	int pos[100];
	int i = 0;
	for (int index = 0; index < pRe.size(); index++)
		if (pRe[index] == ' ')
			pos[i++] = index + 1;

	station_id = pRe.substr(pos[0], pos[1] - 1 - pos[0]); 
	line_id = pRe.substr(pos[1]); 
	
    TStation_line* _station_lines = new TStation_line[(*(TDataset**)pData)->station_lines->getSize()];
	(*(TDataset**)pData)->station_lines->_traverse(_station_lines,0);

    bool remove = false;
    for(int i = 0 ; i < (*(TDataset**)pData)->station_lines->getSize() - 1 ; i++)
		   if(line_id  == _station_lines[i].line_id && station_id == _station_lines[i].station_id)
		     {
               (*(TDataset**)pData)->station_lines->remove(i);
				remove = true;
				break;
			 }

    delete []_station_lines;
	N = 1;
	pOutput = new int[N];	 
    if(remove)
			*(int*)pOutput = 0;
	else
	       *(int*)pOutput = -1;
	
}

void Request_SLP_station_id_track_id(const char* pRequest, void *&pData, void* &pOutput, int &N)//V
{
	N = 1;
    pOutput = new int[N];
	
	string pRe = pRequest;
	string station_id, track_id;

	int pos[100];
	int i = 0;
	for (int index = 0; index < pRe.size(); index++)
		if (pRe[index] == ' ')
			pos[i++] = index + 1;

	station_id = pRe.substr(pos[0], pos[1] - 1 - pos[0]);
	track_id = pRe.substr(pos[1]); 
	

    string _POINT_station;
	bool found = false;
    for(int i = 0 ;i < (*(TDataset**)pData)->tracks->getSize()-1;i++)
	{
		if(track_id == (*(TDataset**)pData)->tracks->at(i).id)
		{
			
				string LINE =(*(TDataset**)pData)->tracks->at(i).geometry.substr(11);
                LINE = LINE.substr(0,LINE.size()-1);

				stringstream LINESTRING(LINE);
				string point;
				while(!LINESTRING.eof())
				{
					getline(LINESTRING,point,',');
					TLINESTRING _POINT(point);
					(*(TDataset**)pData)->LINESTRING->push_back(_POINT); // add all point into POINT List
				}

				for(int i = 0 ;i < (*(TDataset**)pData)->stations->getSize()-1;i++)
				      if(station_id ==(*(TDataset**)pData)->stations->at(i).id)
					  {
                        _POINT_station =(*(TDataset**)pData)->stations->at(i).geometry.substr(6,(*(TDataset**)pData)->stations->at(i).geometry.size() - 1  - 6);
						break;
					  }

				for(int i = 0 ;i < (*(TDataset**)pData)->LINESTRING->getSize();i++)
					if(_POINT_station == (*(TDataset**)pData)->LINESTRING->at(i).POINT)
					 {
						 found = true;
                         *(int*)pOutput = i;
						 break;
					 }
			break;
		}
	}
   
   if(!found)
   *(int*)pOutput = -1;
}

void Request_ISL_station_id_line_id_p_i(const char* pRequest , void* &pData , void* &pOutput , int& N )//VI
{
	string pRe = pRequest;
	string station_id, line_id , p_i;
	int pos[100];
	int i = 0;
	for (int index = 0; index < pRe.size(); index++)
		if (pRe[index] == ' ')
			pos[i++] = index + 1;

	station_id = pRe.substr(pos[0], pos[1] - 1 - pos[0]);
	line_id = pRe.substr(pos[1] , pos[2] - 1 - pos[1]);
    p_i = pRe.substr(pos[2]); 

    TStation_line station_lines(station_id,line_id);
     
	 bool insert = false;
	 TStation_line* _station_lines = new TStation_line[(*(TDataset**)pData)->station_lines->getSize()];
	 (*(TDataset**)pData)->station_lines->_traverse(_station_lines,0);
    
    for(int i = 0 ; i < (*(TDataset**)pData)->station_lines->getSize() - 1 ; i++)
	       if(line_id == _station_lines[i].line_id){
		       if(station_id == _station_lines[i].station_id)
			     { 
					 insert = false;
					 break;
				 }
			   else insert = true;
		   }
    
	if(insert){
		int pos = stoi(p_i);
	   for(int i = 0 ; i < (*(TDataset**)pData)->station_lines->getSize() - 1 ; i++){
	     	if(line_id == _station_lines[i].line_id)pos--;
            if(pos == -1){
	           (*(TDataset**)pData)->station_lines->insert(i,station_lines);
			   break;
			}
	   }
	}

	delete []_station_lines;
	N = 1;
	pOutput = new int[N];	 
    if(insert)
			*(int*)pOutput = 0;
	else
	       *(int*)pOutput = -1;
		
}

void Request_US_station_id_csv_description(const char* pRequest , void* &pData , void* &pOutput ,int& N )
{
   
   N = 1;
   pOutput = new int[N];

   string csv_description  = pRequest;
   int pos[100];
   int index = -1;
   int two = 0;
   bool ban = true;
   for(int i = 0 ;i < csv_description.size();i++)
   {
	   if(csv_description[i] == ' ' && two < 2)
	   {
          pos[++index] = i + 1;
		  two++;
	   }
	   else if(csv_description[i] == 'P' && csv_description[i+1] == 'O')
	   {
		   pos[++index] = i;
		   ban = false;

	   }
	   else if(!ban && csv_description[i] == ' ')
	   {
           pos[++index] = i + 1;
	   }
	   
   }


  string id , name,geometry,buildstart,opening,closure;

  id = csv_description.substr(pos[0], pos[1] - pos[0] - 1);
  name  = csv_description.substr(pos[1],pos[2] - pos[1] - 1);
  geometry = csv_description.substr(pos[2],pos[4] - pos[2] - 1);
  
  bool update = false;
  TStation* _stations = new TStation[(*(TDataset**)pData)->stations->getSize()];
  (*(TDataset**)pData)->stations->_traverse(_stations,0);

  for(int i = 0 ; i < (*(TDataset**)pData)->stations->getSize()-1;i++)
  {
	if(id  == _stations[i].id)
	{
		TStation stations(id,name,geometry,_stations[i].city_id);
	   (*(TDataset**)pData)->stations->update(i,stations);
	   update = true;
		break;
	}
  }

 if(update)
  *(int*)pOutput = 0;
 else 
  *(int*)pOutput = -1;
  delete [] _stations;

}

void Request_RS_station_id(const char* pRequest , void* &pData , void* &pOutput ,int& N )
{
   	string station_id = pRequest;
    station_id = station_id.substr(3);

    bool remove = false;

	TStation* _stations = new TStation[(*(TDataset**)pData)->stations->getSize()];
	(*(TDataset**)pData)->stations->_traverse(_stations,0);

    for(int i = 0 ; i < (*(TDataset**)pData)->stations->getSize() - 1 ; i++)
		   if(station_id  ==  _stations[i].id)
		     {
                (*(TDataset**)pData)->stations->remove(i);
				remove = true;
				break;
			 }

	N = 1;
	pOutput = new int[N];	 
    if(remove)
			*(int*)pOutput = 0;
	else
	       *(int*)pOutput = -1;
	delete[]_stations;

}

void Request_IS_csv_description(const char* pRequest, void *&pData, void* &pOutput, int &N)
{
   N = 1;
   pOutput = new int[N];
  
   /* Ex: IS Keisei Tsudanuma POINT(140.024812197129 35.6837744784723) 1921 1921 999999*/

   string csv_description = pRequest;
   int pos[100];
   int index = -1;
   int one = 0;
   bool ban = true;
   for(int i = 0 ;i < csv_description.size();i++)
   {
	   if(csv_description[i] == ' ' && one < 1)
	   {
          pos[++index] = i + 1;
		  one++;
	   }
	   else if(csv_description[i] == 'P' && csv_description[i+1] == 'O')
	   {
		   pos[++index] = i;
		   ban = false;
	   }
	   else if(!ban && csv_description[i] == ' ')
	   {
           pos[++index] = i + 1;
	   }
   }


  string name,geometry,buildstart,opening,closure;

  geometry  = csv_description.substr(pos[1],pos[3] - pos[1] - 1);
  name = csv_description.substr(pos[0],pos[1] - pos[0] - 1);
  

  TStation* _stations = new TStation[(*(TDataset**)pData)->stations->getSize()];
	(*(TDataset**)pData)->stations->_traverse(_stations,0);

  int id_max = 0;
  for(int i = 0 ;i < (*(TDataset**)pData)->stations->getSize();i++)
  {
	  int VALUE;
	  stringstream in(_stations[i].id);
	  in >> VALUE;
    if(id_max < VALUE)
	    id_max = VALUE;
  }
  
  TStation stations(std::to_string(id_max+1),name,geometry,"");
  (*(TDataset**)pData)->stations->push_back(stations);

  *(int*)pOutput = id_max + 1;
   delete [] _stations;
}


void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &N) {
	
	string pRe = pRequest;

     if (pRe == "CL")
		Request_CL(pRequest, pData, pOutput,N);

	else if (pRe[0] == 'C' && pRe.size() > 3)
	    Request_CL_cityName(pRequest, pData, pOutput, N);

	else if (pRe.substr(0, 3) == "LSC" && pRe.size() > 4)
		Request_LSC_cityName(pRequest, pData, pOutput, N);

	else if (pRe.substr(0, 3) == "LLC" && pRe.size() > 4)
		Request_LLC_cityName(pRequest, pData, pOutput, N);

	else if (pRe.substr(0, 3) == "LSL" && pRe.size() > 4)
		Request_LSL_lineid(pRequest, pData, pOutput, N);

	else if (pRe.substr(0, 2) == "FC" && pRe.size() > 3)
		Request_FC_cityName(pRequest, pData, pOutput, N);

	else if (pRe.substr(0, 2) == "FS" && pRe.size() > 3)
		Request_FS_stationName(pRequest, pData, pOutput, N);

	else if(pRe.substr(0,3) == "SLP" && pRe.size() > 4)
	   Request_SLP_station_id_track_id(pRequest,pData,pOutput,N);

    else if(pRe.substr(0,3) == "IS " && pRe.size() > 3)
       Request_IS_csv_description(pRequest, pData, pOutput, N);

	else if(pRe.substr(0,3) == "RS " && pRe.size() > 3)
	   Request_RS_station_id(pRequest ,pData , pOutput ,N );
	
    else if(pRe.substr(0,2) == "US" && pRe.size() > 3)
       Request_US_station_id_csv_description(pRequest , pData , pOutput ,N );

	else if(pRe.substr(0,3) == "ISL" && pRe.size() > 4)
	    Request_ISL_station_id_line_id_p_i(pRequest ,pData ,pOutput ,N );

	else if (pRe.substr(0,3) == "RSL" && pRe.size() > 4)
		Request_RSL_station_id_line_id(pRequest, pData, pOutput, N);
}

