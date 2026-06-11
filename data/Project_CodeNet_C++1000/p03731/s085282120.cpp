#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int n, T;
    cin >> n >> T;
    long int t[n];
    rep(i, n) cin >> t[i];
    long int ans = 0;
    long int dif = 0;

    rep(i, n - 1){
        ans += min(T, t[i+1] - t[i]);        
    }
    ans += T;
    cout << ans << endl;
}
