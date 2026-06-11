//Two Switches
#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int lower = max(a,c);
    int upper = min(b,d);
    
    cout<< max(0,upper - lower) <<endl;
    return 0;
}