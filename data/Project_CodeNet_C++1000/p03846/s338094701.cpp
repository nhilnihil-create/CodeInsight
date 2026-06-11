#include <iostream>
using namespace std;

static const int MAX = 100000;
static const int INFTY = 1e+9 + 7;

int power(int a, int n){
    if(n == 0) return 1;
    if(a == 0) return 0;
    return (a * power(a, n - 1)) % INFTY;
}

int main(){
    int n, a, A[MAX] = {}; 
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        A[a]++;
    }

    bool flag = true;
    if((n % 2) && (A[0] == 1)){
        for(int i = 2; i < n; i += 2)
            if(A[i] != 2){
                flag = false;
                break;
            }
    } else if(!(n % 2)) {
        for(int i = 1; i < n; i += 2)
            if(A[i] != 2){
                flag = false;
                break;
            }
    } else flag = false;

    if(flag) cout << power(2, n / 2) << endl;
    else cout << 0 << endl;

    return 0;
}