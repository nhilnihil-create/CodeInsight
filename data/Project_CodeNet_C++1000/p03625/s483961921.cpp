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
    int n;
    cin >> n;
    map<long long, int> mp;
    bool ok = false;
    for (int i = 0;i < n;i++){
        long long a;
        cin >> a;
        mp[a]++;
    }
    long long m1 = 0, m2 = 0;
    for (auto v:mp){
        if (v.second >= 2){
            if (v.first > m1){
                m2 = m1;
                m1 = v.first;
            }
            else if (v.first > m2){
                m2 = v.first;
            }
        }
    }

    if (m1 == 0 || m2 == 0){
        cout << 0 << endl;
        return 0;
    }

    if (mp[m1] >= 4){
        cout << m1 * m1 << endl;
    } else{
        cout << m1 * m2 << endl;
    }
}