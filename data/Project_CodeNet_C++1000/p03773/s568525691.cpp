#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    int ans;
    if(A + B < 24){
        ans = A + B;
    }else{
        ans = A + B - 24;
    }
    cout << ans;
}