#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A,B,C;
    cin>>A>>B>>C;
    long long ans = 10000000000;
    
    if(A % 2 * B % 2 * C % 2 == 0) ans = 0;
    else{
        long long tmp1,tmp2,tmp3;
        tmp1 = A*B;
        tmp2 = A*C;
        tmp3 = B*C;
        ans = min({tmp1,tmp2,tmp3});
    }

    cout<<ans<<endl;

    return 0;
}