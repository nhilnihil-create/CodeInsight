/**
*    created: 10.05.2020 08:42:12
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    int N;
    cin >> N;
    int a[N];
    rep(i, N) cin >> a[i];
    int ans = 0;
    bool f,g;
    rep(i,N){
        if(i==0){
            f = true;
            continue;
        }
        if(f){
            if(a[i]>a[i-1]){
                g = 0;
                f = false;
            }else if(a[i]<a[i-1]){
                g = 1;
                f = false;
            }else{
                continue;
            }
        }else{
            if(g==0&&a[i]<a[i-1]){
                f = 1;
                ans++;
            }
            if(g==1&&a[i]>a[i-1]){
                f = 1;
                ans++;
            }
        }
    }
    ans++;
    cout << ans << endl;
}