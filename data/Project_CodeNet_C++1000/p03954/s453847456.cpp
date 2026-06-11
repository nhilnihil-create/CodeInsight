//NOT A FSKY CODE
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200004],b[200004];
bool check(int x){
	for (int i=1;i<=m;i++){
		if (a[i]<x) b[i]=0;
		else b[i]=1;
	}
	int l,r;
	for (l=n-1;l>0 && b[l]^b[l+1];l--);
	for (r=n+1;r<=m && b[r]^b[r-1];r++);
	if (l==0 && r==m+1) return b[1];
	return r-n>n-l?b[l]:b[r];
}
int main(){
	cin>>n;
	m=n*2-1;
	for (int i=1;i<=m;i++) scanf ("%d",&a[i]);
	int l=-1,r=m+1;
	while (r>l+1){
		int mid=(l+r)/2;
		if (check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
}