#include "Model.h"

using namespace std;

void Model::GetData(){
	ifstream in("data.txt");
	Point3d temp;
	int count = 0;
	while (!in.eof()){
		if (count % 3 == 0) in >> temp.x;
		if (count % 3 == 1) in >> temp.y;
		if (count % 3 == 2) {
			in >> temp.z;
			model.push_back(temp);
		}
		count++;
	}
	in.close();
}

void Model::MinMax_x(int i, int j, double &min, double &max){
	int mid;
	double lmin, lmax, rmin, rmax;
	if (i == j){
		min = model[i].x;
		max = model[j].x;
	}
	else if (j == i + 1){
		if (model[i].x > model[j].x){
			min = model[j].x;
			max = model[i].x;
		}
		else{
			min = model[i].x;
			max = model[j].x;
		}
	}
	else{
		mid = (i + j) / 2;
		MinMax_x(i, mid, lmin, lmax);
		MinMax_x(mid + 1, j, rmin, rmax);
		min = (lmin > rmin) ? rmin : lmin;
		max = (lmax > rmax) ? lmax : rmax;
	}
}

void Model::MinMax_y(int i, int j, double &min, double &max){
	int mid;
	double lmin, lmax, rmin, rmax;
	if (i == j){
		min = model[i].y;
		max = model[j].y;
	}
	else if (j == i + 1){
		if (model[i].y > model[j].y){
			min = model[j].y;
			max = model[i].y;
		}
		else{
			min = model[i].y;
			max = model[j].y;
		}
	}
	else{
		mid = (i + j) / 2;
		MinMax_y(i, mid, lmin, lmax);
		MinMax_y(mid + 1, j, rmin, rmax);
		min = (lmin > rmin) ? rmin : lmin;
		max = (lmax > rmax) ? lmax : rmax;
	}
}

void Model::MinMax_z(int i, int j, double &min, double &max){
	int mid;
	double lmin, lmax, rmin, rmax;
	if (i == j){
		min = model[i].z;
		max = model[j].z;
	}
	else if (j == i + 1){
		if (model[i].z > model[j].z){
			min = model[j].z;
			max = model[i].z;
		}
		else{
			min = model[i].z;
			max = model[j].z;
		}
	}
	else{
		mid = (i + j) / 2;
		MinMax_z(i, mid, lmin, lmax);
		MinMax_z(mid + 1, j, rmin, rmax);
		min = (lmin > rmin) ? rmin : lmin;
		max = (lmax > rmax) ? lmax : rmax;
	}
}

void Model::GetBound(){
	cout << endl << "====The smallest cube for all N points====" << endl;

	Point3d min, max;

	MinMax_x(0, model.size() - 1, min.x, max.x);
	MinMax_y(0, model.size() - 1, min.y, max.y);
	MinMax_z(0, model.size() - 1, min.z, max.z);

	cout << "v_min = "; min.print();
	cout << "v_max = "; max.print();
	
}

void Model::MinHeapify(vector<Distance> &a, int k, int n){
	int i = k;
	int j = 2 * i; //left child of i
	while (j < n){
		if (j<n && a[j].d < a[j + 1].d){
			j++;
		}
		if (a[i].d > a[j].d){
			break;
		}
		else{
			a[i].swap(a[j]);
			i = j;
			j = 2 * i;
		}
	}
}

void Model::HeapSort(vector<Distance> &a, int n){
	for (int i = n / 2 ; i >= 1; i--){
		MinHeapify(a, i, n);
	}
	for (int i = 1; i < n; i++){
		a[0].swap(a[n-i +1]);
		MinHeapify(a, 0, n-i );
	}
}

Model Model::GetNearBy(Point3d v_0, int X){
	cout << endl << "====The nearest X points of v_0====" << endl;
	cout << "v_0 = "; v_0.print();
	cout << "X = " << X << endl;
	vector<Distance> dt;
	Distance temp;
	for (int i = 0; i < model.size(); i++){
		temp.d = model[i].Distance(v_0);
		temp.index = i;
		dt.push_back(temp);
	}

	Model nb;
	HeapSort(dt, model.size() -1 );
	for (int i = 0; i < X; i++){
		//dt[i].print();
		nb.model.push_back(model[dt[i].index]);
	}

	return nb;
}

Model Model::GetContained(Point3d v_min, Point3d v_max){
	cout << endl << "====Points in cube v_min & v_max====" << endl;
	cout << "v_min = "; v_min.print();
	cout << "v_max = "; v_max.print();
	Model temp;
	for (int i = 0; i < model.size(); i++){
		//here is the simplest way in this certain case: the edges of the cube are parallel to the coordinate axes
		//if the cube isn't parallel to the axes, have to concern about the normal vector of each plane, and then compare the dot product of two vectors
		if ((model[i].x < v_max.x) && (model[i].x > v_min.x) &&
			(model[i].y < v_max.y) && (model[i].y > v_min.y) &&
			(model[i].z < v_max.z) && (model[i].z > v_min.z)){
			temp.model.push_back(model[i]);
		}
	}
	return temp;
}


void Model::print(){
	for (int i = 0; i < model.size(); i++){
		model[i].print();
	}
}