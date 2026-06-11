#include<bits/stdc++.h>
#define LL long long
#define MAXN 200005
using namespace std;

int N,K;
int a[MAXN];
LL s[MAXN], c[MAXN];
//
int fw[MAXN];
int lbt(int x){
	return x & (-x);
}

void update(int x, int dv){
	for(;x<=N;x+=lbt(x)){
		fw[x] += dv;
	}
}

int getsum(int x){
	int ans = 0;
	for(;x>0;x-=lbt(x)){
		ans += fw[x];
	}
	return ans;
} 


int main(){
	
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		cin>>a[i];
		a[i] -= K;
		
		s[i] = s[i-1] + a[i];
	}
	
	memcpy(c, s, sizeof(s));
	sort(c+1, c+1+N);
	
	LL ans = 0;

	for(int i=1;i<=N;i++){
		if(s[i]>=0) ++ans;
		
		s[i] = lower_bound(c+1, c+1+N, s[i]) - c;
		ans += getsum(s[i]);
		update(s[i], 1);
	}
	
	cout<<ans<<endl;
	
	return 0;
}