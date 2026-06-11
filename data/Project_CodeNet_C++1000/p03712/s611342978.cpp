#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char> (w));
    rep(i, h) rep(j, w){
        cin >> a[i][j];
    }
    rep(i, h+2){
        rep(j, w+2){
            if(i == 0 || i == h+1){
                cout << '#';
            }
            else{
                if(j==0 || j==w+1) cout << '#';
                if(!(j==0 || j==w+1))cout << a[i-1][j-1];
            }
        }
        cout << '\n';
    }
    return 0;
}