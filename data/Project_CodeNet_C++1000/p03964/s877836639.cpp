#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    int n; sc(n)
    int T[n], A[n];
    REP(i, n){
        sc(T[i])
        sc(A[i])
    }
    ll aT = T[0], aA = A[0];
    for (int i = 1; i < n; i++){
        if (aT < T[i]) aT = T[i];
        else if (aT % T[i] != 0) aT += T[i] - (aT % T[i]);
        if (aT / T[i] * A[i] < aA) aT += (aA - aT / T[i] * A[i]) / A[i] * T[i];
        if (aT / T[i] * A[i] < aA) aT += T[i];
        aA = aT / T[i] * A[i];
    }
    cout << aT + aA << endl;
    return 0;
}