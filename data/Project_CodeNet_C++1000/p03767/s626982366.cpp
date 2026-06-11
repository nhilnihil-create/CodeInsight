
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

 int main(){

 long long a;
 cin>>a;

 long long n = 3*a;

 int v[n];

 for(int i=0;i<n;i++)
    cin>>v[i];

  sort(v,v+n);
  long long ans=0;

  for(int i = n-2;i>=a;i-=2){
    ans += v[i];
  }

  cout<<ans<<endl;

 return 0;
 }
