#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define PI (acos(-1.0))
#define MODN 1000000007
#define MODN2 998244353
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    int A,B,C,a,b,c;
    cin >> A >> B >> C;

    if(A % 2 == 1 || B % 2 == 1 || C % 2 == 1){
        cout << 0 << endl;
    }else{

        a = A;
        b = B;
        c = C;

        int count = 0;

        do{

            int tmpc = c;
            int tmpb = b;

            c = (a + b) / 2;
            b = (a + tmpc) / 2;
            a = (tmpb + tmpc) / 2;

            count++;

            //cerr << a << " " << b << " " << c << endl;


            if(a == A && b == B && c == C){
                count = -1;
                break;
            }

        }while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0);

        cout << count << endl;
    }
    return 0;
}
