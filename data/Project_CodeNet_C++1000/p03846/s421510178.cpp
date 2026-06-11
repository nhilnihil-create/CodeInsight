#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const int MAX = 1e9+7;
const int SIZE = 1e5+1;

void solve(){
    int n; cin>>n;
    
    int a[n+1];
    memset(a, 0, sizeof a);
    bool no_solution = false; 
    for (int i=1; i<=n; i++){
        int e; cin>>e; a[e]++;
    }

    int counter = (n%2^0) ? (n-1)/2 :  n/2;

    int res = 1;
    for (int i=1; i<=counter; i++)
        res = (res*2)%MAX;

    if(n%2^0){
        for (int i=2; i<n; i+=2)
            if(a[i]^2) {res = 0; break;}
    } else 
        for (int i=1; i<=n-1; i+=2)
            if(a[i]^2) {res = 0; break;}
    
    cout<<res<<endl;
}

int main()
{
    solve();
    Bye;
}