


#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000

 int main(){

 int n,k; cin>>n>>k;
 int a[n];
 for(int i=0;i<n;i++) cin>>a[i];

 sort(a,a+n);

  ll sum =0,ans=n;

  for(int j=n-1;j>=0;j--){
      if(sum + a[j] < k)
            sum += a[j];
      else{
            ans = j;
            }
  }

  cout<<ans<<endl;

return 0;
 }