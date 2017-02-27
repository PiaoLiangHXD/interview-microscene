/*
* Author: Xiaodi
* Date: 25/02/2017
* Description: code for interview of MicroScene
* Details here: https://github.com/everyang/interview/blob/master/READMD.md
* Class: Distace: data structure for distance with a given point (double distance, int index)
*/
#pragma once

#include<iostream>

class Distance{
public:
	double d;
	int index;

	Distance(){
		d = 0;
		index = 0;
	}

	Distance(double _d, int _index){
		d = _d;
		index = _index;
	}

	void swap(Distance &a){
		double _d = d;
		int _index = index;
		d = a.d;
		index = a.index;
		a.d = _d;
		a.index = _index;
	}

	void print(){
		cout << d << " " << index << endl;
	}
};