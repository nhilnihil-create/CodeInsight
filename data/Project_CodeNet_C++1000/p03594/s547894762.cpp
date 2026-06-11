//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}

// cf IO: I64d
// atcoder IO: ｌｌｄ
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=505;
int c[Maxn][Maxn];
bool can[Maxn][Maxn];
char kk[]=" RYGB";
int rr[Maxn],cc[Maxn];
int n,m,d;
bool solve(){
	cerr<<123<<endl;
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;i++) rr[i]=i;
	for (int i=1;i<=m;i++) cc[i]=i;
	random_shuffle(rr+1,rr+1+n);
	random_shuffle(cc+1,cc+1+m);
	memset(can,true,sizeof(can));
	for (int ii=1;ii<=n;ii++){
		int i=rr[ii];
		for (int jj=1;jj<=m;jj++){
			int j=cc[jj];
			if (can[i][j]){
				c[i][j]=1;
				for (int kx=0;kx<=d;kx++){
					int ky=d-kx;
					if (i>kx && j>ky) can[i-kx][j-ky]=false;
					if (i>kx && j+ky<=m) can[i-kx][j+ky]=false;
					if (i+kx<=n && j>ky) can[i+kx][j-ky]=false;
					if (i+kx<=n && j+ky<=m) can[i+kx][j+ky]=false;
				}
			}
		}
	}
	random_shuffle(rr+1,rr+1+n);
	random_shuffle(cc+1,cc+1+m);
	memset(can,true,sizeof(can));
	for (int ii=1;ii<=n;ii++){
		int i=rr[ii];
		for (int jj=1;jj<=m;jj++){
			int j=cc[jj];
			if (can[i][j] && !c[i][j]){
				c[i][j]=2;
				for (int kx=0;kx<=d;kx++){
					int ky=d-kx;
					if (i>kx && j>ky) can[i-kx][j-ky]=false;
					if (i>kx && j+ky<=m) can[i-kx][j+ky]=false;
					if (i+kx<=n && j>ky) can[i+kx][j-ky]=false;
					if (i+kx<=n && j+ky<=m) can[i+kx][j+ky]=false;
				}
			}
		}
	}
	random_shuffle(rr+1,rr+1+n);
	random_shuffle(cc+1,cc+1+m);
	memset(can,true,sizeof(can));
	for (int ii=1;ii<=n;ii++){
		int i=rr[ii];
		for (int jj=1;jj<=m;jj++){
			int j=cc[jj];
			if (can[i][j] && !c[i][j]){
				c[i][j]=3;
				for (int kx=0;kx<=d;kx++){
					int ky=d-kx;
					if (i>kx && j>ky) can[i-kx][j-ky]=false;
					if (i>kx && j+ky<=m) can[i-kx][j+ky]=false;
					if (i+kx<=n && j>ky) can[i+kx][j-ky]=false;
					if (i+kx<=n && j+ky<=m) can[i+kx][j+ky]=false;
				}
			}
		}
	}
	random_shuffle(rr+1,rr+1+n);
	random_shuffle(cc+1,cc+1+m);
	memset(can,true,sizeof(can));
	for (int ii=1;ii<=n;ii++){
		int i=rr[ii];
		for (int jj=1;jj<=m;jj++){
			int j=cc[jj];
			if (can[i][j] && !c[i][j]){
				c[i][j]=4;
				for (int kx=0;kx<=d;kx++){
					int ky=d-kx;
					if (i>kx && j>ky) can[i-kx][j-ky]=false;
					if (i>kx && j+ky<=m) can[i-kx][j+ky]=false;
					if (i+kx<=n && j>ky) can[i+kx][j-ky]=false;
					if (i+kx<=n && j+ky<=m) can[i+kx][j+ky]=false;
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (!c[i][j]) return false;
		} 
	}
	return true;
}
int chev[2005][2005];
int main(){
	scanf("%d %d %d",&n,&m,&d);
	for (int i=0;i<2000;i++){
		for (int j=0;j<2000;j++){
			if (i%(2*d)<d && j%(2*d)<d){
				chev[i][j]=1;
			}
			else if (i%(2*d)<d){
				chev[i][j]=2;
			}
			else if (j%(2*d)<d){
				chev[i][j]=3;
			}
			else{
				chev[i][j]=4;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x=i+j,y=i-j;
			x+=500;
			y+=500;
			printf("%c",kk[chev[x][y]]);
		}
		printf("\n");
	}
	return 0;
}