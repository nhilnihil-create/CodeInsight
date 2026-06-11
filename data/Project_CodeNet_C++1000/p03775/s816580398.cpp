#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int maxfig(ll A,ll B){
    int cntA = 0,cntB = 0;

    while(A > 0){
        A /= 10;
        cntA++;
    }

    while(B > 0){
        B /= 10;
        cntB++;
    }

    if(cntA > cntB)
        return cntA;

    else
        return cntB;
}

int main(void)
{
    ll N;
    int ans = 20;
    cin >> N;

   for(ll i = 1;i*i <= N;i++){
       if(N%i == 0){
           ans = min(ans,maxfig(i,N/i));
       }
   }

   cout << ans << endl;

    return 0;
}