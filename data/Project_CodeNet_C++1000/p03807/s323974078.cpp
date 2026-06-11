#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int N;
    cin >> N;
    int o=0;
    int tmp;
    rep(i,N){
        cin >> tmp;
        if(tmp %2 == 1){
            o++;
        }
    }
    if(o%2==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}