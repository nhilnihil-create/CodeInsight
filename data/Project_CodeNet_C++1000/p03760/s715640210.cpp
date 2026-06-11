#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    string o,e,ans="";
    cin >> o >> e;
    int O = o.size();
    int E = e.size();

    int size = max(O,E);
    rep(i,0,size-1){
        ans += o.at(i);
        ans += e.at(i);
    }
    if(O==E){
        ans += o.at(size-1);
        ans += e.at(size-1);
    }
    if(O>E) ans += o.at(size-1);
    if(O<E) ans += e.at(size-1);
    cout << ans << endl;

}