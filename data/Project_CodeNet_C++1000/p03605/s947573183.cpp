#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=998244353;
const int siz=1e5;
const long inf=1e9;
int main(){
	int N; cin>>N;
	if(N / 10 == 9 || N % 10 == 9) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}