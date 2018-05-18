/*
时间:2018.05.17
说明:用于文本的处理，对应的函数均有说明
注意:尚未对文本的边界条件进行限制，即对异常进行处理
*/
#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<fstream>
#include<vector>

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

	vector<string> _strvec;                           //TXT文件缓存区
	vector<string> _jointmotiondatas;                 //存放所有关节运动数据

	//读取BVH文件的行数
	int _linecounts;
	int _frame;                                       //帧数

	Joints(std::string filename);
	void read_joint_name_lines(string joint_name);     //读取输入的关节所在的行号
	//void ResetLine(string filename, int line);       //读取指定行数得内容
	void read_data_start_lines(string line);           //表明从该行开始读取数据

	Joints(std::string filename, std::string joint_name);
	double readXroation(string joints);
	double readYroation(string joints);
	double readZroation(string joints);
	void movetonextframe(); //移动帧数
	//int returnFrame();      //

private:
	int _jointline;
	int _jointnumb;                                   //指定关节所在编号
	int _motiondatalinenumb;                          //motion 关键字所在行号
	double stringTodouble(string str);
};

