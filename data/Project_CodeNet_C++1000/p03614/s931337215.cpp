#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
int a[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			if(i<n)swap(a[i],a[i+1]);
			else swap(a[i],a[i-1]);
			cnt++;
		}
	}
	printf("%d",cnt);
}