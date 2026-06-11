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
int n;
typedef long long ll;
ll T;
ll a[100004],ans;
int main(){
	cin>>n>>T;
	ll minn=1e9+1;
	for (int i=0;i<n;i++){
		scanf ("%d",&a[i]);
		if (a[i]>minn)ans=max(ans,a[i]-minn);
		minn=min(minn,a[i]);
	}
	minn=a[0];ll res=0;
	for (int i=1;i<n;i++){
		if (a[i]>minn+ans-1){
			res+=a[i]-(minn+ans-1);
			a[i]=minn+ans-1;
		}
		minn=min(minn,a[i]);
	}
	cout<<res;
}