#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <random>

const long long INF = 10000000000000000;

using namespace std;

int main(){

	int N;
	cin>>N;
	
	long long tmp=0;
	int index=1;
	for(int i=1;i<=N;i++){
		tmp+=i;
		if(tmp>N){
			index=i;
			break;
		}
	}
	//cout<<tmp<<endl;
	long long del=tmp-N;
	for(int i=1;i<=index;i++){
		if(i==del) continue;
		else cout<<i<<endl;
	}
	return 0;	
}
