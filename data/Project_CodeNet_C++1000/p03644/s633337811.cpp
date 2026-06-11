/*
      author  : nishi5451
      created : 14.08.2020 14:15:14
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    int res = 1;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    while(1){
        if(res*2 > n){
            break;
        }
        res*=2;
    }
    cout << res << endl;


    return 0;
}