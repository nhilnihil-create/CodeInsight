#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define obit __builtin_popcount
#define pof pop_front
#define For(i,a,n) for(i=a;i<n;i++)
#define all(ar) ar.begin(),ar.end() 
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned short int us;
typedef short int ss;
typedef long double ld;
const ll mod = 1000000007;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    //*/
    int i,n,tn = 0,mn = 10000, ntn = 0;
    cin>>n;
    For(i,0,n){
        int x; cin>>x;
        if(x % 10 == 0) tn += x;
        else{
            ntn += x;
            if(x < mn){
                mn = x;
            }
        }
    }
    if(ntn % 10 == 0){
        ntn -= mn; ntn = max(ntn,0);
    }
    tn += ntn;
    if(tn % 10 == 0) cout<<0;
    else cout<<tn;
    return 0;
}