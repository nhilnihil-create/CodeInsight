
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
	for(int64_t i1=0;i1<a;i1++){
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

int main(){
	int64_t n,m;
	cin>>n>>m;
	vector<vector<int64_t> > a;
	read_2d (a,n,m);
	vector<bool> held;
	held.resize(m);
	fill(held.begin(),held.end(),true);
	int64_t ans=INF;
	vector<int64_t> count;
	count.resize(m);
	while(true){
		if(find(held.begin(),held.end(),true)==held.end()){
			break;
		}

		fill(count.begin(),count.end(),0);
		for(auto i1=a.begin();i1!=a.end();i1++){
			for(auto i2=i1->begin();i2!=i1->end();i2++){
				if(held.at((*i2)-1)){
					count[(*i2)-1]++;
					break;
				}
			}
		}
		int64_t c_ans=*max_element(count.begin(),count.end());
		if(c_ans<ans){
			ans=c_ans;
		}
		int64_t max_index=max_element(count.begin(),count.end())-count.begin();
		held[max_index]=false;
	}
	cout<<ans<<endl;
}
