#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n,k,x,y;
    cin >> n >> k >> x >> y;
    if(n <= k)cout << x*n;
    else cout << x*k+y*(n-k);
}