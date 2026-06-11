#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){

 ULL a,b,x; cin>>a>>b>>x;
 ULL ans = b/x-a/x;
 if(a%x==0) ans++;
 cout<<ans<<endl;

 return 0;
}


