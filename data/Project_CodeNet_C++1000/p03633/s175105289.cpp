#include <iostream>
#include <vector>
using namespace std;
long gcd(long long x,long long y){
    if(x < y) swap(x,y);
    if(y == 0) return x;
    else return gcd(y,x%y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<long long> t(n);
    for(int i = 0; i < n; ++i) cin >> t[i];
    long long lcm = t[0];
    for(int i = 0; i < n; ++i){
        lcm = lcm/gcd(lcm, t[i])*t[i];
    }
    cout << lcm << endl;
    return 0;
}