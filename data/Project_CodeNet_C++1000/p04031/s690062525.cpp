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
#define long long

using namespace std;
int main() {
	int n,ans=0;
	cin>>n;
	float a[n],sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	float avg;
	avg=round(sum/n);
	for(int i=0;i<n;i++){
		ans+=pow(abs(avg-a[i]),2);
	}
	cout<<ans;
}
