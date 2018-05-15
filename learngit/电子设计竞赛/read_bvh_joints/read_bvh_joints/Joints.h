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

	//�����ؽ������ת��
	double Zrotation;
	double Xrotation;
	double Yrotation;

	string joint_name;
	string filename;

	//��ȡBVH�ļ�������
	int _linecounts;
	int _jointline;
	int _jointnumb;                               //ָ���ؽ����ڱ��
	int _motionlinenumb;                          //motion �ؼ��������к�

	Joints(std::string filename);
	void read_joint_name_lines(string joint_name);//��ȡ����Ĺؽ����ڵ��к�
	Joints(std::string filename, std::string joint_name);

	
};

