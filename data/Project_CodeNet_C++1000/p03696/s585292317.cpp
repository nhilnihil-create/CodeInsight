#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
const ll MOD = 1000000007;
const double PI = acos(-1);
//or-> ||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl

int N;
string ans;
string S;
signed main(){
	IO_STREAM;
	cin>>N>>S;

	int cnt=0;
	rep(i,0,N){
		if(S[i]==')'){
			cnt++;
		}
		else{
			if(cnt<=0) cnt--;
			else break;
		}
	}
	rep(i,0,cnt){
		S='('+S;
		N++;
	}
	
	cnt=0;
	for(int i=N-1;i>=0;i--){
		if(S[i]=='('){
			cnt++;
		}
		else{
			if(cnt<=0) cnt--;
			else break;
		}
	}
	rep(i,0,cnt){
		S=S+')';
		N++;
	}

	DBG("S",S,N,"");
	int L=0,R=0;
	rep(i,0,N){
		if(S[i]=='(')	L++;
		else			R++;
	}
	if(R>L){
		rep(i,0,(R-L)){
			ans.pb('(');
		}
		ans=ans+S;
	}
	else if(L>R){
		ans=S;
		rep(i,0,(L-R)){
			ans.pb(')');
		}
	}
	else{
		ans=S;
	}
	cout<<ans<<endl;
	return 0;
}
