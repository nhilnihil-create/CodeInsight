#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;


int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >>n;
    long d = pow(10,9)+7;
    long power = 1;
    for(int i=1;i<=n;i++){
        power = i * power % d;
    }
    cout << power<<endl;
}