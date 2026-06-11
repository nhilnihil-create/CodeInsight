#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N;cin>>N;
	pair<int,int> vp[N]; int x[N];
	rep(i,0,N){
		cin>>x[i]; x[i]--;
        vp[i] = {x[i], i};
	}
	sort(vp, vp+N);
	int a[N*N];
	rep(i,0,N*N) a[i] = -1;
	rep(i,0,N) a[vp[i].first] = vp[i].second;
	int k = 0;
	rep(i,0,N){
		rep(j,0,vp[i].second){
			while(a[k] != -1) k++;
			a[k] = vp[i].second;
		}
	}
	k = N * N - 1;
	for(int i = N-1; i >= 0; i--){
		for(int j = N-1; j > vp[i].second; j--){
			while(a[k] != -1) k--;
			a[k] = vp[i].second;
		}
	}
	int cnt[N] = {};
	rep(i,0,N*N){
		cnt[a[i]]++;
		if(cnt[a[i]] == a[i] + 1){
            if(x[a[i]] != i){ cout<<"No"<<endl; return 0; }
        }a[i]++;
	}
	cout<<"Yes"<<endl;
	print(a,,N*N);
}