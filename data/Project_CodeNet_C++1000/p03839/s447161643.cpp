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
int n,k;
typedef long long ll;
ll s[100004],ss[100004];
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	ll x;
    	cin>>x;
    	s[i]=s[i-1]+x;
    	ss[i]=ss[i-1]+max(0ll,x);
    	//cout<<s[i];
	}
    ll ans=max(0ll,s[n]);
    for (int i=k;i<=n;i++){
    	int j=i-k;
    	ans=max(ans,ss[n]-(ss[i]-ss[j])+max(0ll,s[i]-s[j]));
    }
   	cout<<ans;
}
