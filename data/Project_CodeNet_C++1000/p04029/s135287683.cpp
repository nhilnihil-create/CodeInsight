#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int N;
    cin >> N;
    int sum=0;
    rep(i,N)sum+=i+1;
    cout << sum << endl;
}