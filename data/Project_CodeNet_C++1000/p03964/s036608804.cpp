#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define ve vector
#define umap unordered_map

int main() {
    ll a=1, b=1;
    int n; cin>>n;
    while(n--) {
        ll x, y;
        cin>>x>>y;
        
        ll c1 = (a + x - 1) / x;
        ll c2 = (b + y - 1) / y;
        ll c = max(c1, c2);
        a = x * c;
        b = y * c;
    }
    cout<<a+b<<endl;
}