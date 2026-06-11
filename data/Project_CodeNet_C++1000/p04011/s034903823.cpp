#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,k,x,y;
    cin >> n >> k >> x >> y;
    ll total = 0;
    if(n > k){
      total = k*x;
      total += (n-k)*y;
    }else{
      total = n*x;
    }
    cout << total;
}