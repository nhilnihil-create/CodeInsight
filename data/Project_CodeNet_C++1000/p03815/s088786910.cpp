#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
ll x;cin >> x;
if(x%11 == 0)cout << 2*(x/11);
if(x%11 >= 1 && x%11 <= 6)cout << (x/11)*2 + 1;
if(x%11 > 6)cout << (x/11)*2 + 2;
}