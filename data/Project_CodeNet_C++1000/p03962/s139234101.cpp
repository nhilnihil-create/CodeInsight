#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>
#include<bits/stdc++.h>
#define long long
using namespace std;

int main(){
	int a,b,c,sum=3;
	cin>>a>>b>>c;
	if(a==b){
		sum--;
		if(a==c){
			sum--;
		}
	}
	else{
		if(b==c){
			sum--;
		}
		if(a==c){
			sum--;
		}
	}
	cout<<sum;
}
