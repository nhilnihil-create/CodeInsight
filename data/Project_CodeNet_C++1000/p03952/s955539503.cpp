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

const int N=1000005;
int ans[N],n,x;
set<int> s;

int main(){
	read(n),read(x);
	if(x==1||x==2*n-1){
		puts("No");
		return 0;
	}
	rep(i,2,n*2-2)
		if(i!=x)s.insert(i);
	ans[n]=x;
	ans[n-1]=1;
	ans[n+1]=2*n-1;
	rep(i,1,2*n-1)
		if(!ans[i]){
			ans[i]=*s.begin();
			s.erase(s.begin());
		}
	puts("Yes");
	rep(i,1,2*n-1)printf("%d ",ans[i]);
	puts("");
	return 0;
}
