// read_bvh_joints.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Joints.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;


int main()
{
	string filename = "D:\\电子设计竞赛\\人体关节数据集\\s1_vicon_bvh\\S1\\acting1_BlenderZXY_YmZ.bvh";
	string joint = "Spine";
	Joints cpp =  Joints(filename, joint);
	//cout << cpp._motiondatalinenumb << endl;
	//cout << cpp._jointnumb << endl;
	cout << cpp.Xrotation << cpp.Yrotation<<cpp.Zrotation<<endl;
	string joint2 = "Spine1";
	Joints cpp1 = Joints(filename, joint2);
	cout << cpp1.Xrotation << endl;
	system("pause");
    return 0;

}

