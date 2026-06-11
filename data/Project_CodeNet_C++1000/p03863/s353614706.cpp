#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	string s;cin>>s;
	int k=s.size()-(s[0]==s.back() ? 1 : 0);
	if(k%2) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
}