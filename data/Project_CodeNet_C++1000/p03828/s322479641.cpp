#include <iostream>
#include <cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
#define MAX_B 1001001
#define NIL -1
const int MOD = 1e9+7;
const int INF = 1 << 29;
const ll INFTY=1000000000000000000LL;
bool is_prime(int n){
   for(int i=2;i*i<=n;i++){
       if(n%i==0)return 0;
   }
   return 1;
}
int main(){
    int n;
    cin>>n;
    map<ll,ll>m;
    for(int i=2;i<=n;i++){
        int x=i;
       for(int j=2;j<=i;j++){
       while(x%j==0){
           x/=j;
           m[j]++;
       }
       }
    }
    ll ans=1;
    for(auto p:m){
        ans=ans*(p.second+1)%MOD;
    }
    cout<<ans<<endl;
}