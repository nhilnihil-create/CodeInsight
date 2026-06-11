#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
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
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    double ans = 0;
    int sw, s;
    for (int i = 0;i <= 30;i++){
        for (int j = 0;j <= 30;j++){
            int water = 100*a*i + 100*b*j;
            if (water > f){
                continue;
            }
            int mx = min(water/100 * e, f - water);
            for (int k = 0;k <= mx;k++){
                for (int l = 0;c*k + d*l <= mx;l++){
                    int sugar = c*k + d*l;
                    double de = sugar * 100.0f / (sugar + water);
                    if (de >= ans){
                        ans = de;
                        sw = sugar + water;
                        s = sugar;
                    }
                }
            }
        }
    }
    cout << sw << " " << s << endl;
    return 0;
}