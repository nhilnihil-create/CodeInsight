#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
#define MOD 1000000007
int main() {
    int N;
    cin >> N;
    int a = 0,b = 0,c =0;
    rep(i, 0, N){
        ll tmp;
        cin >> tmp;
        if(tmp%4 == 0){
            a++;
        } else if (tmp%2 == 0){
            b++;
        } else {
            c++;
        }
    }
    
    if (a>=c) {
        cout << "Yes" << endl;
    } else if ( c == a+1 && b == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
