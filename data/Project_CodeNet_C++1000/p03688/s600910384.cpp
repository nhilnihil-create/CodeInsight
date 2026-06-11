#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    int a[n];
    rep(i,n){
        cin >> a[i];
    }
    sort(a, a + n);
    if(a[0] == a[n - 1]){
        if(a[0] == n - 1 || (1 <= a[n - 1] && a[n - 1] <= n / 2)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }
    if(a[n - 1] - a[0] != 1){
        cout << "No" << endl;
        return 0;
    }
    int s = 0, l = 0;
    rep(i,n){
        if(a[i] == a[0]) s++;
        else l++;
    }
    if(s + 1 <= a[n - 1] && a[n - 1] <= s + l / 2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}