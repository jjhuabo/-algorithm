/*
ʱ��:2018.05.17
˵��:�����ı��Ĵ�����Ӧ�ĺ�������˵��
ע��:��δ���ı��ı߽������������ƣ������쳣���д���
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

	//�����ؽ������ת��
	double Zrotation;
	double Xrotation;
	double Yrotation;

	string joint_name;
	string filename;

	vector<string> _strvec;                           //TXT�ļ�������
	vector<string> _jointmotiondatas;                 //������йؽ��˶�����

	//��ȡBVH�ļ�������
	int _linecounts;
	int _frame;                                       //֡��

	Joints(std::string filename);
	void read_joint_name_lines(string joint_name);     //��ȡ����Ĺؽ����ڵ��к�
	//void ResetLine(string filename, int line);       //��ȡָ������������
	void read_data_start_lines(string line);           //�����Ӹ��п�ʼ��ȡ����

	Joints(std::string filename, std::string joint_name);
	double readXroation(string joints);
	double readYroation(string joints);
	double readZroation(string joints);
	void movetonextframe(); //�ƶ�֡��
	//int returnFrame();      //

private:
	int _jointline;
	int _jointnumb;                                   //ָ���ؽ����ڱ��
	int _motiondatalinenumb;                          //motion �ؼ��������к�
	double stringTodouble(string str);
};

