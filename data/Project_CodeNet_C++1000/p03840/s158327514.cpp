#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll A[10],As[10];
ll i, j, k;

ll calc(bool flg){
    ll ret = 0;
    fornum(i,0,7){
        As[i] = A[i];
    }
    if(flg&&As[0]>0&&As[3]>0&&As[4]>0){
        ret += 3;
        --As[0];
        --As[3];
        --As[4];
    }
    ret += As[0] / 2 * 2;
    ret += As[1];
    ret += As[3] / 2 * 2;
    ret += As[4] / 2 * 2;
    return ret;
}
int main(){
    fornum(i,0,7){
        scanf("%lld", &A[i]);
    }

    printf("%lld", max(calc(false), calc(true)));
    return 0;
}