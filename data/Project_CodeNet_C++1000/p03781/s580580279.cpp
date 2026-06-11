#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    i64 x;
    cin >> x;
    i64 sum = 0;
    for(i64 i=1;i<=x;++i){
        sum += i;
        if(sum >= x){
            cout << i << endl;
            break;
        }
    }

    return 0;
}