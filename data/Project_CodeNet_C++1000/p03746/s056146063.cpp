//  atcodder.xcode
//  main.cpp
//  Created by conan1024hao on 2019/11/11.
//  Copyright © 2019 conan1024hao. All rights reserved.
//  専用ライブラリ
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
vector<ll>c[100001];
vector<ll>path1,path2;
int visited[100001];
void dfs(int y){
//path.push_back(y);
    if(c[y].size()==1)
        return;
    for(int i=0;i<c[y].size();i++){
        if(visited[c[y][i]]==1)
            continue;
        visited[c[y][i]]=1;
        dfs(c[y][i]);
        break;
    }
}
//---------------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    
    memset(visited,0,sizeof(visited));
    ll x,y;
    x=0;
    y=c[0][0];
    visited[x]=1;
    visited[y]=1;
    
    path1.push_back(x);
    path2.push_back(y);
    
    ll perx=y,pery=x;
    while(1){
        bool update=0;
        for(int i=0;i<c[x].size();i++){
            if(c[x][i]==perx)continue;
            if(!visited[c[x][i]]){
                
                visited[c[x][i]]=1;
                path1.push_back(c[x][i]);
                perx=x;
                x=c[x][i];
                update=1;
                break;
            }
        }
        if(!update)
            break;
    }
    while(1){
        bool update=0;
        for(int i=0;i<c[y].size();i++){
            if(c[y][i]==pery)continue;
            if(!visited[c[y][i]]){
                
                visited[c[y][i]]=1;
                path2.push_back(c[y][i]);
                pery=y;
                y=c[y][i];
                update=1;
                break;
            }
        }
        if(!update)
            break;
    }
    cout<<path1.size()+path2.size()<<endl;
    for(int i=path1.size()-1;i>=0;i--){
        cout<<path1[i]+1<<" ";
    }
    for(int i=0;i<path2.size();i++){
        cout<<path2[i]+1<<" ";
    }
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------

