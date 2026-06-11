//  Created by conan1024hao on 2019/11/23.
//  Copyright © 2019 conan1024hao. All rights reserved.
//  専用ライブラリです、自由にコピーして構いません。
//  感谢看我的代码！Wechat:conan1024hao QQ:810396815
#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll>P;
#define INF 10e16
#define MOD 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define fi first
#define se second
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define PI acos(-1.0)
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
ll cmp(pair<ll,string>a,pair<ll,string> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se<b.se;
}
//---------------------------------------------------------------------------
vector<int> g[100005];
int dfs(int s,int q){
    int k=0;
    for(int r=0;r<g[s].size();r++){
        if(g[s][r]!=q)
            k^=(1+dfs(g[s][r],s));
    }
    return k;
}
//---------------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(dfs(0,-1))
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;
//-------------------------------
    return 0;
}
//---------------------------------------------------------------------------
