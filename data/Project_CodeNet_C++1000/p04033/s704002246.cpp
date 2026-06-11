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

    int a,b;
    cin >> a >> b;

    if(a > 0 && b > 0){
        cout << "Positive" << endl;
    }else if(a <= 0 && 0 <= b){
        cout << "Zero" << endl;
    }else{
        int count = b - a + 1;

        if(count % 2 == 0){
            cout << "Positive" << endl;
        }else{
            cout << "Negative" << endl;
        }
    }

    return 0;
}
