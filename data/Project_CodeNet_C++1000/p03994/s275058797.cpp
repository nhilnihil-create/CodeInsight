#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

int main() {

	string s;
	string t = "abcdefghijklmnopqrstuvwxyz";
	ll k;
	cin>>s;
	cin>>k;
	rep(i,s.size()-1){
		if(s[i]=='a')continue;
		rep(j,26){
			if(t[j]==s[i]){
				if(26-j<=k){
					s[i]='a';
					k=k-26+j;
				}
				break;
			}
		}
	}
	rep(j,26){
		if(t[j]==s[s.size()-1]){
			if(26-j<=k){
				k=k-26+j;
				k%=26;
				s[s.size()-1]=t[k];
			}else s[s.size()-1]=t[j+k];
			cout<<s<<endl;
			return 0;
		}
	}

	return 0;

}
