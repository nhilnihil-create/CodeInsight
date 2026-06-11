#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n){
        cin >> a[i];
        if(i%2 == 0 && n%2 == 0){
            b[n/2 + i/2] = a[i];
        }
        else if(i%2 == 1 && n%2==1){
            b[n/2 + i/2 + 1] = a[i];
        }
    }
    for(int i = n-1; i>=0; i--){
        int cnt = n-1 - i;
        if(cnt%2 == 0){
            b[cnt/2] = a[i];  
        }
    }
    for(int i:b){
        cout << i << " ";
    }
    return 0;
}
