#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int f(int a, int b){
    return max(to_string(a).size(), to_string(b).size());
}

int main(){
    ll n; cin >> n;
    int min_val = INT_MAX;
    for(int i=1; i<=(int)sqrt((double)n); i++){
        if(n%i != 0) continue;
        min_val = min(min_val, f(i, n/i));
    }
    cout << min_val << endl;
}
