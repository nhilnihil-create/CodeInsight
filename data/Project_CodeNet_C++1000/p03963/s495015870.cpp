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
    ll n, k;
    cin>>n>>k;
    ll ans = k;
    while (--n) ans *= k - 1;
    cout<<ans<<endl;
}