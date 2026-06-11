#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    
    set<int> check;
    
    bool ans;
    int x = A;
    while(true){
        x = x%B;
        if(x == C){
            ans = true;
            break;
        }else if(check.count(x)){
            ans = false;
            break;
        }
        check.insert(x);
        x += A;
    }
    
    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
