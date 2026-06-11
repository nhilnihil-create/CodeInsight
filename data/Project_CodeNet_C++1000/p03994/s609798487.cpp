#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);

int main(){
	string s;ll k;cin>>s>>k;
	int n =s.length();
	rep(i,n-1){
		if('z'-s[i]+1<=k&&s[i]!='a'){
			k-='z'-s[i]+1;
			s[i]='a';
		}
	}
	k%=26;
	k+=s[n-1]-'a';
	k%=26;
	s[n-1]='a'+k;
	cout<<s<<endl;
}