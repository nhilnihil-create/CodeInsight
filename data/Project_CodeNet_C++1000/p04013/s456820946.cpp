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
const int maxsum=2502;
int dp[51][maxsum];
int subs(int i,int s,int arr[],int n){
	if(i==n){
		if(s==0)return 1;
		else return 0;
	}
	if(dp[i][s+maxsum]!=-1)return dp[i][s+maxsum];
	return dp[i][s+maxsum]=subs(i+1,s+arr[i],arr,n)+subs(i+1,s,arr,n);
}
signed main(){
  ms(dp,-1);
  int n,avg;
  sl(n);sl(avg);
  int x[n];
  for(int i=0;i<n;i++)sl(x[i]);
  for(int i=0;i<n;i++)x[i]=x[i]-avg;
  cout<<subs(0,0,x,n)-1<<endl;
 
  return 0;
}
