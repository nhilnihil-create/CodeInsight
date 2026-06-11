#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <string.h>
#include <climits>
using namespace std;
int main() {cin.tie(0);
   	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    long long a[n];
    long long ans;
    long long sum=0;
    long long s=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    ans=LLONG_MAX;
    for(int i=0;i<n-1;++i){
        s+=a[i];
        ans=min(ans,abs(2*s-sum));
    }
    cout <<ans<<endl;
    return 0;
}
