#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define INF 100000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
int main(){
    int N,A,B;
    string S;
    cin >> N >> A >> B >> S;
    int kokunai = A + B;
    int sanka = 0;
    int kaigai = 0;
    for(int i = 0; i < N; i++){
        if (S[i] == 'a' && sanka < A+B){
            kokunai--;
            sanka++;
            cout << "Yes" << endl;
        }else if (S[i] == 'b' && kaigai < B && sanka < A+B){
            sanka++;
            kaigai++;
            cout << "Yes" << endl;
        }else if (S[i] == 'c'){
            cout << "No" << endl;
        }else {
            cout << "No" << endl;
        }
    }
    return 0;
}