#include<bits/stdc++.h>
using namespace std;
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    bool ans = false;
    for(int i = 1; i <= B; i++){
        if(A * i % B == C){
            ans = true;
        }
    }
    if(ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}