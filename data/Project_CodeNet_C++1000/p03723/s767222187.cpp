#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)

typedef long long ll;
typedef long double ld;

int main(){
    int a,b,c; 
    cin >> a >> b >> c; 

    ll i(0);

    while(a%2==0 && b%2==0 && c%2==0){
        int ab,ac,ba,bc,ca,cb;
        ab = ac = a/2;
        ba = bc = b/2;
        ca = cb = c/2;
        a = a + ba + ca; b = b + ab + cb; c = c + ac + bc;
        i++;
        if(i == 100000000){
            i = -1;
            break;
        }
    }

    cout << i << endl;
    return 0;
}