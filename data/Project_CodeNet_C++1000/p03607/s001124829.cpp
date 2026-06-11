#include <bits/stdc++.h>
using namespace std;
int main(){
        long long int n; cin >> n;
        map<long long int, long long int> mp;
        for (long long int x = 0; x < n; ++x){
            long long int q; cin >> q;
            mp[q]++;
        }
        long long int c = 0;
        for (auto x : mp){
            if (x.second % 2 != 0) c++;
        }
        cout << c << endl;
    return 0;
}
