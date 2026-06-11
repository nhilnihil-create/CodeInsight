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

    int N, A, B;
    cin >> N >> A >> B;
    string s;
    cin >> s;

    int a = 0;
    int b = 0;

    rep(i, N){

        if(s[i] == 'a'){
            if(a + b < A + B){
                cout << "Yes" << endl;
                a++;
            }else{
                cout << "No" << endl;
            }
        }else if(s[i] == 'b'){
            if(a + b < A + B && b < B){
                cout << "Yes" << endl;
                b++;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}
