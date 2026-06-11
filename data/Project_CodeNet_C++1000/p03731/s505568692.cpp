#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int64_t ans=t;
    vector<int> vec(n);
    for(int i=0; i<n; i++) cin >> vec.at(i);
    for(int i=0; i<n-1; i++) {
        if(t+vec.at(i)>vec.at(i+1)) ans += (vec.at(i+1)-vec.at(i));
        else ans += t;
    }
    cout << ans << endl;
}