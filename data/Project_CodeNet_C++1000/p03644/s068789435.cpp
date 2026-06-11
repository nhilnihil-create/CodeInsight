#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main(){
    int n;
    cin >> n;
    int num = 1;
    int ans;

    for(int i = 1; i <= n; i++){
        if(num == n){
            ans = num;
            break;
        }
        else if( num > n ){
            ans = num / 2;
            break;
        }
        num *= 2;
    }
    cout << ans << endl; 
}
