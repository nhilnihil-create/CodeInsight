#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define sf scanf
#define pf printf
#define iAmSpeed ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main(){
    iAmSpeed;
    ll a, b, c;
    cin >> a >> b >> c;
    ll temp = a;
    a /= c;
    b /= c;
    if(temp % c == 0){
        cout << b - a + 1 << '\n';
    }
    else{
        cout << b - a << '\n';
    }
    return 0;
}
