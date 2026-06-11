#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
const int MAX_N = 100100;

ll A[MAX_N*3];
int main(){
    int N;
    cin >> N;
    REP(i,3*N){
        ll a;
        cin >> a;
        A[i] = a;
    }
    priority_queue<ll, vector<ll>, greater<ll> > qx;
    priority_queue<ll, vector<ll> > qy;

    ll xsum = 0;
    ll ysum = 0;
    for(int i = 0; i < N; i++){
        ll x = A[i];
        qx.push(x);
        xsum += x;
    }

    for(int i = 0; i < N; i++){
        ll y = A[i+2*N];
        qy.push(y);
        ysum += y;
    }

    ll XSUM[MAX_N];
    XSUM[0] = xsum;
    for(int i = N; i < 2*N; i++){
        ll z = A[i];
        ll x_min = qx.top();
        if(z > x_min){
            qx.pop();
            qx.push(z);
            xsum -= x_min;
            xsum += z;
        }
        XSUM[i-N+1] = xsum;
    }

    ll YSUM[MAX_N];
    YSUM[N] = ysum;
    for(int i = 2*N - 1; i >= N; i--){
        ll z = A[i];
        ll y_max = qy.top();
        if(z < y_max){
            qy.pop();
            qy.push(z);
            ysum -= y_max;
            ysum += z;
        }
        YSUM[i-N] = ysum;
    }

    ll ans = LLONG_MIN;
    REP(i,N+1){
        ll diff = XSUM[i] - YSUM[i];
        //printf("xsum:%lld\tysum:%lld\tdiff:%lld\n", XSUM[i], YSUM[i], diff);
        ans = max(ans, diff);
    }
    cout << ans << endl;
    return 0;
}
