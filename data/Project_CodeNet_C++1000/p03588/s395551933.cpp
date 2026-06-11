#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define INF      (int)1e9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef pair<int,int> pii;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
template<class Type> void join(const Type &a){for(auto elem:a)cout<<elem<<' ';cout<<endl;}

int main(){
	int n;
	cin>>n;
	
	int mxm=0;
	int sco;
	REP(i,n){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>mxm){
			mxm=a;
			sco=b;
		}
	}
	
	cout<<mxm+(sco-0)<<endl;
	return 0;
}