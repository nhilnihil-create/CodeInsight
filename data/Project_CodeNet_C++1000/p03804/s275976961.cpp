#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 1000000007
const int MAX = 510000;
ll gcd(ll a, ll b){
    if (a % b == 0)
    {  return(b);}
    else{return(gcd(b, a % b));}
}
ll lcm(ll a, ll b)
{return a * b / gcd(a, b);}

int main(){
  int N,M;cin>>N>>M;
  char A[N][N];
  char B[M][M];
  rep(i,N){
  	rep(j,N){
    	cin>>A[i][j];
    }
  }
  rep(i,M){
  	rep(j,M){
    	cin>>B[i][j];
    }
  }
  int ans=0;
  for(int i=0;i<=N-M;i++){
  	for(int j=0;j<=N-M;j++){
      	int flag=0;
    	 rep(k,M){
  			rep(l,M){
    			if(A[k+i][l+j]!=B[k][l]){flag=1;}
    		}
  		}
    	if(flag==0){ans=1;}
    }
  }
  if(ans==1){cout<<"Yes";}
  else{cout<<"No";}
}