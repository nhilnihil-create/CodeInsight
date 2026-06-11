#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
#define pi 3.14159265358979
using ll = long long;
using P = pair<int,int>;

ll divisor=1e9+7;
int main(){
	int n;
	cin>>n;
	int a[n];
	rep(i,n)cin>>a[i];
	int count=0;
	rep(i,n){
		if(a[a[i]-1]==i+1)count++;
	}
	puts(count/2);
	
}