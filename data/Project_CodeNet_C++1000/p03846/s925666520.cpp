#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define pb push_back

void solve(){
   int n;cin>>n;
   int a,A[100000]{};
   for(int i=0;i<n;++i) cin>>a,++A[a];
    A[0]+=n%2;
   for(int i= (n+1)%2 ; i < n; i+=2) 
    if(A[i]!=2) {
      cout<<"0"<<endl;
      return;
    }

   n/=2;
   ll temp=1;
   while(n--) temp=(temp*2)%1000000007;
    cout<<temp<<endl;
}


int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
solve();
  return 0;
}
