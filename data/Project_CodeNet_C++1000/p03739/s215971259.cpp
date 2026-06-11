#include<bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll res1 = 0, res2 = 0;
    ll sum = 0;
    rep(i, n){
        if (i % 2 == 0 && sum + a[i] <= 0){
            res1 += abs(sum + a[i]) + 1;
            sum = 1;
        }else if (i % 2 == 1 && sum + a[i] >= 0){
            res1 += abs(sum + a[i]) + 1;
            sum = -1;
        }else{
            sum += a[i];
        }
    }
    sum = 0;
    rep(i, n){
        if (i % 2 == 0 && sum + a[i] >= 0){
            res2 += abs(sum + a[i]) + 1;
            sum = -1;
        }else if (i % 2 == 1 && sum + a[i] <= 0){
            res2 += abs(sum + a[i]) + 1;
            sum = 1;
        }else{
            sum += a[i];
        }
    }
    cout << min(res1, res2) << endl;
}