#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const ll INFL = 1e18;
const ll mod = 1e9 + 7;
 
int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}
 
ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

bool is_prime(long long N){
    if (N == 1) return false;
    for (long long i = 2;i * i <= N;i++){
        if (N % i == 0) return false;
    }
    return true;
}
 
ll lcm(ll a,ll b){
    return ((a * b == 0)) ? 0 : (a / gcd(a,b) * b);
}
 
double DegreeToRadian(double degree){
    return degree * M_PI / 180.0;
}
 
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
 
///////////////////////////////////////////////////////////////////////////////////

int main(){
    long long x, y;
    cin >> x >> y;
    long long res = 1e18;
    for (int i = 1;i < x;i++){
        long long a = (x - i) * y;
        long long b = i * (y / 2);
        long long c = x * y - a - b;
        res = min(res, max(a, max(b, c)) - min(a, min(b, c)));
        a = i * y;
        b = (x - i) / 2 * y;
        c = x * y - a - b;
        res = min(res, max(a, max(b, c)) - min(a, min(b, c)));
    }
    for (int i = 1;i < y;i++){
        long long a = (y - i) * x;
        long long b = i * (x / 2);
        long long c = x * y - a - b;
        res = min(res, max(a, max(b, c)) - min(a, min(b, c)));
        a = i * x;
        b = (y - i) / 2 * x;
        c = x * y - a -b;
        res = min(res, max(a, max(b, c)) - min(a, min(b, c)));
    }
    cout << res << endl;
}