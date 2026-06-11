#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int n;
    cin >> n;

    ll factorial=1;
    for(int i=1;i<=n;++i){
        factorial = (factorial*i)%(1000000000+7);
    };
    cout<<factorial<<endl;
    return 0;
}