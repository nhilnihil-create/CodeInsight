#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
int main() {

    int A, B, C;
    cin >> A >> B >> C;

    int ans = 0;
    for(;A%2==0 && B%2==0 && C%2==0 && A!=0;ans++){
        int tmpA = B/2 + C/2;
        int tmpB = A/2 + C/2;
        int tmpC = A/2 + B/2;
        A = tmpA;
        B = tmpB;
        C = tmpC;
        if(A==B && B==C){
            ans = -1;
            break;
        }
    }
    

    cout << ans << endl;

    return 0;

}