#include <iostream>
#include <math.h>
using namespace std;

#define vv vector< vector< int > >
#define ll long long
#define ALL(a) (a).begin(), (a).end()
const long long mod = 1000000000 + 7;
const long long INF = 9e18;
const double PI = 3.14159265358979323846;

ll gcd(ll a, ll b){if (b == 0) return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main(){
    int A, B, C, ans = -1;
    cin >> A >> B >> C;
    int i = 0;
    while (i <= 1E8){
        if(A % 2 != 0 || B % 2 != 0 || C % 2 != 0){
            ans = i;
            break;
        }
        int ta = A;
        int tb = B;
        int tc = C;
        A = tb / 2 + tc / 2;
        B = ta / 2 + tc / 2;
        C = tb / 2 + ta / 2;
        i++;
    }
    cout << ans << endl;
    return 0;
}
