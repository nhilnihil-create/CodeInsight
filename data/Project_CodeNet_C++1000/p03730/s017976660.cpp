#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int a,b,c;
    cin >> a >> b >>c;

    bool can = false;
    for(int i=1;i<=b;++i){
        if((i*a)%b==c){
            can = true;
        }
    }
    if(can) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}