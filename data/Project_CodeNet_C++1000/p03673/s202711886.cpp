
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    string b;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    //数列の個数が偶数の場合
    if(n%2==0){
        for(int i=0; i<n; i+=2){
            cout << a[n-1-i] << ' ';
        }
        for(int i=0; i<n; i+=2){
            cout << a[i] << ' ';
        }
        cout << endl;
        return 0;
    }
    else{
        for(int i=0; i<n; i+=2){
            cout << a[n-1-i] << ' ';
        }
        for(int i=1; i<n; i+=2){
            cout << a[i] << ' ';
        }
        cout << endl;
        return 0;
    }
}