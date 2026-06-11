#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)



int main(){
    long int n, a, b;
    cin >> n >> a >> b;
    long int x[n];
    rep(i, n) cin >> x[i];
    long int ans = 0;
    rep(i, n - 1){
        if ((x[i+1] - x[i]) * a > b){
            ans += b;
        }else{
            ans += (x[i+1] - x[i]) * a;
        }
    }
    cout << ans << endl;
}