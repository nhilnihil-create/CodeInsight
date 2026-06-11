#include <iostream>
#include <vector>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;
const ll mod = 1000000007;

int main() {
    char a,b;
    cin >> a >> b;

    if((a == 'H' && b == 'H') || (a == 'D' && b == 'D')){
        cout << 'H' << endl;
    } else {
        cout << 'D' << endl;
    }
 
    return 0;
}