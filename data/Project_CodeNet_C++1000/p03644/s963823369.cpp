#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int ex[7]={1,2,4,8,16,32,64};
    int n;
    cin >> n;
    rep(i,7){
        if(ex[i]>n){
            cout << ex[i-1];
            return 0;
        }
    }
    cout << ex[6];
    return 0;
}