for(int b=0;b<len_data;b++)
		{   push.push_back(b);
		    push.push_back(0);
			data.push_back(push);
		}
		    float hold;

	        int qt,kt;
		int switched = 1;
		for( kt=0;kt<data.size()-1 && switched==1;kt++)
		{switched=0;
			for(qt=0; qt<data.size()-1-kt;qt++)
			{
				if(data[qt][0] > data[qt+1][0])
				{  switched=1;
				   hold=data[qt][0];
				   data[qt][0]=data[qt+1][0];
				   data[qt+1][0]=hold;
				   hold=data[qt][1];
				   data[qt][1]=data[qt+1][1];
				   data[qt+1][1]=hold;
				}
			}
		}

		for(kt=0;kt<data.size()-1;kt++)
		{
			if(data[kt][1]==0)
			{
				data[kt][1]=(data[kt+1][1]-data[kt-1][1])/(data[kt+1][0]-data[kt-1][0])*data[kt][0]+data[kt-1][1];
				outFile << 60/data[kt][1] << endl;
			}
		}
