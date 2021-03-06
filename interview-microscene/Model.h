/*
 * Author: Xiaodi
 * Date: 24/02/2017
 * Description: code for interview of MicroScene
 * Details here: https://github.com/everyang/interview/blob/master/READMD.md
 * Class: Model: a model of 3d points in file data.txt
*/
#pragma once

#include "Point3d.h"
#include "Distance.h"
#include<fstream>

class Model{
public:
	vector<Point3d> model;
	Model(){
		model.clear();
	}


	void GetData();

	//minmax in x,y,z for GetBound
	void MinMax_x(int, int, double&, double&);
	void MinMax_y(int, int, double&, double&);
	void MinMax_z(int, int, double&, double&);
	/* the smallest cube containing all N points
	 * input: N 3d points
	 * output: a cube (2 3d points)
	*/ 
	void GetBound();

	//Heap sort for GetNearBy
	void MinHeapify(vector<Distance> &,int,int);
	void HeapSort(vector<Distance> &, int);

	/* the nearest X points of point v_0
	* input: 3d point v_0, number X
	* output: X points
	*/
	Model GetNearBy(const Point3d, int);

	/* the points who are contained in cube b
	 * input: cube b(2 3d points)
	 * output: points
	*/
	Model GetContained(const Point3d, const Point3d);

	/* print all the points in model
	*/
	void print();
};