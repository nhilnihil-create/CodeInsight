
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
template<class T>
void read_1d(std::vector<T>& a,int64_t num){
	a.reserve(num);
	for(int64_t i1=0;i1<num;i1++){
		T temp;
		cin>>temp;
		a.push_back(temp);
	}
}
template<class T>
void read_2d(std::vector<std::vector<T> >&a,int64_t x,int64_t y ){
	a.resize(x);
	for(int64_t i1=0;i1<x;i1++){
		a[i1].reserve(y);
		for(int64_t i2=0;i2<y;i2++){
			T temp;
			cin>>temp;
			a[i1].push_back(temp);
		}
	}
}
template<class InputIterator>
void debug(InputIterator first,InputIterator last){
	for(auto i1=first;i1!=last;i1++){
		cout<<(*i1)<<endl;
	}
}

int main(){
	int64_t n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	n--;
	b=b-a;
	int64_t max_num=n*d;
	int64_t min_num=n*c;
	bool possible=false;
	for(int64_t i1=0;i1<n+1;i1++){
		if(min_num<=b&&b<=max_num){
			possible=true;
			break;
		}else{
			min_num-=(d+c);
			max_num-=(d+c);
		}
	}
	if(possible){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}
