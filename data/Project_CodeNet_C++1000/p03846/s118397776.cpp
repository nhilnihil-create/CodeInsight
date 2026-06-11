#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int const mod = 1000000007;
    long int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    long int ans = 1;
    if (n % 2 == 0){
        int num[n/2];
        rep(i, n / 2) num[i] = 0;
        rep(i, n){
            if (a[i] % 2 == 0){
                cout << 0 << endl;
                return 0;
            }
            long int idx = a[i] / 2;
            if (num[idx] > 1){
                cout << 0 << endl;
                return 0;     
            }
            num[idx]++;
        }
        
        rep(i, n / 2){
            ans *= 2;
            ans %= mod;
        }
    }else{
        int num[n/2+1];
        rep(i, n / 2 + 1) num[i] = 0;
        rep(i, n){
            if (a[i] % 2 == 1){
                cout << 0 << endl;
                return 0;
            }
            long int idx = a[i] / 2;
            if (idx > 0 && num[idx] > 1){
                cout << 0 << endl;
                return 0;     
            }else if (idx == 0 && num[idx] > 0){
                cout << 0 << endl;
                return 0;
            }
            num[idx]++;
        }
        
        rep(i, n / 2){
            ans *= 2;
            ans %= mod;
        }
    }
    
    cout << ans << endl;

}