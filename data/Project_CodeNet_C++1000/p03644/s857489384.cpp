#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int N;
    cin >> N;
    rep(i,8){
        if(N<pow(2,i)){
            cout<<pow(2,i-1)<<endl;
            return 0;
        }
    }
}