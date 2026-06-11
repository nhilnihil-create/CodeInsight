#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*
AC
h2*w2内の総和がどこを見ても-1になるようにする
正の部分と負の部分を偏らせる（大きい数字を左上に寄せて，小さい数字が右下に来るようにする）
*/


int main(void){
	bool ok=true;
	ll h,w,h2,w2,ans[510][510];
	cin>>h>>w>>h2>>w2;
	if(h%h2==0 && w%w2==0)ok=false;
	rep(i,h)rep(j,w)ans[i][j]=0;
	rep(i,h/h2+1)rep(j,w/w2+1)ans[i*h2][j*w2]=9999;
	reg(i,1,h/h2)reg(j,1,w/w2)ans[i*h2-1][j*w2-1]=-10000;
	if(ok){
		cout<<"Yes"<<endl;
		rep(i,h){
			rep(j,w)cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}