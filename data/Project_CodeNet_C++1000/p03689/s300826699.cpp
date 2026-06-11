
#include <time.h>

#include <stdlib.h>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <bitset>

using namespace std;
const int64_t INF=10000000000000000;

int main(){
	int64_t h_size,w_size,h,w;
	cin>>h_size>>w_size>>h>>w;
	int64_t ans[h_size][w_size];
	if(h_size%h==0&&w_size%w==0){
		cout<<"No"<<endl;
	}else{
		int64_t sum=0;
		int64_t T=(1000000000-1)/(h*w-1);
		for(int64_t i1=0;i1<h_size;i1++){
			for(int64_t i2=0;i2<w_size;i2++){
				if(i1%h==(h-1)&&i2%w==(w-1)){
					ans[i1][i2]=-((h*w-1)*T+1);
					sum-=((h*w-1)*T+1);
				}else{
					ans[i1][i2]=T;
					sum+=T;
				}
			}
		}
		if(sum>0){
			cout<<"Yes"<<endl;
			for(int64_t i1=0;i1<h_size;i1++){
				for(int64_t i2=0;i2<w_size;i2++){
					cout<<ans[i1][i2]<<" ";
				}
				cout<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}

	}
}
