#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long int ll;

struct edge{
	ll length;
	int count;
};

bool whichIsLonger(struct edge left,struct edge right){
	return left.length > right.length;
}

int main()
{
	int n;
	cin>>n;
	map<int,int> edgeMap;
	rep(i,n){
		ll num;
		cin>>num;
		if( edgeMap.count(num) == 0){
			edgeMap.insert(make_pair(num,1));
		}else{
			edgeMap[num]++;
		}
	}
	vector<struct edge> vec;
	for(auto iter = edgeMap.begin(); iter != edgeMap.end(); iter++){
		struct edge temp;
		temp.length = iter->first;
		temp.count = iter->second;
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end(),whichIsLonger);
	ll l1 = 0;
	ll l2 = 0;
	for(auto iter = vec.begin(); iter != vec.end(); iter++){
		if( l2 != 0) break;
		if(iter->count >= 4 && l1 == 0){
			l1 = iter->length;
			l2 = iter->length;
		}

		if(iter->count >= 2){
			l2 = l1;
			l1 = iter->length;
		}
	}
	cout<<l1 * l2<<endl;
	return 0;
}

