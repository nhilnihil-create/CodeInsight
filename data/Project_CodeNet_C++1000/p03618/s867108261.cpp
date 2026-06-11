#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
string a;
	ll ans;
	cin >>a;
	ans=a.size()*(a.size()+1LL)/2LL+1LL;
	//clog<<ans<<endl;
	map<char,ll>dis;
	rep(i,a.size()){
		dis[a[i]]+=0;
		dis[a[i]]++;
	}
	repi(itr,dis){
		ans-=(itr->S)*((itr->S)-1LL)/2LL;
	//	clog<<(itr->S)<<endl;
	}
	ans-=a.size();
	cout<<ans<<endl;
}
/*
8=n
oooooooo
01 12 23 34 45 56 67 =n-1
02 13 24 35 46 57    =n-2 = o(n)
   03 14 25 36 47  
   04 15 26 37
      05 16 27
	  06 17=
	     07
= 28

abracadabra
   aca
     ada

abcba  3 2 2 1
bacba
cbaba
bcbaa
acbba
aabcb
abbca
ababc
abcab


abbca 4 2 2 1
babca
bbaca
cbbaa
acbba
aacbb
abcba
abacb
abbac
*/