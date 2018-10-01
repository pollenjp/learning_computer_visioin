#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
std::string win_src = "src";
std::string win_dst = "dst";

#define IMAGE_DATA_PATH "../../../../image/building01.jpg"


//--------------------------------------------------------------------------------
// Main
//--------------------------------------------------------------------------------
int main()
{
  cv::Mat img_src = cv::imread(IMAGE_DATA_PATH,  // const String& filename
                               1);               // int           flags = IMREAD_COLOR 
  // https://docs.opencv.org/3.0-beta/modules/imgcodecs/doc/reading_and_writing_images.html?highlight=mat%20imread#Mat%20imread(const%20String&%20filename,%20int%20flags)
  cv::Mat img_gray, img_dst;

  if (!img_src.data){
    std::cout << "error" << std::endl;
    return -1;
  }

  cv::cvtColor(img_src,              // InputArray  src,
               img_gray,             // OutputArray dst,
               cv::COLOR_BGR2GRAY);  // int         code,
                                     // int         dstCn = 0
  img_src.copyTo(img_dst);

  std::vector<cv::Point2f> corners;
  cv::goodFeaturesToTrack(img_gray, corners, 1000, 0.1, 5);
  for (int i = 0; i < corners.size(); i++){
    cv::circle(img_dst,
               cv::Point(corners[i].x,
                         corners[i].y),
               3,
               cv::Scalar(0, 0, 255),
               2);
  }
  
  // create Window
  cv::namedWindow(win_src, cv::WINDOW_AUTOSIZE);
  cv::namedWindow(win_dst, cv::WINDOW_AUTOSIZE);

  // Display
  //  - https://docs.opencv.org/master/d7/dfc/group__highgui.html#ga8d86b207f7211250dbe6e28f76307ffb
  cv::imshow(win_src, img_src);
  cv::moveWindow(win_src,  20, 100);  

  cv::imshow(win_dst, img_dst);
  cv::moveWindow(win_dst, 500, 100);

  cv::waitKey(0);

  return 0;

}
