#include<bits/stdc++.h>
#define MAXN 200005
#define LL long long
#define sum(l,r) (l<=r?(s[r] - s[l-1]):0)
using namespace std;
 
int N;
LL a[MAXN], s[MAXN];
int nxt[MAXN];
 
int main(){
	
	cin>>N;
	cin>>a[1];
	
	int N1 = 1;
	char op;
	int x, f = 1; 
	for(int i=1;i<N;i++){
		cin>>op;
		cin>>x;
		if(op=='-') a[++N1] = -x, f = 0;
		else{
			if(f) a[N1] += x;
			else a[++N1] = x, f = 1; 
		}
	}

	N = N1;
	if(N==1){
		cout<<a[1]<<endl;
		return 0;
	}
	
	for(int i=1;i<=N;i++){
		//cout<<a[i]<<" ";
		s[i] = s[i-1] + abs(a[i]);
	}
	//cout<<endl;
	
	nxt[N] = N;
	for(int i=N-1;i>=1;i--){
		if(a[i+1] < 0) nxt[i] = i;
		else nxt[i] = nxt[i+1];
	}
	
	LL ans = -1e18; 
	LL sum = a[1];
	for(int i=2;i<=N;i++){
		
		if(a[i] < 0) ans = max(ans, sum - sum(i,nxt[i]) + sum(nxt[i]+1,N));
		sum += a[i];
	} 
	
	ans = max(ans, sum);
//	
//	for(int i=2;i<=N;i++){
//		ans = max(ans, a[1]-sum(2,i)+sum(i+1,N));
//	}
	cout<<ans<<endl;
	return 0;
}