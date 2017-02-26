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

void Model::GetBound(){
	Point3d min, max;

	for (int i = 0; i < model.size(); i++){
		if (min.x > model[i].x) min.x = model[i].x;
		if (min.y > model[i].y) min.y = model[i].y;
		if (min.z > model[i].z) min.z = model[i].z;
		if (max.x < model[i].x) max.x = model[i].x;
		if (max.y < model[i].y) max.y = model[i].y;
		if (max.z < model[i].z) max.z = model[i].z;
	}

	cout << "min = "; min.print();
	cout << "max = "; max.print();
	
}


Model Model::GetNearBy(const Point3d v_0, int X){
	vector<double> D;
	for (int i = 0; i < model.size(); i++){
		D.push_back(model[i].Distance(v_0));
	}
	Model temp;
	return temp;
}

Model Model::GetContained(Point3d v_min, Point3d v_max){
	Model temp;
	for (int i = 0; i < model.size(); i++){
		if ((model[i].x < v_max.x) && (model[i].x > v_min.x) &&
			(model[i].y < v_max.y) && (model[i].y > v_min.y) &&
			(model[i].z < v_max.z) && (model[i].z > v_min.z)){
			temp.model.push_back(model[i]);
			//model[i].print();
		}
	}
	//temp.print();
	return temp;
}



void Model::print(){
	for (int i = 0; i < model.size(); i++){
		model[i].print();
	}
}