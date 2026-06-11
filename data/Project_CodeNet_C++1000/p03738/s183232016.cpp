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

    string a,b;
    cin >> a;
    cin >> b;

    int asize = a.size();
    int bsize = b.size();

    if(asize > bsize){
        cout << "GREATER" << endl;
    }else if(asize < bsize){
        cout << "LESS" << endl;
    }else{

        bool finish = false;

        rep(i, asize){
            if(a[i] > b[i]){
                finish = true;
                cout << "GREATER" << endl;
                break;
            }else if(a[i] < b[i]){
                finish = true;
                cout << "LESS" << endl;
                break;
            }
        }

        if(!finish){
            cout << "EQUAL" << endl;
        }

    }
    return 0;
}
