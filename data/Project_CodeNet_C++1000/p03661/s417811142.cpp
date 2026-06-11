#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
const int maxn = 3e5+6;
using ll = long long;
array<ll,maxn>arr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    ll tot = 0;
    cin >> num;
    for(int i = 0;i<num;++i)
    {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    ll dis = 1e17;
    ll tmp = 0;
    for(int i = 0;i<num-1;++i) {
        dis = min(dis,abs(arr[i]-arr[num-1]+arr[i]));
    }
    cout << dis << endl;
}