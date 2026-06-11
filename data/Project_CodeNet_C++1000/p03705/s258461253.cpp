

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

#define access(i) a[i/3][i%3]
//#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})

 int main(){

  ll n,a,b;
  cin>>n>>a>>b;

   if(a > b){
      cout<<"0"<<endl;
      return 0; }
   else if( n < 2 && a != b){
      cout<<"0"<<endl;
   return  0 ;}

  ll maxi_sum = b*(n-1)+a;
  ll mini_sum = a*(n-1)+b;

  cout<<maxi_sum-mini_sum+1<<endl;



 return 0;
 }