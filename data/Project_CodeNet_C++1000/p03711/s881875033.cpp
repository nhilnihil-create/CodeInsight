#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
int main(){
	int x,y; cin>>x>>y;
	int a[12] = {0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
	cout<<(a[x-1] == a[y-1] ? "Yes" : "No")<<endl;
}