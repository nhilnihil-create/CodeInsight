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
    const int M = 1e9 + 7;
    auto qpow = [&](long long x , int n){
        long long res = 1;
        for(;n;n>>=1){
            if(n&1)res = (res * x) % M;
            x = (x * x) % M;
        }
        return res;
    };
    cout << qpow(2 , n / 2) << endl;

    
}