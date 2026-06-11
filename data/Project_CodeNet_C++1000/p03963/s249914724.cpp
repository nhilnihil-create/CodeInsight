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
	int a,b;
	cin>>a>>b;
	int ans=b;
	for(int i=0;i<a-1;i++){
		ans*=(b-1);
	}
	cout<<ans;
}
