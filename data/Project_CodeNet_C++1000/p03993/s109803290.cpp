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

int main() {
	int n,ans=0;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==a[a[i]]){
			ans++;
		}
	}
	cout<<ans/2;
}

