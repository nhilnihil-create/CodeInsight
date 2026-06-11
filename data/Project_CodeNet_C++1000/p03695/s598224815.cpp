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
    int n,i;
    cin>>n;
    bool ar[8];
    memset(ar,false,sizeof(ar));
    int j = 0;
    For(i,0,n){
        int x;
        cin>>x;
        if(x >= 1 && x <= 399) ar[0] = 1;
        else if(x >= 400 && x <= 799 ) ar[1] = 1;
        else if(x >= 800 && x <= 1199) ar[2] = 1;
        else if(x >= 1200 && x <= 1599) ar[3] = 1;
        else if(x >= 1600 && x <= 1999) ar[4] = 1;
        else if(x >= 2000 && x <= 2399) ar[5] = 1;
        else if(x >= 2400 && x <= 2799) ar[6] = 1;
        else if(x >= 2800 && x <= 3199) ar[7] = 1;
        else j++;
    }
    int ans = 0, ol;
    ol = j> 0;
    For(i,0,8) ans += ar[i];
    cout<<max(ans,ol) sp;
    cout<<ans + j;
    return 0;
}