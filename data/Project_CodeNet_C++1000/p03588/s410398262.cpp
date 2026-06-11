#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

int main(){
    ll n; cin >> n;
    vector<vector<ll>> ab;
    for(int i=0; i<n; i++){
        ll a, b; cin >> a >> b;
        ab.push_back(vector<ll>{a, b});
    }
    sort(ab.begin(), ab.end());
    cout << ab[n-1][0] + ab[n-1][1] << endl;
    return 0;
}