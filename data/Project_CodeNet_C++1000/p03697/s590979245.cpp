#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
ll A,B;

ll i, j, k;
int main(){
    scanf("%lld%lld", &A, &B);
    if(A+B<=9){
        printf("%lld\n", A + B);
    }else{
        printf("error\n");
    }

    return 0;
}