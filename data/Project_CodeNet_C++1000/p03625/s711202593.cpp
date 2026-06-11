#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    map<long long, int, greater<long long>> mp;
    for(int i = 0; i < N; i++){
        long long hoge = 0;
        cin >> hoge;
        mp[hoge]++;
    }
    
    long long ans = 0;
    int count = 0;
    for (auto x : mp) {
        //cout << x.first << " : " << x.second << endl;
        if (x.second >= 4 && count == 0) {
            long long a = x.first * x.first;
            ans = max(ans, a);
            count += 2;
            break;
        } else if (x.second >= 2) {
            if (count == 0) {
                ans = x.first;
                count++;
            }else if(count == 1){
                ans *= x.first;
                count++;
                break;
            }
        }
    }
    
    if (count == 2) {
        cout << ans << endl;
    }else{
        cout << "0" << endl;
    }
}