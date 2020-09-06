#include "SphereFilter.h"
#include <iostream>
#include <stdio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2\core\mat.hpp"
#include "opencv2/imgproc/imgproc.hpp"

bool SphereFilter::FilterShape(Sphere * i_ShapeToFilter, TwoWaysColor * io_Color, const std::string & ImagePath)
{
	
		cv::String cvstring = ImagePath;
		cv::Mat image, imagegry;
		image = cv::imread(cvstring, cv::IMREAD_COLOR);
	
		if (!image.data)                              // Check for invalid input
		{
			std::cout << "Could not open or find the image" << std::endl;
			return -1;
		}
		// Convert it to gray
		cv::cvtColor(image, imagegry,cv::COLOR_BGR2GRAY);
	
		// Reduce the noise so we avoid false circle detection
		cv::GaussianBlur(imagegry, imagegry, cv::Size(9, 9), 2, 2);
	
		std::vector<cv::Vec3f> circles;
	
		cv::HoughCircles(imagegry, circles,cv::HOUGH_GRADIENT, 1, imagegry.rows / 8, 200, 100, 0, 0);
	
		cv::Mat img_bw = imagegry > 160;

		
		Location loc;
		for (size_t i = 0; i < circles.size(); i++)
		{
			cv::Point center(circles[i][0], circles[i][1]);
			int radius = circles[i][2];
			// circle center
			circle(imagegry, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);
			// circle outline
			circle(imagegry, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);
			
			
			loc.m_X = center.x;
			loc.m_Y = center.y;
			
			i_ShapeToFilter->SetShapeLocation(loc);
			i_ShapeToFilter->SetRadius(radius);

			std::cout << "Pixel at position (x, y) : (" << loc.m_X << ", " << loc.m_Y << ") =" << img_bw.at<cv::Vec3b>(uchar(loc.m_Y), uchar(loc.m_X)) << std::endl;
			std::cout << "Pixel at position (x, y) : (" << loc.m_X - radius << ", " << loc.m_Y << ") =" << img_bw.at<cv::Vec3b>(uchar(loc.m_Y) ,uchar(loc.m_X - radius)) << std::endl;

			cv::Vec3b color = img_bw.at<cv::Vec3b>(uchar(loc.m_Y), uchar(loc.m_X));
			io_Color->SetInColor(BaseColor(color[0], color[1], color[2]));
			color = img_bw.at<cv::Vec3b>(uchar(loc.m_Y), uchar(loc.m_X-radius));
			io_Color->SetOutColor(BaseColor(color[0], color[1], color[2]));
			
			cv::putText(img_bw, "Color Of This Text Is The Outside Color", cv::Point(loc.m_X - radius, loc.m_Y),
				cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(io_Color->GetOutColor().GetRed(), io_Color->GetOutColor().GetGreen(), io_Color->GetOutColor().GetBlue()), 1);

			cv::putText(img_bw, "Color Of This Text Is The Inside Color", cv::Point(loc.m_X - radius, loc.m_Y - radius - 10),
				cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(io_Color->GetInColor().GetRed(), io_Color->GetInColor().GetGreen(), io_Color->GetInColor().GetBlue()), 1);


			break;
			 
		}

	

		cv::namedWindow("Colored", cv::WINDOW_AUTOSIZE);
		cv::imshow("Colored", image);

		cv::namedWindow("Black & White Color", cv::WINDOW_AUTOSIZE);
		cv::imshow("Black & White Color", img_bw);
		
		
		
		return true;


}

