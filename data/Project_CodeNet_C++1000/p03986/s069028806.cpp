#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll,ll>;

void solve(std::string X){
    ll ans = X.size();
    ll sNum=0;
    for(int i=0;i<X.size();i++){
        if(X[i] == 'S'){
            sNum++;
        }else if(sNum>0){
            sNum--;
            ans -=2;
        }
    }
    cout << ans << endl;

}

int main(){
    std::string X;
    std::cin >> X;
    solve(X);
    return 0;
}
