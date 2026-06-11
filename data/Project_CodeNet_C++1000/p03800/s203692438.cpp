#include<bits/stdc++.h>
using namespace std;
#define SC scanf
#define PR printf
#define pb push_back
#define mp make_pair
#define SZ(v) ((int)(v).size())
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define db double
#define ldb long double
#define uint unsigned
#define ll long long
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef map<int,int> mii;
const int INF=0x3f3f3f3f;
const ll LL_INF=0x3f3f3f3f3f3f3f3f;
const int xx[4]={1,-1,0,0};
const int yy[4]={0,0,1,-1};
int inline nextin(){
	int t;
	if(scanf("%d",&t)!=1)exit(0);
	return t;
}
int inline in(){
	int x=0,c;
	for(;(uint)((c=getchar())-'0')>=10;){
		if(c=='-')return -in();
		if(!~c)throw ~0;
	}
	do{
		x=(x<<3)+(x<<1)+(c-'0');
	}while((uint)((c=getchar())-'0')<10);
	return x;
}
int main(){
    cin.sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<4;i++){
		string t=to_string((i&2)>>1)+to_string(i&1);
		for(int j=2;j<n;j++){
			if(s[j-1]=='o'&&t[j-1]=='0'){
				t+=t[j-2];
			}else if(s[j-1]=='o'&&t[j-1]=='1'){
				t+=((t[j-2]-'0')^1)+'0';
			}else if(s[j-1]=='x'&&t[j-1]=='0'){
				t+=((t[j-2]-'0')^1)+'0';
			}else t+=t[j-2];
		}
		
		if(s[0]=='o'&&t[0]=='0'){
			if(t[n-1]==t[1]);
			else continue;
		}
		if(s[0]=='o'&&t[0]=='1'){
			if(t[n-1]!=t[1]);
			else continue;
		}
		if(s[0]=='x'&&t[0]=='0'){
			if(t[n-1]!=t[1]);
			else continue;
		}
		if(s[0]=='x'&&t[0]=='1'){
			if(t[n-1]==t[1]);
			else continue;
		}
		
		if(s[n-1]=='o'&&t[n-1]=='0'){
			if(t[0]==t[n-2]);
			else continue;
		}
		if(s[n-1]=='o'&&t[n-1]=='1'){
			if(t[0]!=t[n-2]);
			else continue;
		}
		if(s[n-1]=='x'&&t[n-1]=='0'){
			if(t[0]!=t[n-2]);
			else continue;
		}
		if(s[n-1]=='x'&&t[n-1]=='1'){
			if(t[0]==t[n-2]);
			else continue;
		}
		
		for(int j=0;j<n;j++){
			if(t[j]=='0')cout<<'S';
			else cout<<'W';
		}
		cout<<endl;
		return 0;
	}
	puts("-1");
	return 0;
}