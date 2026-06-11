#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

int main(){
	string s;
	cin>>s;
	
	llong ans=0;
	REP(i,1<<(s.size()-1)){
		llong tmp=0;
		int p=0;
		int cnt=1;
		REP(j,s.size()-1){
			if((i>>j)&1){
				tmp+=stoll(s.substr(p,cnt));
				p=j+1;
				cnt=1;
			}else cnt++;
		}
		tmp+=stoll(s.substr(p,cnt));
		
		ans+=tmp;
	}
	
	cout<<ans<<endl;
}