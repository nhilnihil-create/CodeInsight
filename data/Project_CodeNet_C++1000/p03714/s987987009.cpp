/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

int a[300005]={0},pref[300005]={0};

signed main()
{
    priority_queue< int,vector<int>, greater <int> > f;
    priority_queue<int> s;
    int n;  cin>>n;
    int N=n*3,fsum=0 ,ssum=0;
    for (int i=1;i<=N;i++) {
        cin>>a[i];
        if (i<=n){
            fsum += a[i];
            f.push(a[i]);
        }
        if (i>2*n){
            ssum += a[i];
            s.push(a[i]);
        }
    }
    pref[1] = fsum;
    pref[n+1] = -ssum;
    for (int i=1;i<=n;i++){
        fsum += a[n+i];
        ssum += a[2*n-i+1];
        f.push(a[n+i]);
        s.push(a[2*n-i+1]);
        int mn=f.top(),mx=s.top();
        f.pop(); s.pop();
        fsum -= mn; ssum -= mx;
        pref[i+1] += fsum;
        pref[n-i+1] -= ssum;
    }
    int ans=INT64_MIN;
    for (int i=1;i<=n+1;i++)
        ans = max(ans,pref[i]);
    cout << ans << endl;
    return 0;
}
