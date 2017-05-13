#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

Mat img,arena;
int row,col;
vector <vector <Point> > contours;
vector<Rect> bound; 
vector <vector <Point> > contours2;

Point matchingMethod(Mat src, Mat temp,double *min){
	Mat result;

	int result_cols =  src.cols - temp.cols + 1;
	int result_rows = src.rows - temp.rows + 1;

	result.create( result_rows, result_cols, CV_32FC1 );

	matchTemplate( src, temp, result, 2 );
	//normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

   double minVal, maxVal; 
   Point minLoc, maxLoc;

   minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
    
   *min=maxVal;
   cout<<"orignal : "<<maxVal<<endl;
   return maxLoc;

}

Mat get_size(){
	Mat temp;
	
	cvtColor(arena,temp,CV_BGR2GRAY);
	Canny(temp,temp,50,100);
	findContours(temp,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
	
	for(int i=0;i<contours.size();i++){
		bound.push_back(boundingRect(Mat(contours[i])));
	}

	Mat dst(temp.rows,temp.cols,CV_8UC1,Scalar(0));
	drawContours(dst,contours,-1,Scalar(255));
	return dst;
}

void find_pattern(){

	Point p,final;
	double min,m_min;
	Mat temp1,img_temp;
	int dim1,dim2;

	cvtColor(img,temp1,CV_BGR2GRAY);
	Canny(temp1,temp1,50,100);
	findContours(temp1,contours2,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
		

	Mat dst(temp1.rows,temp1.cols,CV_8UC1,Scalar(0));
	drawContours(dst,contours2,-1,Scalar(255));
	
	Mat img_ROI=dst(boundingRect(Mat(contours2[24])));
	

	Mat temp2=get_size();

	for(int i=0;i<bound.size();i++){
		if(contourArea(contours[i])>100){
			resize(img_ROI,img_temp,Size(bound[i].br().x-bound[i].tl().x , bound[i].br().y-bound[i].tl().y));
			p=matchingMethod(temp2,img_temp,&min);
			cout<<p.x<<" "<<p.y<<endl;
			cout<<min<<endl;
			if(i==0){
				m_min=min;
				final=p;
				dim1=bound[i].br().x-bound[i].tl().x;
				dim2=bound[i].br().y-bound[i].tl().y;
				imshow("resized object",img_temp);
			}
			else if(min>m_min){
				m_min=min;
				final=p;
				dim1=bound[i].br().x-bound[i].tl().x;
				dim2=bound[i].br().y-bound[i].tl().y;
			}
		}
	}

	
	cout<<"\n\n"<<final.x<<" "<<final.y<<endl;
	rectangle( temp2, final,Point(final.x+dim1,final.y+dim2), Scalar::all(255), 2, 8, 0 );
  	cout << "final" << final.x << " " << final.y << "\n";
  	cout << "final1" << final.x + dim1 << " " << final.y + dim2;

  	imshow( "image_window", temp2 );
  	imshow( "result_window", img );
  	imshow( "template", img_ROI );

}


int main(){
    img=imread("final.png",1);
    arena=imread("arena32.png",1);


    find_pattern();
    waitKey(0);
    return 0;
}
