#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int a, b, c; cin >> a >> b >> c;
    bool isOK = false;
    for(int i = 1; i <= b; i++){
        if(a*i % b == c) isOK = true;
    }
    if(isOK) cout << "YES" << endl;
    else cout << "NO" << endl;
}