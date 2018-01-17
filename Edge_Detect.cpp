#include <opencv2/core.hpp> // Edge Detection Algorithms- Laplace,Sobel,Canny 
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include<cv.h>
using namespace cv;
using namespace std;


Mat Laplace(const char* filename) // LAPLACE
{ namedWindow( "Input Image", WINDOW_AUTOSIZE ); 
  namedWindow( "Laplacian", WINDOW_AUTOSIZE );

Mat I = imread(filename, CV_LOAD_IMAGE_GRAYSCALE); // Input Image for Laplacian
imshow("Input Image",I); 

IplImage tmp=I; // Converting cv::Mat to CvArr*
cvLaplace(&tmp,&tmp,3); // Kernel:3
cv::Mat lap = cv::cvarrToMat(&tmp);  // Laplacian

imshow("Laplacian",lap);
waitKey(0);

imwrite( "/home/welcome/cv_test/EdgeDetect_HemanthBalajiDandi/Laplacian.jpg",lap);
return lap;
}

Mat Sobel(const char* filename) // SOBEL
{ namedWindow( "Input Image", WINDOW_AUTOSIZE ); 
  namedWindow( "Sobel", WINDOW_AUTOSIZE ); 

Mat J = imread(filename, CV_LOAD_IMAGE_GRAYSCALE); // Input Image for Laplacian
imshow("Input Image",J);

IplImage tmp1=J; // Converting cv::Mat to CvArr*
cvSobel(&tmp1,&tmp1,1,1,3); // X-Order=1, Y-Order=1, Kernel=3
cv::Mat sob = cv::cvarrToMat(&tmp1); // Sobel

imshow("Sobel",sob);
waitKey(0);

imwrite( "/home/welcome/cv_test/EdgeDetect_HemanthBalajiDandi/Sobel.jpg",sob);
return sob;
}

Mat Canny(const char* filename) // CANNY
{ namedWindow( "Input Image", WINDOW_AUTOSIZE ); 
  namedWindow( "Canny", WINDOW_AUTOSIZE ); 

Mat K = imread(filename, CV_LOAD_IMAGE_GRAYSCALE); // Input Image for Laplacian
imshow("Input Image",K);

IplImage tmp2=K; // Converting cv::Mat to CvArr*
cvCanny(&tmp2,&tmp2,60,180); // Lower-Threshold Value=60, Upper-Threshold Value=180
cv::Mat can = cv::cvarrToMat(&tmp2); // Canny

imshow("Canny",can);
waitKey(0);

imwrite( "/home/welcome/cv_test/EdgeDetect_HemanthBalajiDandi/Canny.jpg",can);
return can;
}


int main()
{ int l;
  m :cout<<"\n \t \t \tWelcome to the world of Edge Detections!";
  cout<<"\nWhich Function would you like to first perform?";
  cout<<"\n 1.Laplace \t 2.Sobel \t 3.Canny \t 4.Abort"<<endl;
  cin>>l;
  
  switch(l)
{
  case 1: Laplace("/home/welcome/cv_test/bird.jpg");
          goto m;
  case 2: Sobel("/home/welcome/cv_test/bird.jpg");
          goto m;
  case 3: Canny("/home/welcome/cv_test/bird.jpg");
          goto m;
  case 4 :abort();
  
}
return 0;
}

