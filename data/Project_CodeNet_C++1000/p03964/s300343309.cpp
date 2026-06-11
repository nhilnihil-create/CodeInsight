#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5+2;
#define ld long double
signed main(){
  int nt,na,n,t,a,p;
  nt=1;
  na=1;
  cin>>n;
  for(int i=0;i<n;i++){
	  cin>>t>>a;
	  int p=max(ceil(nt/ (ld)t),ceil(na/ (ld)a));
	  //cout<<p<<" ";
	  nt=t*p;
	  na=a*p;
  }
  cout<<(nt + na)<<endl;
  return 0;
}
