#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <math.h>

using namespace cv;
using namespace std;

Mat img,img1;

int box(Mat img,int arr[],int ratio)
{
	if(ratio==2)
	{
		int c=img.rows*img.cols/8;
		
		for(int i=0;i<img.rows/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j,i)==255)
					arr[0]++;
		}
		for(int i=0;i<img.rows/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j+img.cols/2,i)==255)
					arr[1]++;
		}
		
		for(int i=0;i<img.rows/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j,i+img.rows/4)==255)
					arr[2]++;
		}
		for(int i=0;i<img.rows/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j+img.cols/2,i+img.rows/4)==255)
					arr[3]++;
		}
		for(int i=0;i<img.rows/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j,i+img.rows/2)==255)
					arr[4]++;
		}
		for(int i=0;i<img.rows/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j+img.cols/2,i+img.rows/2)==255)
					arr[5]++;
		}
		for(int i=0;i<img.rows/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j,i+3*img.rows/4)==255)
					arr[6]++;
		}
		for(int i=0;i<img.rows/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j+img.cols/2,i+3*img.rows/4)==255)
					arr[7]++;
		}
		
		for(int i=0;i<8;i++)
		{
			arr[i]=100*arr[i]/c;
			if(arr[i]>75)
				arr[i]=1;
		}

		return 8;
	}

	else if(ratio==-2)
	{
		int c=img.rows*img.cols/8;
		
		for(int i=0;i<img.cols/4;i++)
		{
			for(int j=0;j<img.rows/2;j++)
				if(img.at<uchar>(i,j)==255)
					arr[0]++;
		}
		for(int i=0;i<img.cols/4;i++)
		{
			for(int j=0;j<img.rows/2;j++)
				if(img.at<uchar>(i+img.rows/2,j)==255)
					arr[1]++;
		}
		
		for(int i=0;i<img.cols/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(i,j+img.cols/4)==255)
					arr[2]++;
		}
		for(int i=0;i<img.cols/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(i+img.rows/2,j+img.cols/4)==255)
					arr[3]++;
		}
		for(int i=0;i<img.cols/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(i,j+img.cols/2)==255)
					arr[4]++;
		}
		for(int i=0;i<img.cols/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(i+img.rows/2,j+img.cols/2)==255)
					arr[5]++;
		}
		for(int i=0;i<img.cols/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(i,j+3*img.cols/4)==255)
					arr[6]++;
		}
		for(int i=0;i<img.cols/4;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(i+img.rows/2,j+3*img.cols/4)==255)
					arr[7]++;
		}
		
		for(int i=0;i<8;i++)
		{
			arr[i]=100*arr[i]/c;
			if(arr[i]>75)
				arr[i]=1;
		}

		return 8;
	}

	else if(ratio==5)
	{
		for(int i=0;i<img.rows/5;i++)
		{
			for(int j=0;j<img.cols;j++)
				if(img.at<uchar>(j,i)==255)
					arr[0]++;
		}
		for(int i=0;i<img.rows/5;i++)
		{
			for(int j=0;j<img.cols;j++)
				if(img.at<uchar>(j,i+img.rows/5)==255)
					arr[1]++;
		}
		for(int i=0;i<img.rows/5;i++)
		{
			for(int j=0;j<img.cols;j++)
				if(img.at<uchar>(j,i+2*img.rows/5)==255)
					arr[2]++;
		}
		for(int i=0;i<img.rows/5;i++)
		{
			for(int j=0;j<img.cols;j++)
				if(img.at<uchar>(j,i+3*img.rows/5)==255)
					arr[3]++;
		}
		for(int i=0;i<img.rows/5;i++)
		{
			for(int j=0;j<img.cols;j++)
				if(img.at<uchar>(j,i+4*img.rows/5)==255)
					arr[4]++;
		}

		return 5;

	}

	else if(ratio==-5)
	{
		for(int i=0;i<img.cols/5;i++)
		{
			for(int j=0;j<img.rows;j++)
				if(img.at<uchar>(i,j)==255)
					arr[0]++;
		}
		for(int i=0;i<img.cols/5;i++)
		{
			for(int j=0;j<img.rows;j++)
				if(img.at<uchar>(i,j+img.rows/5)==255)
					arr[1]++;
		}
		for(int i=0;i<img.cols/5;i++)
		{
			for(int j=0;j<img.rows;j++)
				if(img.at<uchar>(i,j+2*img.rows/5)==255)
					arr[2]++;
		}
		for(int i=0;i<img.cols/5;i++)
		{
			for(int j=0;j<img.rows;j++)
				if(img.at<uchar>(i,j+3*img.rows/5)==255)
					arr[3]++;
		}
		for(int i=0;i<img.cols/5;i++)
		{
			for(int j=0;j<img.rows;j++)
				if(img.at<uchar>(i,j+4*img.rows/5)==255)
					arr[4]++;
		}

		return 5;

	}

	else if((ratio)==1)
	{
		float a=1.3;
		if(((float)img.rows/img.cols)>=a)
		{
			for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j,i)==255)
					arr[0]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j+img.cols/2,i)==255)
					arr[1]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j,i+img.rows/3)==255)
					arr[2]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j+img.cols/2,i+img.rows/3)==255)
					arr[3]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j,i+2*img.rows/3)==255)
					arr[4]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/2;j++)
				if(img.at<uchar>(j+img.cols/2,i+2*img.rows/3)==255)
					arr[5]++;
		}

		return 6;
		}

		else
		{
			for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/3;j++)
				if(img.at<uchar>(j,i)==255)
					arr[0]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/3;j++)
				if(img.at<uchar>(j+img.cols/3,i)==255)
					arr[1]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/3;j++)
				if(img.at<uchar>(j+2*img.cols/3,i)==255)
					arr[2]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/3;j++)
				if(img.at<uchar>(j,i+img.rows/3)==255)
					arr[3]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/3;j++)
				if(img.at<uchar>(j+img.cols/3,i+img.rows/3)==255)
					arr[4]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/3;j++)
				if(img.at<uchar>(j+2*img.cols/3,i+img.rows/3)==255)
					arr[5]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/3;j++)
				if(img.at<uchar>(j,i+2*img.rows/3)==255)
					arr[6]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/3;j++)
				if(img.at<uchar>(j+img.cols/3,i+2*img.rows/3)==255)
					arr[7]++;
		}
		for(int i=0;i<img.rows/3;i++)
		{
			for(int j=0;j<img.cols/3;j++)
				if(img.at<uchar>(j+2*img.cols/3,i+2*img.rows/3)==255)
					arr[8]++;
		}

		return 9;
		}
	}

	else if((ratio)==-1)
	{
		float a=1.3;
		if(((float)img.cols/img.rows)>=a)
		{
			for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/2;j++)
				if(img.at<uchar>(i,j)==255)
					arr[0]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/2;j++)
				if(img.at<uchar>(i+img.rows/2,j)==255)
					arr[1]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/2;j++)
				if(img.at<uchar>(i,j+img.cols/3)==255)
					arr[2]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/2;j++)
				if(img.at<uchar>(i+img.rows/2,j+img.cols/3)==255)
					arr[3]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/2;j++)
				if(img.at<uchar>(i,j+2*img.cols/3)==255)
					arr[4]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/2;j++)
				if(img.at<uchar>(i+img.rows/2,j+2*img.cols/3)==255)
					arr[5]++;
		}

		return 6;
		}

		else
		{
			for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/3;j++)
				if(img.at<uchar>(i,j)==255)
					arr[0]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/3;j++)
				if(img.at<uchar>(i+img.rows/3,j)==255)
					arr[1]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/3;j++)
				if(img.at<uchar>(i+2*img.rows/3,j)==255)
					arr[2]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/3;j++)
				if(img.at<uchar>(i,j+img.cols/3)==255)
					arr[3]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/3;j++)
				if(img.at<uchar>(i+img.rows/3,j+img.cols/3)==255)
					arr[4]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/3;j++)
				if(img.at<uchar>(i+2*img.rows/3,j+img.cols/3)==255)
					arr[5]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/3;j++)
				if(img.at<uchar>(i,j+2*img.cols/3)==255)
					arr[6]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/3;j++)
				if(img.at<uchar>(i+img.rows/3,j+2*img.cols/3)==255)
					arr[7]++;
		}
		for(int i=0;i<img.cols/3;i++)
		{
			for(int j=0;j<img.rows/3;j++)
				if(img.at<uchar>(i+2*img.rows/3,j+2*img.cols/3)==255)
					arr[8]++;
		}

		return 9;
		}
	}
}

int check(Mat temp1,Mat temp2)
{
	int ratio1,ratio2,size1,size2;
	if(temp1.rows>temp1.cols)
		ratio1=temp1.rows/temp1.cols;	
	else
		ratio1=-temp1.rows/temp1.cols;
	if(temp2.rows>temp2.cols)
		ratio2=temp2.rows/temp2.cols;	
	else
		ratio2=-temp2.rows/temp2.cols;
	int arr1[10],arr2[10];
	for(int i=0;i<10;i++)
	{
		arr1[i]=0;arr2[i]=0;
	}
	size1=box(temp1,arr1,ratio1);
	size2=box(temp2,arr2,ratio2);

	if(size1!=size2)
		return 0;
	else
	{
		for(int i=0;i<size1;i++)
			if(arr1[i]!=arr2[i])
				return 0;
		return 1;	
	}

}


void extract(Mat img,Mat arr[])
{
	Mat gray(img.rows, img.cols, CV_8UC1);
	cvtColor(img, gray, CV_BGR2GRAY);
	Mat img1(img.rows, img.cols, CV_8UC1,Scalar(0));
	Canny(gray, gray, 50, 100);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(gray, contours, hierarchy,RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	drawContours(img1, contours, -1,255,-1);
	
	for (int i = 0; i < contours.size(); i++)
	{
		Rect r = boundingRect(contours[i]);
		rectangle(img1, r, 127);
		img1(r).copyTo(arr[i]);
		//imshow("w", arr[i]);
	}
	
}


int main()
{
	
	img = imread("arena32.png", 1);
	img1=imread("final.png",1);
	
	Mat arr1[6];
	Mat arr2[4];

	extract(img,arr1);
	extract(img1,arr2);

	for(int i=0;i<6;i++)
		for(int j=0;j<4;j++)
		{
			printf("%d with %d makes %d",i+1,j+1,check(arr1[i],arr2[j]));
		}

	waitKey(0);
}

/*void box(Mat img,int arr[],int ratio)
{
		if(fabs(ratio)==1)
		{
			//box is 3x3
			arr[0]=0;arr[4]=0;arr[8]=0
			for(int i=0;i<img.rows/3;i++)
			{
				if(img.at<uchar>(i,i)==255)
					arr[0]++;
				if(img.at<uchar>(i+img.rows/3,i+img.rows/3)==255)
					arr[4]++;
				if(img.at<uchar>(img.rows/3 -i,img.rows/3 -i)==255)
					arr[8]++;
			}
			arr[0]=(300*arr[0])/img.rows;
			arr[4]=(300*arr[4])/img.rows;
			arr[8]=(300*arr[8])/img.rows;

			for(int i=0;i<img.rows/3;i++)
			{
				int j=i-img.cols/3;
				if(img.at<uchar>(i,j)==255)
					arr[1]++;
				if(img.at<uchar>(i+img.cols/3,j+img.rows/3)==255)
					arr[5]++;
			}
			arr[1]=(300*arr[1])/img.rows;
			arr[5]=(300*arr[5])/img.rows;

			for(int i=0;i<img.rows/3;i++)
			{
				int j=i+img.cols/3;
				if(img.at<uchar>(i,j)==255)
					arr[3]++;
				if(img.at<uchar>(i+img.cols/3,j+img.rows/3)==255)
					arr[7]++;
			}
			arr[3]=(300*arr[3])/img.rows;
			arr[7]=(300*arr[7])/img.rows;

			for(int i=0;i<img.rows/3;i++)
			{
				int j=i-2*img.cols/3;
				if(img.at<uchar>(i,j)==255)
					arr[2]++;
			}
			arr[2]=(300*arr[2])/img.rows;

			for(int i=0;i<img.rows/3;i++)
			{
				int j=i+2*img.cols/3;
				if(img.at<uchar>(i,j)==255)
					arr[6]++;
			}
			arr[6]=(300*arr[6])/img.rows;

		}

		else if(fabs(ratio)==2)
		{
				for(int i=0;i<img.rows/3;i++)
			{
				int j=i-img.cols/3;
				if(img.at<uchar>(i,j)==255)
					arr[1]++;
				if(img.at<uchar>(i+img.cols/3,j+img.rows/3)==255)
					arr[5]++;
			}
			arr[1]=(300*arr[1])/img.rows;
			arr[5]=(300*arr[5])/img.rows;
		}
}*/