#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define piii pair<pii,pii>
#define precise cout<<fixed<<setprecision(10)
#define st first
#define nd second
#define ins insert
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int MAX=305;
int a[MAX][MAX];
int ans=0;
void wyjdz(){
	cout<<"-1";
	exit(0);
}
int32_t main()
{
  BOOST;
  int n;
  cin>>n;
  for (int i=1;i<=n;i++)
  	for (int j=1;j<=n;j++){
  		cin>>a[i][j];
  	}
  	
  for (int i=1;i<=n;i++){
  	for (int j=1;j<=n;j++){
  		bool czy=true;
  		for (int k=1;k<=n;k++){
  			if (a[i][j]+a[j][k]<a[i][k]  && i!=j && i!=k && j!=k)wyjdz();
  			if (a[i][j]==a[i][k]+a[k][j] && i!=j && j!=k && i!=k)czy=false;
  		}
  		if (czy)ans+=a[i][j];
  	}
  }
  ans>>=1;
  cout<<ans;
  return 0;
}
