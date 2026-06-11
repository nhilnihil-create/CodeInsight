#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    
    int push = max(A,C);
    int sep = min(B,D);
    
    int ans = sep - push;
    
    if(ans<0){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
}
