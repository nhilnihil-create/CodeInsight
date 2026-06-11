#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG 
 int main(){
     int a,b,c;
     cin>>a>>b>>c;
     vector<int> vec(b);
     rep1(i,b){
         int moda=a%b;
         moda*=i;
         moda%=b;
         vec[i-1]=moda;
     }
     bool judge =false;
     rep(i,b){
         if(vec[i]==c) judge=true;
         else continue;
     }
     if(judge) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;

 }