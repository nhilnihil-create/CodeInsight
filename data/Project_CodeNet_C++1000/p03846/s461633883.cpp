#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int cnt[1010101];

int solve(int n){
    int ans = 1;
    
    if (n % 2 == 1){
        if (cnt[0] != 1) return 0;
        
        for (int i = 2; i < n; i +=2){
            if (cnt[i] != 2) return 0;
            (ans *= 2) %= mod;
        }
        
        return ans;
    }
    else{
        for (int i = 1; i < n; i+=2){
            if (cnt[i] != 2) return 0;
            (ans *= 2) %= mod;
        }
        
        return ans;
    }
}


int main(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        cnt[a]++;
        
    }
    cout << solve(n) << endl;
    return 0;
}