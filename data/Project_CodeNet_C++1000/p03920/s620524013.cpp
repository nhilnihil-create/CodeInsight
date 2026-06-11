#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0, ub = 0;
    for(int i=1;i<=n;++i){
        sum += i;
        if(sum >= n){
            ub = i;
            break;
        }
    }

    for(int i=ub;i>0;--i){
        if(n >= i){
            cout << i << endl;
            n -= i;
        }
    }

    return 0;
}
