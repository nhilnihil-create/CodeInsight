#include<bits/stdc++.h>
#pragma 03

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repp(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define ll long long


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const long long mod=1000000007;

string s,d;
int psum1[100001],psum2[100001];


signed main() {
	   fastio;
	   // freopen(".inp","r",stdin); freopen(".out","w",stdout);
	   cin >> s >> d;
	   if(s[0]=='A') psum1[0]=1;
	   else psum1[0]=2;
	   if(d[0]=='A') psum2[0]=1;
	   else psum2[0]=2;
	   rep(i,1,s.length()-1) {
	   	if(s[i]=='A'){
	   		psum1[i]=psum1[i-1]+1;
		   } 
		   else {
		   	psum1[i]=psum1[i-1]+2;
		   }
	   }
	   rep(i,1,d.length()-1) {
	   	if(d[i]=='A'){
	   		psum2[i]=psum2[i-1]+1;
		   } 
		   else {
		   	psum2[i]=psum2[i-1]+2;
		   }
	   }
	   //cout << psum1[13] << " " << psum1[2] << endl;
	   //cout << psum2[16] << " " << psum1[6] << endl;
	   //return 0;
	   int q;
	   cin >> q;
	   rep(i,1,q) {
	   	int x,y,z,t,mod1=0,mod2=0;
	   	cin >> x >> y >> z >> t;
	   	if(x==1) mod1=psum1[y-1]%3;
	   	else mod1=(psum1[y-1]-psum1[x-2])%3;
	   	if(z==1) mod2=psum2[t-1]%3;
	   	else mod2=(psum2[t-1]-psum2[z-2])%3;
	   	if(mod1<0) mod1+=3;
	   	if(mod2<0) mod2+=3;
		   if(mod1==mod2) cout << "YES" << endl;
		   else cout << "NO"<<endl;
	   }
	   
	   
}

