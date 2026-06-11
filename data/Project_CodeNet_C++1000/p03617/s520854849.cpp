#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    ll q,h,s,d,n;cin >> q >> h >> s >> d >> n;
    ll x=min(min(4*q,2*h),s);
    if(2*x<=d){
        cout << x*n << endl;
        return 0;
    }

    else{
        if(n%2==0){
            cout << n/2*d << endl;

        }
        else{
            cout << (n-1)/2*d+x << endl;
        }
    }

    return 0;
}