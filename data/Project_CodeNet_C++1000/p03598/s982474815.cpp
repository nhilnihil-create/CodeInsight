#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    int n;  
    int k;
    cin >> n;
    cin >> k;

    // int x[n];
    int sum = 0;

    rep(i, n){
        int xi;
        cin >> xi;
        int disCan1 = xi; 
        int disCan2 = k - xi;
        if(disCan1 < disCan2){
            sum += disCan1 * 2;
        }else{
            sum += disCan2 * 2;
        }
    }
    
    cout << sum << endl;
}