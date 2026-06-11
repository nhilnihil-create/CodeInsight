#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
#define pint pair<int, int>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const ll LINF=1e18;
const int MOD=1e9+7;
//const int MOD=998244353;

int main(){
	string A; cin>>A;
	int n=A.size();

	vector<int> v[26],w;
	int num[26]={};
	FOR(i,0,n){
		v[A[i]-'a'].PB(i);
	}
	FOR(i,0,26) v[i].PB(INF);

	int k=1;
	int p[200001]={};
	ROF(i,0,n){
		p[i]=k;
		num[A[i]-'a']++;
		bool f=true;
		FOR(j,0,26){
			if(num[j]==0) f=false;
		}
		if(f){
			fill(num,num+26,0);
			k++;
			w.PB(i);
		}
	}
	/**
	FOR(i,0,n) cout<<p[i];
	cout<<endl;
	cout<<"k: "<<k<<endl;
	**/
	int nowpos=0;
	int length=k;
	string ans="";
	FOR(i,0,k){
		FOR(j,0,26){
			int a=*lower_bound(all(v[j]),nowpos);
			if(a==INF||p[a]==length-1){
				ans+=('a'+j);
				nowpos=a+1;
				length--;
				break;
			}
		}
	}
	co(ans);
}
