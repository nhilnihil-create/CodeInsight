#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    int ans = 0;
    for(int i=1; i<n; i++){
        if(pow(2,i)>n){
            ans = pow(2,i);
            break;
        }
    }
    if(n==1){
        cout << 1 <<endl;
    }else{
        cout << ans/2 <<endl;
    }
}