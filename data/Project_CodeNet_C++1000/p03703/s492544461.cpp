/*
 #pragma GCC target ("avx2")
 #pragma GCC optimize ("Ofast")
 #pragma GCC optimize ("unroll-loops")
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#define F first
#define S second
#define pb push_back
using namespace std;
const long long N = 2e5 + 10;
long long n, k;
long long a[N],pref[N];
vector<long long> v;

long long ans;

long long t[N];

long long sum (long long r)
{
    long long result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    return result;
}

void inc (long long i, long long delta)
{
    for (; i <= N; i = (i | (i+1)))
        t[i] += delta;
}

long long sum (long long l, long long r)
{
    return sum (r) - sum (l-1);
}
vector<pair<long long,long long> > p;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        //ans+=(a[i]>=k);
    }
    for(long long i=1;i<=n;i++){
        pref[i]=pref[i-1]+a[i-1];
    }
    for(long long i=0;i<=n;i++){
        pref[i]-=(i*k);
        //cout<<pref[i]<< ' ';
    }
    for(long long i=0;i<=n;i++){
        p.pb({pref[i],i});
    }
    sort(p.begin(),p.end());
    long long c=1;
    for(long long i=0;i<p.size();i++){
        if(i>0&&p[i].F>p[i-1].F)c++;
        pref[p[i].S]=c;
    }
    
    for(long long i=0;i<=n;i++){
        //cout<<ans<<' ';
        ans+=(sum(0,pref[i]));
        inc(pref[i],1);
    }
    cout<<ans;
    return 0;
}
