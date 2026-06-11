#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()

#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000

#define PB push_back
#define MP make_pair
#define F first
#define S second

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main(){
	string s;
	cin >>s;
	int n=s.length();
	long long tmp=0,ans=0;
	REP(bit,1<<(n-1)){
		REP(i,n){
			tmp*=10;
			tmp+=s[i]-'0';
			if((bit&(1<<i))||i==n-1){
				ans+=tmp;
				tmp=0;
			}
		}
	}
	cout<<ans<<endl;
}
