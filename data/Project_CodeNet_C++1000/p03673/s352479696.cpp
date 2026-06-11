#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b;
    rep(i, n) cin >> a[i];
    for(int i = n-1; i >= 0; i -=2){
        b.push_back(a[i]);
    }
    int j = n % 2;
    for(;j < n; j += 2){
        b.push_back(a[j]);
    }
    rep(i, n) cout << b[i] << " ";
    cout << endl;
    return 0;
}