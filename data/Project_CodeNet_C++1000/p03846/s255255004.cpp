#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;

int solve(int n){
    int ans = 1;
    
    for (int i = 1; i <= n; i++){
        ans *= 2;
        ans %= mod;
    }
    
    return ans;
}

int main(void){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> cnt(100002);
    
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    
    bool check = true;
    
    if (n % 2 == 1){
        
        if (cnt[0] != 1) check = false;
        
        for (int i = 2; i < n; i+=2){
            if (cnt[i] != 2) check = false;
        }
        
        if (check){
            cout << solve((n-1)/2) << endl;
            return 0;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
        
    }
    else if (n % 2 == 0){
        
        for (int i = 1; i < n; i+=2){
            if (cnt[i] != 2) check = false;
        }
        
        if (check){
            cout << solve(n/2) << endl;
            return 0;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
    
}
