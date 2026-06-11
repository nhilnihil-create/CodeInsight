#include <bits/stdc++.h>

using namespace std;

int main() {
    int n ; cin >> n;
    bool ok = false;
    vector<int>v(n) , mark(n + 1);
    for(int& i : v){
        cin >> i;
        if(i % 2 == n % 2)ok = true;
        mark[i]++;
        if(mark[i] > 2){
            ok = true;
        }
    }
    int z = count(v.begin() , v.end() , 0);
    if(z && n % 2 == 0){
        cout << 0 << endl;
        return 0;
    }
    if(z > 1 || ok){
        cout << 0 << endl;
        return 0;
    }
    int half = n / 2 ;
    long long ans = 1;
    const int M = 1e9 + 7;
    for(int i = 1 ; i <= half; ++i){
        ans = (ans * 2) % M;
    }
    cout << ans << endl;

    
}