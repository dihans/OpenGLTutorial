/* {                                                              } 
   { �������� BMP ������ �о� ���� ������ �Ѵ�.                     }
   { ���� ����� ����.                                             }
   { ��Ÿ ������� BMP ������ ���� �б� ����                        }
   {                                                              }
   { ���� : �輺ö( paranwave@korea.com )                         }
   {                                                              } */
#ifndef _EGL_DIB_H_
#define _EGL_DIB_H_

#include <windows.h>

class eglDib
{
protected:
	LPBITMAPFILEHEADER mBMPFileHeader;
	LPBITMAPINFO	   mBMPInfo;
	LPBITMAPINFOHEADER mBMPInfoHeader;
	RGBQUAD			   *mRGBTable;
	BYTE			   *mRawData;
	UINT			   mNumColors;
	BOOL LoadBitmapFromFile(const char * filename);
	void CreateLogicalPallete(void);
	eglDib();
	
public:
	float RedPal[256], GreenPal[256], BluePal[256];

	eglDib(const char * filename);
	~eglDib(void);
	DWORD GetImageSize(void);
	UINT  GetWidth(void);
	UINT  GetHeight(void);
	UINT  GetNumChannels(void);
	UINT  GetNumColors(void);
	UINT  GetPixelDepth(void);
	LPBITMAPINFOHEADER GetInfoHeaderPtr(void);
	LPBITMAPINFO GetInfoPtr(void);
	LPRGBQUAD GetRGBTablePtr(void);
	BYTE* GetRawData(void);
};


#endif