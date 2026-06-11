#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;

int N;
int a[MAXN], c[MAXN];

int main(){
	
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	
	memcpy(c, a, sizeof(a));
	sort(c+1, c+1+N);
	
	int ans = 0;
	for(int i=1;i<=N;i++){
		a[i] = lower_bound(c+1, c+1+N, a[i]) - c;
		if(a[i]%2 != i%2) ++ans;
	}
	cout<<ans/2<<endl;
	
	return 0;
}
