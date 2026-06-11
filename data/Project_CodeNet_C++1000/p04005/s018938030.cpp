#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    vector<ll> a(3);
    cin >> a[0] >> a[1] >> a[2];
    if(a[0]%2==0 || a[1]%2==0 || a[2]%2==0){
        cout << 0 << endl;
        return 0;
    }

    sort(a.begin(),a.end());
    cout << a[0]*a[1] << endl;

    return 0;
}