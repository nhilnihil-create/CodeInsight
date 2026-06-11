#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int MAXN=300005;
const int MOD=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define fst first
#define snd second
#define pb push_back

const int MAXM=100005;
const int S=409;
inline int read() {
    int x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
    return x;
}

int N,M;
int L[MAXN],R[MAXN];
int ans[MAXN];
int fw[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	N=read();
	M=read();
	FOR(i,0,N-1){
		L[i]=read();
		R[i]=read();
		L[i]--;
	}
	FOR(n,0,N-1){
		FOR(d,1,S){
			if (R[n]/d-L[n]/d > 0){
				ans[d]++;
			}
		}
	}
	FOR(n,0,N-1){
		vector<int>v={0};
		int x=R[n]/(S+1);
		int y=L[n]/(S+1);
		while (x>=1 && y>=1){
			if (R[n]/x < L[n]/y) v.pb(R[n]/x--);
			else v.pb(L[n]/y--);
		}
		while (x>=1) v.pb(R[n]/x--);
		while (y>=1) v.pb(L[n]/y--);
		v.pb(INT_MAX/2);
		FOR(i,1,(int)v.size()-1){
			if (R[n]/v[i] - L[n]/v[i] > 0){				
				if (v[i]>0) fw[v[i]]++;
				if (v[i-1]>0) fw[v[i-1]]--;
			}
		}
	}
	DEC(d,M,S+1){
		fw[d]+=fw[d+1];
		ans[d]+=fw[d];
	}
	FOR(d,1,M){
		cout<<ans[d]<<"\n";
	}
}
/*
3 3
1 2
2 3
3 3

7 9
1 7
5 9
5 7
5 9
1 1
6 8
3 4
*/