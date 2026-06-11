#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n){
        cin >> a.at(i) >> b.at(i);
    }
    ll chka=0;
    ll ans;
    rep(i,n){
        if(chka<a.at(i)){
            chka=a.at(i);
            ans=a.at(i)+b.at(i);
        }
    }
    cout << ans << endl;
} 
    