#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <opencv2/gpu/gpu.hpp>

using namespace cv;
using namespace std;


int main()
{
    
    int len_data = 5033;
    float a,b;
    vector<float> ele;
    vector<vector<float>> data;

    fstream b_file("/Users/dutt/Movies/uf2/usehr2.txt");
    while(!b_file.eof())
    {
//        cout<<"in while loop"<<endl;
        b_file>>a>>b;                           //since there are teo numbers in a row, seperated by space;
//        cout<<a<<"\t"<<b<<endl;
        ele.push_back(a);
        ele.push_back(b);
        data.push_back(ele);
        ele.clear();
    }

    for(int i=1;i<len_data;i++)
    {
        ele.push_back(i);
        ele.push_back(-1);
        data.push_back(ele);
        ele.clear();
    }
  
    std::sort(data.begin(), data.end(),
              [](const std::vector<float>& a, const std::vector<float>& b) {
                  return a[0] < b[0];
              });
    cout<<"Values Placed and Sorted.. Press a Key"<<endl;
    getchar();
    
//    for(int k=0; k< data.size();k++)
//    {
//        cout<<data[k][0]<<"\t"<<data[k][1]<<endl;
//    }
    
    
    float x0,x1,y0,y1,x,a1,b1,y;

		for(int kt=0;kt<data.size()-1;kt++)
		{
			if(data[kt][1]==-1)
			{
                y1 = data[kt+1][1];
                y0 = data[kt-1][1];
                
                x1 = data[kt+1][0];
                x0 = data[kt-1][0];
                
                x = data[kt][0];
                
                a1 = (y1 - y0) / (x1 - x0);
                b1 = -a1*x0 + y0;
                y = a1*x + b1;
                
				data[kt][1] = y;
			}
		}
    cout<<"Values interpolated.. Press a Key"<<endl;
    getchar();
    for(int k=0; k< data.size();k++)
    {
        cout<<data[k][0]<<"\t"<<data[k][1]<<endl;
    }
}