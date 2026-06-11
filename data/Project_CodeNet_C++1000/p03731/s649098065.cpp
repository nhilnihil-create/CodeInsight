#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, T;
    cin >> n >> T;
    
    vector<long long> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    
    long long ans = 0;
    
    for (int i = 1; i < n; i++){
        
        // 次の人が来るまでの時間を計算する
        long long diff = t[i]-t[i-1];
        
        // 次の人がT秒以内に来るならば、お湯は出続ける.
        // そうでなければ, お湯はT秒間出て止まる.
        ans += min(T, diff);
    }
    
    
    // 注意せよ. 最後にボタンが押された時, お湯がT秒間必ず出る.
    ans += T;
    cout << ans << endl;
}

