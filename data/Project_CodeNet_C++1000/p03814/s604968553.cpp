#include <bits/stdc++.h>

using namespace std;

#define vv vector< vector< int > >
#define ll long long
#define ALL(a) (a).begin(), (a).end()
const long long mod = 1000000000 + 7;
const long long INF = 9e18;
const double PI = 3.14159265358979323846;

ll gcd(ll a, ll b){if (b == 0) return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main(){
    string S;
    cin >> S;
    int a, z;
    a = S.find('A');
    z = S.rfind('Z');
    cout << z - a + 1 << endl;
    return 0;
}


