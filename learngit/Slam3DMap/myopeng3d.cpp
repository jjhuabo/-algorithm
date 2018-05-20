/***************************************
���ߣ��ؼ̻�
���ڣ�2018.04.13
���ܣ���˼᰹�˾��SDK�еĵ�ͼͨ��OpenGL
      ����ά�ķ�ʽ������QT�ϡ�
****************************************/
#include<iostream>

#include <QString>
#include <string>
#include<vector>
#include <rpos/robot_platforms/slamware_core_platform.h>
#include <rpos/features/location_provider/map.h>
#include <rpos/core/core.h>
#include <rpos/system/types.h>
#include "myopeng3d.h"

using namespace std;

//int * pData = nullptr;
//BYTE * pData = nullptr;                                      //ָ����������,ע��ָ���ʽ

myopeng3d::myopeng3d(QWidget *parent)
	: QOpenGLWidget(parent)
{
	using namespace rpos::robot_platforms;
	SlamwareCorePlatform sdp = SlamwareCorePlatform::connect("192.168.11.1",1445);
	setWindowTitle("MY ROBOT:"+QString::fromStdString(sdp.getSDKVersion()));
}

void myopeng3d::initializeGL()
{
	initializeOpenGLFunctions();                             //���OpenGL�����ʼ��������ᱨ������
	//glClearColor(1.0, 1.0, 0.1, 0.1);
	glShadeModel(GL_SMOOTH);
	//glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_TEST);                                 //������Ȳ���
	glDepthFunc(GL_LEQUAL);                                  //������Ȳ�������
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);       //����͸��У��
}

void myopeng3d::resizeGL(int w, int h)
{
	Q_UNUSED(w);
	Q_UNUSED(h);
}

void myopeng3d::paintGL()
{
	GLubyte *pData;

	using namespace rpos::robot_platforms;
	SlamwareCorePlatform sdp = SlamwareCorePlatform::connect("192.168.11.1",1445);
	using namespace rpos::system::types;
	using namespace rpos::features;
	using namespace rpos::features::location_provider;
	rpos::core::RectangleF knowArea = sdp.getLocationProvider().getKnownArea(MapTypeBitmap8Bit, rpos::features::location_provider::EXPLORERMAP);
	location_provider::Map map = sdp.getMap(MapTypeBitmap8Bit, knowArea, rpos::features::location_provider::EXPLORERMAP);
	MapWid = map.getMapDimension().x();
	MapHeight = map.getMapDimension().y();

	vector<int> mapWid;
	vector<int> mapHeight;
	int t = sizeof(map.getMapData());
	GLubyte g[sizeof(map.getMapData())];
	for(int i = 0;i < t;i++)
	{
		//mapWid.push_back(map.getMapData()[])
		g[i] = map.getMapData()[i] + 127;
	}
	mapWid.push_back(MapWid);
	mapHeight.push_back(MapHeight);
	int _linelength = MapWid*sizeof(GLubyte);

	//while(_linelength %4 != 0)
	//{
	//	++_linelength;
	//}

	_linelength = _linelength * MapHeight;
	pData = (GLubyte*)malloc(_linelength);
	// �������
	for (int posY = 0; posY < MapHeight; ++posY)
	{
		for (int posX = 0; posX < MapWid; ++posX)
		{            
			// get map pixel
			rpos::system::types::_u8 mapValue_8bit = map.getMapData()[posX+ posY * MapWid] + 127;
			//rpos::system::types::_u8 mapValue_8bit = 128 + map.getMapData()[posX + (map.getMapDimension().y()-posY-1) * map.getMapDimension().x()];
			//fill the bitmap data
			//pData[posX+ posY*MapWid] = RGB(mapValue_8bit,mapValue_8bit,mapValue_8bit);
			pData[posX + posY*MapWid] = mapValue_8bit;
		}
	}

	GLubyte p[61][60][3];
	for (int posY = 0;posY<MapHeight;++posY)
	{
		for(int posX = 0;posX < MapWid;++posX)
		{
			for(int i = 0; i < 3;i++)
			{
				rpos::system::types::_u8 mapValue_8bit = map.getMapData()[posX+ posY * MapWid] + 127;
				//p[MapWid][MapHeight] =  RGB(mapValue_8bit,mapValue_8bit,mapValue_8bit);
				for(int i = 0;i<3;i++)
				{
					p[posY][posX][0] = mapValue_8bit;
					p[posY][posX][1] = mapValue_8bit;
					p[posY][posX][2] = mapValue_8bit;
				}

			}
		}
	}

		//��ԭ���ͼ  
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glTranslatef(-0.2,-0.35,0);
		//glColor3f(0.0F, 0.0f, 0.0f);
		glRasterPos2i(0.5,0.5);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);  
		glPixelZoom(5.0f,5.0f);                                     //�����ذ���x,y��ķ�����зŴ���С
	    //glDrawPixels(MapWid,MapHeight,GL_RGB,GL_BYTE,p);        
		// ��������
		glDrawPixels(MapWid, MapHeight,
			GL_BGR, GL_BYTE, g);

		//for(int i = 0;i<61;i++)
		//{
		//	glBitmap(1,60,0.0,0.0,25.0,0.0,p[i]);
		//}

		//free(pData);
}

myopeng3d::~myopeng3d()
{

}
