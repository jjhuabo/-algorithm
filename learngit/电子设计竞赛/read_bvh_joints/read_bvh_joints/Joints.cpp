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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
	string data;                                 //ÿһ�ж�ȡ������
	out.open(filename, ios::in);

	if (out.fail())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
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

//�ж��ǵڼ����ؽڣ����ں����������ȡ����Ӧ����ת��
void Joints::read_joint_name_lines(string joint_name) 
{
	_jointnumb = 0;
	fstream out;
	string data;
	const char *point;        //ָ��joint_name�ؽ�
	const char *pointtojoint; //ָ��Joint�ؼ���
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

//��ȡ�������ڵ��к�
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

//�Զ���ȡjoint�ؽڵ���ת��
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

//�Զ���ȡjoint�ؽڵ�Y����תֵ
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

//�Զ���ȡjoint�ؽڵ�Z����תֵ
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