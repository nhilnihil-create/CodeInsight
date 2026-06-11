#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    vector<int>b;
    for(int i = 1;i<n;i += 2) {
        b.push_back(a[i]);
    }
    reverse(b.begin(),b.end());
    for(int i = 0;i<n; i+= 2) {
        b.push_back(a[i]);
    }
    if(n%2 == 1) reverse(b.begin(),b.end());
    rep(i,n) {
        cout << b[i] << " ";
    }
    cout << endl;
}