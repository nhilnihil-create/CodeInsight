#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
#define VI vector<int>
#define VL vector<LL>
#define VII vector< vector<int> >
#define VLL vector< vector<LL> >
#define VS  vector<string>
#define VSS vector< vector<string> >
#define PII pair<int,int>
#define PIS pair<int,string>
#define PSI pair<string,int>
#define PLL pair<LL,LL>
const LL MOD = 1000000007;
const LL INF = 1e16;
LL facctorialMethod(int k);
int main(){
    LL n,k,total;
    cin >> n >> k;
    VL l(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(l.begin(),l.end());
    reverse(l.begin(),l.end());

    total = 0;
    for(int i = 0; i < k; i++) {
        total += l[i];
    }
    cout << total << endl;

    return 0;
}

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}
