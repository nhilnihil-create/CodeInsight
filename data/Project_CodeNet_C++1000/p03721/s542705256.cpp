#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef unsigned long long int ll;

struct numberNode{
	int a;
	ll b;
};

bool comp(numberNode LHS,numberNode RHS){
	return LHS.a < RHS.a;
}


int main()
{
	int n;
	ll k;
	cin>>n>>k;
	map<int,ll> bigArray;
	for(int i = 0; i < n; i++){
		int a;
		ll b;
		cin>>a>>b;
		if(bigArray.count(a)==0){
			bigArray.insert(make_pair(a,b));
		}else{
			bigArray[a] += b;
		}
	}
	vector<numberNode> bigVector;
	for(auto iter = bigArray.begin(); iter != bigArray.end(); iter++){
		numberNode localNode;
		localNode.a = iter->first;
		localNode.b = iter->second;
		bigVector.push_back(localNode);
	}
	sort(bigVector.begin(),bigVector.end(),comp);
	for(auto iter = bigVector.begin(); iter!= bigVector.end();iter++){
		if( k <= iter->b){
			cout<<iter->a<<endl;
			break;
		}else{
			k = k - iter->b;
		}
	}
	return 0;
}
