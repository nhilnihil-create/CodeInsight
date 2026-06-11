//  Created by conan1024hao in 2020.
//  Copyright © 2020 conan1024hao. All rights reserved.
//  専用ライブラリです、自由にコピーして構いません。
//  感谢看我的代码！Wechat:conan1024hao Twitter/QQ:810396815
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
#include <unordered_map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 10e8
#define INF 10e16
#define MOD 1000000007
#define mod 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
//using Int=int_fast64_t;
typedef long long int ll;
typedef long long int LL;
typedef pair<ll,ll>Pll;
typedef pair<int,int>Pin;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};
char dir[4]={'u','l','d','r'};
ll cmp1(pair<ll,string>a,pair<ll,string> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se<b.se;
}

//---------------------------------------------------------------------------
bool cmp(const Pll &l,const Pll &r){
    return l.fi<r.fi;
}
//---------------------------------------------------------------------------
int main(){//問題をちゃんと見ろ!!!!!!!!!!!!!!!!!      llか??????????统一类型        memset()!!!!!!!!!!!!       ペナを減らせ!!!!!!!!!!!!!
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    int h,w;cin>>h>>w;
    char a[150][150];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>a[i][j];
    map<char,int>cnt;
    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
        cnt[a[i][j]]++;
    int pl1=0,pl2=0,pl4=0;
    if(h%2==0&&w%2==0)
        pl4=h*w;
    else if(h%2!=0&&w%2==0){
        pl4=(h-1)*w;
        pl2=w;
    }
    else if(h%2==0&&w%2!=0){
        pl4=(w-1)*h;
        pl2=h;
    }
    else{
        pl4=(w-1)*(h-1);
        pl2=h+w-2;
        pl1=1;
    }
    //cout<<pl4<<" "<<pl2<<" "<<pl1<<endl;
    for(char i='a';i<='z';i++){
        while(cnt[i]>=4&&pl4>=4){
            cnt[i]-=4;
            pl4-=4;
        }
    }
    for(char i='a';i<='z';i++){
        while(cnt[i]>=2&&pl2>=2){
            cnt[i]-=2;
            pl2-=2;
        }
    }
    for(char i='a';i<='z';i++){
        if(cnt[i]%2!=0&&pl1>=1){
            cnt[i]-=1;
            pl1-=1;
        }
    }
    if(pl1==0&&pl2==0&&pl4==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------





