
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define int ll
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;


signed main(void) {
  int i,j;
  int k;
  cin>>k;
  int n=50;
  vi a(n);
  int cnt=k/n;
  rep(i,n)a[i]=i+cnt;
  int t=k%n;
  rep(i,n){
    if(i<t)a[i]+=n-t+1;
    else a[i]-=t;
  }
 cout<<n<<endl;
 rep(i,n){
   cout<<a[i];
   if(i<n-1)cout<<" ";
   else cout<<endl;
 }
}
