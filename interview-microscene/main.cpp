#include "Point3d.h"
#include "Model.h"

using namespace std;


int main(){


	Model mM;
	mM.GetData();

	//n¡ã1
	mM.GetBound();

	//n¡ã2
	Point3d v_0(-1, -10, -8);
	Model v_near;
	v_near = mM.GetNearBy(v_0, 10);
	v_near.print();
	
	//n¡ã3
	Point3d v_min(-1, -7, -7.5), v_max(-0.5, -6.7, -7.2);
	Model v_in;
	v_in = mM.GetContained(v_min, v_max);
	v_in.print();

	return 0;
}
