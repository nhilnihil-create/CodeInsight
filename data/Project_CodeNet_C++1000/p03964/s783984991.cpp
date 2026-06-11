#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll p=1,q=1;
    for(int i=0; i<n; i++){
        ll t,a;
        cin >> t >> a;
        ll x,y;
        x=(p+t-1)/t;
        y=(q+a-1)/a;
        p=t*max(x,y);
        q=a*max(x,y);
        //cout << p << " " << q << endl;
    }
    cout << p+q << endl;
}