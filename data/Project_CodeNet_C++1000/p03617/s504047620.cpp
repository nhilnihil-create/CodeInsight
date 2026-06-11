#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int q, h, s, d;
    ll n;
    cin >> q >> h >> s >> d >> n;
    
    vector<pair<int, int> > arr;
    arr.emplace_back(q * 8, 1);
    arr.emplace_back(h * 4, 2);
    arr.emplace_back(s * 2, 3);
    arr.emplace_back(d, 4);
    sort(arr.begin(), arr.end());

    ll ans = 0;
    for(auto a : arr){
        if(n == 0) break;
        switch(a.second){
            case 1: case 2: case 3:
                ans += n * a.first / 2;
                n = 0;
                break;
            case 4:
                if(n >= 2){
                    ans += n / 2 * d;
                    n %= 2;
                }
                break;
        }
    }
    cout << ans << endl;
    return 0;
}