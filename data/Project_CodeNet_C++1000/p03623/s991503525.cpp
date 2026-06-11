#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int x,a,b; cin>>x>>a>>b;
	int xa=abs(a-x);
	int xb=abs(b-x);
	cout<<(xa<xb?"A":"B")<<endl;
}