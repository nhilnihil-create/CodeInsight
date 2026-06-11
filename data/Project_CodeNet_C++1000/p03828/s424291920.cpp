#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<int,int> m;
    for (int j = N; j >= 1; j--){
        if (j == 1) continue;
        else{
            int k = j;
            for (int i = 2; i <= 1000; i++){
                while (k % i == 0){
                    if (!m.count(i)) m[i] = 1;
                    else m.at(i)++;
                    k /= i;
                }
            }
            
        }
        
    }
    int64_t ans = 1;
    for (auto x : m){
        auto value = x.second;
        ans *= (value + 1);
        ans %= 1000000007;
    }
    cout << ans << endl;
}