#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

long int a[1001];

void fact(long int x){
    long int t = x;
    for (long int i = 2; i * i <= x; i++){
        while (t % i == 0){
            a[i]++;
            t =  t / i;
        }
    }
    if (t > 1){
        a[t]++;
    }
    
    
}

int main(){
    long int const mod = 1000000007;
    long int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        fact(i);
    }
    long int ans = 1;
    for (int i = 2; i <= 1000; i++){
        ans *= a[i] + 1;
        ans %= mod;
    }
    cout << ans << endl;
    // rep(i, 20) cout << a[i] << " ";
    // cout << endl;

}