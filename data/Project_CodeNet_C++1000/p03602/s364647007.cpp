#include<bits/stdc++.h>
#define MAXN 305
#define LL long long
using namespace std;

int N;
int d[MAXN][MAXN];

LL ans = 0;
bool chk(){
	
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			int x = d[i][j];
			bool f = 0;
			for(int k=1;k<=N;k++){
				if(k==i || k==j) continue;
				if(d[i][k] + d[k][j] < x) return 0;
				if(d[i][k] + d[k][j] == x) f = 1;
			}
			if(!f) ans += x;
		}
	}
	return 1;
}

int main(){
	
	cin>>N;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>d[i][j];
		}
	}
	
	if(chk()==0){
		cout<<"-1"<<endl;
		return 0;
	}
	else{
		cout<<ans<<endl;
	}
	
	return 0;
}
