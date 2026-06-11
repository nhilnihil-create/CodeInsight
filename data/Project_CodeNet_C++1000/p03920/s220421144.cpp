#include <iostream>
using namespace std;
typedef long long ll;
ll n, sum, res;
int main(void){
    // Your code here!
    cin >> n;
    for (ll i = 1; ; i++) {
        sum += i;
        if (sum >= n) {
            for (ll j = 1; j <= i; j++) {
                if (j == sum - n) continue;
                cout << j << endl;
            }
            break;
        }
    }
}
