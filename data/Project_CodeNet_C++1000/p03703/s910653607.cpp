#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define qi queue<int>
#define vi vector<int>
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second 
#define prq priority_queue
#define foreach(it,c) for(__typeof((c).begin()) it=c.begin();it!=c.end();it++)
//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
inline ll read(){
	ll x=0;
	int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	return x*f;
}
inline void out(int x){
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
int n;
ll k,a[202020],s[202020];
queue<ll> q1,q2;
ll dfs(int l,int r){
	if(r-l==1)return 0;
	int mid=(l+r)/2;
	ll ret=dfs(l,mid)+dfs(mid,r);
	fo(i,l,mid)q1.push(s[i]);
	fo(i,mid,r)q2.push(s[i]);
	int j=l;
	while(!q1.empty()&&!q2.empty()){
		if(q1.front()>q2.front()){
			ret+=mid-l-q1.size();
			s[j++]=q2.front();
			q2.pop();
		}else{
			s[j++]=q1.front();
			q1.pop();
		}
	}
	while(!q1.empty()){
		s[j++]=q1.front();
		q1.pop();
	}
	while(!q2.empty()){
		ret+=mid-l;
		s[j++]=q2.front();
		q2.pop();
	}
	return ret;
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	cin>>n>>k;
	fo(i,0,n)cin>>a[i];
	s[0]=0;
	fo(i,0,n)s[i+1]=s[i]+a[i]-k;
	cout<<dfs(0,n+1)<<endl; 
	return 0;
}