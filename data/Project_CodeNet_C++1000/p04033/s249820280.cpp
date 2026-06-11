#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t a,b;
    cin >> a >> b;
    if(a*b<=0){
        cout << "Zero" << endl;
    }else{
        if(a>0){
            cout << "Positive" << endl;
        }else{
            int64_t diff = abs(b-a);
            if(diff%2==0){
                cout << "Negative" << endl;
            }else{
                cout << "Positive" << endl;
            }
        }
    }
}