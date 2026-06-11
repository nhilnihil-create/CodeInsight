#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
    int n;
    cin >> n;
    ll a[n],sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i=0;i<n-1;i++){
        sum -= 2*a[i];
        ll abs = max(sum, -sum);
        v.push_back(abs);
    }
    sort(v.begin(),v.end());
    cout << v.at(0) << endl;
}