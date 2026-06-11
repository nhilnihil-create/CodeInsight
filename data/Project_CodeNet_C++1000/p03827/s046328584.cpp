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
#include<string>
#include<stdlib.h>
#include<stdio.h>
typedef long long ll;

using namespace std;

int main(){
	int n,ans=0,maks=0;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='I'){
			ans++;
		}
		if(s[i]=='D'){
			ans--;
		}
		maks=max(ans,maks);
	}
	cout<<maks;
}