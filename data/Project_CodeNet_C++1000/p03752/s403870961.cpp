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
#define INF 10e17
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
using Int=int_fast64_t;
typedef long long int ll;
typedef long long int LL;
typedef pair<ll,ll>Pll;
typedef pair<int,int>Pin;
template<class T> using V=vector<T>;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
char dir[4]={'u','l','d','r'};
ll cmp(pair<ll,string>a,pair<ll,string> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se<b.se;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int main(){//問題をちゃんと見ろ! llか? 统一类型 memset()! ペナを減らせ!!!!!!!!!!!!!
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
	ll n,k;cin>>n>>k;
    k--;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    ll ans=INF;
    n--;
    if(k==0){
        cout<<0<<endl;
        return 0;
    }
    for(int bit=0;bit < (1<<n); bit++)
    {
        int cnt=0;
        for(int i=0;i<n;i++){
            if(bit & (1<<i))
                cnt++;
        }
        if(cnt<k)continue;
        ll minm=a[0];
        ll tmp=0;
        for(int i=0;i<n;i++){
            if(bit&(1<<i)){
                if(minm<a[i+1]){
                    minm=a[i+1];
                }
                else{
                    tmp+=minm-a[i+1]+1;
                    minm++;
                    //cout<<tmp<<endl;
                }
            }
            else{
                chmax(minm,a[i+1]);
            }
        }
        chmin(ans,tmp);
    }
    cout<<ans<<Endl;
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------