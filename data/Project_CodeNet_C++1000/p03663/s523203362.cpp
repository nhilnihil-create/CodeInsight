#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define rep(i, a, b) for(int i=(a); i<(b); i++)
//-----
int n;
char s[20];
vi ans;
string g(int x){
	string res;
	while(x)res+=x%10+'0', x/=10;
	reverse(res.begin(), res.end());
	return res;
}
bool qry(ll x){
	printf("? %lld\n", x);
	fflush(stdout);
	scanf("%s", s);
	if(s[0]=='Y')return 1;
	return 0;
}
ll g(){
	ll res=0;
	rep(i, 0, sz(ans))res=res*10+ans[i];
	return res;
}
int main() {
	//scanf("%d", &n);
	
	/*int a=2, b=20;
	rep(i, 1, 300){
		int a=i, b=29;
		cout<<a<<' '<<b<<' '<<((a<=b&&g(a)<=g(b))||(a>b&&g(a)>g(b)))<<endl;
		//a*=10;
	}
	*/
	/*int x=1, y=10;
	cout<<x<<' '<<y<<' '<<((x<=y&&g(x)<=g(y))||(x>y&&g(x)>g(y)))<<endl;*/
	int len=0;
	ll a=1;
	rep(i, 1, 12){
		if(qry(a))len++;
		else break;
		a*=10;
	}
	if(len>9){
		a=2;
		len=0;
		rep(i, 1, 12){
			if(!qry(a))len++;
			else break;
			a*=10;
		}
		printf("! 1");
		rep(i, 0, len)printf("0");
		fflush(stdout);
	}else{
		//cout<<len<<endl;
		rep(i, 0, len-1){
			int lo=0, hi=10;
			while(lo+1<hi){
			int mid=(lo+hi)>>1;
			(qry(g()*10+mid))?lo=mid:hi=mid;
		}
			ans.pb(lo);
		}
		int be=(sz(ans)?1:2);
		rep(i, be, 10){
			if(qry(g()*100+i*10)){
				ans.pb(i);
				break;
			}
		}
		printf("! ");
		rep(i, 0, sz(ans))printf("%d", ans[i]);
		fflush(stdout);
	}
	return 0;
}
