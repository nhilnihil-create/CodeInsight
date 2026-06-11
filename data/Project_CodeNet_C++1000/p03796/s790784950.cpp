#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    int n; cin >> n;
    ll power = 1;
    ll dis = 1000000007;
    for(int i=1; i<=n; i++){
        power = power*i;
        power = power % dis;
    }
    cout << power << endl;
    return 0;

}