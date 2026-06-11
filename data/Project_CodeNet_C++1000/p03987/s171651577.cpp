#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define qwq(x) cerr<<" #"<<#x<<" = "<<x<<endl;
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

const int N=200005;
int a[N],p[N],n;
set<int> s;
ll ans;

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int x,int y){
		return a[x]<a[y];
	});
	s.insert(0);
	s.insert(n+1);
	rep(i,1,n){
		auto it=s.lower_bound(p[i]);
		auto pre=it;pre--;
		ans+=(ll)a[p[i]]*(*it-p[i])*(p[i]-*pre);
		s.insert(p[i]);
	}
	cout<<ans<<endl;

	return 0;
}
