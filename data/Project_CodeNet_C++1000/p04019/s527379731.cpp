#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    string a;
    cin >> a;
    int n = 0,w = 0,s = 0,e = 0;
    rep(i,a.size()){
        if(a[i] == 'N')n = 1;
        else if(a[i] == 'W')w = 1;
        else if(a[i] == 'S')s = 1;
        else if(a[i] == 'E')e = 1;
    }
    if(s == n && w == e) cout << "Yes" << endl;
    else cout << "No" << endl;
}
