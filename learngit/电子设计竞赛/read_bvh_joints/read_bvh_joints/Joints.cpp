#include "stdafx.h"
#include "Joints.h"
#include<sstream>


Joints::Joints()
{

}


Joints::~Joints()
{
	this->_strvec.clear();
	this->_jointmotiondatas.clear();
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
		string result;
		stringstream input(_strvec[_motiondatalinenumb]);
		string data;
		while (!out.eof())
		{
			getline(out, data, '\n');
			_strvec.push_back(data);
		}
	}
}

Joints::Joints(string filename,string joint_name)
{
	this->_frame = 0;
	this->filename = filename;
	fstream out;
	string data;                                 //每一行读取得数据
	out.open(filename, ios::in);

	if (out.fail())
	{
		cout << "文件打开失败！" << endl;
	}
	else
	{
		read_joint_name_lines(joint_name);
		while (!out.eof())
		{

			getline(out, data, '\n');
			_strvec.push_back(data);
		}
	}

	out.close();
	read_data_start_lines(filename);
	string result;
	stringstream input(_strvec[_motiondatalinenumb+_frame]);

	while (input >> result)
	{
		_jointmotiondatas.push_back(result);
	}

	
		//for (int i = 0; i < _jointmotiondatas.size(); i++)
		//{
		//	cout << _jointmotiondatas[i];
		//}
		//cout << endl;
		//cout << _jointnumb << endl;
		//cout << (_jointnumb - 1) * 6 + 3 << endl;
		//cout << _motiondatalinenumb;

	Xrotation = stringTodouble(_jointmotiondatas[(_jointnumb - 1) * 6 + 3]);
	Yrotation = stringTodouble(_jointmotiondatas[(_jointnumb - 1) * 6 + 4]);
	Zrotation = stringTodouble(_jointmotiondatas[(_jointnumb - 1) * 6 + 5]);
}

//判断是第几个关节，便于后面从数据区取出相应得旋转角
void Joints::read_joint_name_lines(string joint_name) 
{
	_jointnumb = 0;
	fstream out;
	string data;
	const char *point;        //指向joint_name关节
	const char *pointtojoint; //指向Joint关键字
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

//读取数据所在得行号
void Joints::read_data_start_lines(string filename)
{
	string _frame = "Frame Time";
	string data;
	const char *p = nullptr;
	fstream out;
	out.open(filename, ios::in);

	while (!out.eof())
	{
		getline(out, data, '\n');
		p = strstr(data.c_str(), _frame.c_str());
		_motiondatalinenumb++;
		if (p != NULL)
		{
			//_motiondatalinenumb ++;
			break;
		}
	}

	out.close();
}

//自动读取joint关节得旋转角
double Joints::readXroation(string joint)
{
	_jointmotiondatas.clear();
	read_joint_name_lines(joint);

	string result;
	stringstream input(_strvec[_motiondatalinenumb+_frame]);

	while (input >> result)
	{
		_jointmotiondatas.push_back(result);
	}

	this->Xrotation = stringTodouble(_jointmotiondatas[(_jointnumb - 1) * 6 + 3]);
	return Xrotation;
}

//自动读取joint关节得Y轴旋转值
double Joints::readYroation(string joint)
{
	_jointmotiondatas.clear();
	read_joint_name_lines(joint);
	string result;
	stringstream input(_strvec[_motiondatalinenumb+_frame]);

	while (input >> result)
	{
		_jointmotiondatas.push_back(result);
	}

	this->Yrotation = stringTodouble(_jointmotiondatas[(_jointnumb - 1) * 6 + 4]);
	return Yrotation;
}

//自动读取joint关节得Z轴旋转值
double Joints::readZroation(string joint)
{
	_jointmotiondatas.clear();
	read_joint_name_lines(joint);
	string result;
	stringstream input(_strvec[_motiondatalinenumb+_frame]);

	while (input >> result)
	{
		_jointmotiondatas.push_back(result);
	}

	this->Zrotation = stringTodouble(_jointmotiondatas[(_jointnumb - 1) * 6 + 5]);
	return Zrotation;
}

void Joints::movetonextframe()
{
	_frame++;
}


double Joints::stringTodouble(string str)
{
	double a = atof(str.c_str());
	return a;
}