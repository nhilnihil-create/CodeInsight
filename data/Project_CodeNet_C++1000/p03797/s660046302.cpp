#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
    ll n,m;
    cin >> n>> m;
    ll ans;
    if(n>=m/2){
        ans=m/2;
    }
    else{
        ans=n;
        ans+=(m-2*n)/4;
    }
    cout << ans << endl;
}