/* 
 * Author: Xiaodi
 * Date: 24/02/2017
 * Description: code for interview of MicroScene
 * Details here: https://github.com/everyang/interview/blob/master/READMD.md
 * Class: vector3d: data structure for a point with 3 dimentions(x,y,z)
*/


#pragma once

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Point3d{
public:
	double x, y, z;

	Point3d(){
		x = 0; 
		y = 0;
		z = 0;
	}

	Point3d(double _x, double _y, double _z){
		x = _x;
		y = _y;
		z = _z;
	}

	Point3d(const Point3d & a){
		x = a.x;
		y = a.y;
		z = a.z;
	}

	/* The distance with another point
	 * input: a point a
	 * output: distance in double
	*/
	double Distance(const Point3d & a){
		return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2) + pow(z - a.z, 2));
	}

	void swap(Point3d &a){
		Point3d temp(x, y, z);
		x = a.x;
		y = a.y;
		z = a.z;
		a.x = temp.x;
		a.y = temp.y;
		a.z = temp.z;
	}

	void print(){
		cout << x << " " << y << " " << z << endl;
	}
};