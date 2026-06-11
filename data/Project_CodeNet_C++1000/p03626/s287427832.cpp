#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    string S1;
    cin >> S1;
    string S2;
    cin >> S2;
    ll ans = 1;
    ll prev = 0;
    ll now = 0;
    if (S1[0] == S2[0]){
        prev = 1;
        now++;
        ans = 3;
    }
    else{
        prev = 2;
        now += 2;
        ans = 6;
    }
    while(now < N){
        if (S1[now] == S2[now]){
            now++;
            if (prev == 1){
                ans = (ans * 2) % 1000000007;
                prev = 1;
            }
            else{
                prev = 1;
            }
        }
        else{
            now += 2;
            if (prev == 1){
                ans = (ans * 2) % 1000000007;
                prev = 2;
            }
            else{
                ans = (ans * 3) % 1000000007;
                prev = 2;
            }
        }
    }
    cout << ans << endl;
}