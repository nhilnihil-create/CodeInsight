#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

int main(){
	vi s; int n;
	read(n),n*=2; s.resize(n);
	REP(i,n) read(s[i]);
	sort(s.begin(),s.end());
	ll ans=0;
	for(int i=0;i<s.size();i+=2) ans+=s[i];
	cout<<ans<<endl;
	return 0;
}