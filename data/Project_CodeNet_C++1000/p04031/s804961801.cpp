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
    VI a(n);
    rep(i,n){
        cin >> a.at(i);
    }
    ll mn=100000000000000;
    for(int i=-100;i<=100;i++){
        ll cnt=0;
        rep(j,n){
            cnt+=(a.at(j)-i)*(a.at(j)-i);
        }
        mn=min(cnt,mn);
    }
    cout << mn << endl;
}