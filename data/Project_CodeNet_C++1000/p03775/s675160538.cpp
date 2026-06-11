#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll n;
    cin >> n;
    int a = 0;
    for(int i = 1;i <= sqrt(n);i++){
        if(n%i == 0) a = max(a,i);
    }
    int d = floor(log10(n/a)) + 1;
    //cout << a << endl;
    cout << d << endl;
}
