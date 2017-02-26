#include "Point3d.h"
#include "Model.h"

using namespace std;

//void changeData(){
//	ifstream in("data.txt");
//	ofstream out("data3.txt");
//	double temp;
//	int count = 0;
//	while (!in.eof()){
//		count += 1;
//		in >> temp;
//		//cout << temp;
//		
//	}
//	cout << count <<" " << endl;
//	in.close();
//	out.close();
//}

int main(){

	Model mM;
	mM.GetData();
	mM.GetBound();


	
	Point3d v_min(-1, -7, -7.5), v_max(-0.5, -6.7, -7.2);
	Model v_in;
	v_in = mM.GetContained(v_min, v_max);
	v_in.print();

	return 0;
}