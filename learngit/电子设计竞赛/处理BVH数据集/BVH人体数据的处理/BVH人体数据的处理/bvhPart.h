#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
class ChannelError;

typedef vector<float> vector3f;

class bvhPart
{
public:
	bvhPart();
	~bvhPart();

	enum channelTypes
	{
		Xpos,Ypos,Zpos,Zrot,Yrot,Xrot
	};

	string name;
	vector3f offset;
	vector<matrix>                                                                                                                                       nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
};

