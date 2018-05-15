#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<fstream>
using namespace std;
class Joints
{
public:
	Joints();
	~Joints();

	//各个关节轴的旋转量
	double Zrotation;
	double Xrotation;
	double Yrotation;

	string joint_name;
	string filename;

	//读取BVH文件的行数
	int _linecounts;
	int _jointline;
	int _jointnumb;                               //指定关节所在编号
	int _motionlinenumb;                          //motion 关键字所在行号

	Joints(std::string filename);
	void read_joint_name_lines(string joint_name);//读取输入的关节所在的行号
	Joints(std::string filename, std::string joint_name);

	
};

