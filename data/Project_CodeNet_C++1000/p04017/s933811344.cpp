#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {
	
	int N;
	scanf("%d",&N);
	
	vector<int> x(N);
	for(int i=0;i<N;i++){
		scanf("%d",&x[i]);
	}
	
	int L;
	scanf("%d",&L);
	
	vector<vector<int>> next(20,vector<int>(N));
	
	for(int i=0;i<N;i++){
		auto it = upper_bound(x.begin(),x.end(),x[i]+L);
		it--;
		
		next[0][i] = distance(x.begin(),it);
	}
	
	for(int i=1;i<20;i++){
		for(int j=0;j<N;j++){
			next[i][j] = next[i-1][next[i-1][j]];
		}
	}
	/*
	for(int i=0;i<5;i++){
		for(int j=0;j<N;j++){
			cout<<next[i][j]<<',';
		}
		cout<<endl;
	}
	*/
	int Q;
	scanf("%d",&Q);
	
	for(int i=0;i<Q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		
		a--;b--;
		if(a>b)swap(a,b);
		
		int ans = 0;
		int now = a;
		for(int j=19;j>=0;j--){
			if(next[j][now]<b){
				ans |= (1<<j);
				now = next[j][now];
			}
		}
		
		printf("%d\n",ans+1);
	}
	
    return 0;
}
