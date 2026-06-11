#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5+1;
const long inf=1e14;
int main(){
	int N; cin>>N;
	int A[N]; map<int,int> mp;
	rep(i,0,N){ cin>>A[i]; mp[A[i]] = i + 1; }
	int k = 0; int cnt = 0;
	for(pair<int,int> p:mp){ k++; cnt += (p.second % 2 != k % 2); }
	cout<<cnt / 2<<endl;
}