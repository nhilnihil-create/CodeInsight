#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
const int MAX = 1e9+7;

void solve(){
    int n, res = 1; cin>>n;
    int a[n+1];
    memset(a, 0, sizeof a);

    for (int i=1; i<=n; i++){ int e; cin>>e; a[e]++;}
    int counter = (n%2^0) ? (n-1)/2 :  n/2;
    for (int i=1; i<=counter; i++) res = (res*2)%MAX;
  
    bool isValid = false;
    for (int i=0; i<n; i+=2) isValid += 
      ((i+2<n && a[i+2]^2 && n%2^0)  || 
      (i+1<=n-1 && a[i+1]^2 && !(n%2^0)));
    
    cout<<((!isValid) ? res : 0)<<endl;
}

int main()
{
    solve();
    Bye;
}
