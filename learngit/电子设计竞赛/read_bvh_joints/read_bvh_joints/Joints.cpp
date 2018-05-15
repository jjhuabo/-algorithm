#include "stdafx.h"
#include "Joints.h"


Joints::Joints()
{
}


Joints::~Joints()
{
}

Joints::Joints(string filename)
{
	this->filename = filename;
	fstream out;
	out.open(filename, ios::in);
	if (out.fail())
	{
		cout << "文件打开失败！" << endl;
	}
	else
	{

	}
}

Joints::Joints(string filename,string joint_name)
{
	this->filename = filename;
	fstream out;
	string data;                                 //每一行读取得数据
	string _frame = "Frame Time";
	out.open(filename, ios::in);
	const char *p = nullptr;
	getline(out, data, '\n');
	p = strstr(data.c_str(), _frame.c_str());

	if (out.fail())
	{
		cout << "文件打开失败！" << endl;
	}
	else
	{
		read_joint_name_lines(joint_name);
		while (!out.eof())
		{
			if (p != NULL)
			{
				
			}
		}
	}
}

void Joints::read_joint_name_lines(string joint_name) 
{
	fstream out;
	string data;
	const char *point;
	const char *pointtojoint; //指向joints关键字
	string joint = "JOINT";

	out.open(filename, ios::in);
	while (!out.eof())
	{
		getline(out, data, '\n');
		point = strstr(data.c_str(), joint_name.c_str());
		pointtojoint = strstr(data.c_str(), joint.c_str());
		if (pointtojoint != NULL)
		{
			_jointnumb++;
			if (point != NULL)
			{
				_jointnumb++;
				out.close();
				break;
			}
		}
	}

}
