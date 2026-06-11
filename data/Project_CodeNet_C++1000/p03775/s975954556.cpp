#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll n;
    cin >> n;
    int minimum = 20;
    double k = sqrt(n);
    for(int a = 1; a <= k; a++){
        if(n%a != 0) continue;
        int b = n/a;
        int al = to_string(a).size();
        int bl = to_string(b).size();
        int f = max(al,bl);
        minimum = min(f,minimum);
    }
    cout << minimum << endl;
}