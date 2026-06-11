#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

long Even(vector<int> a){
    long res = 0;
    long temp = 0;

    REP(i, a.size()){
        temp += a[i];
        if (i % 2 == 0){
            while (temp <= 0){
            temp += 1;
            res += 1;
            }
        }
        else{
            while (temp >= 0){
            temp += -1;
            res += 1;
            }
        }
    }
    return res;
}

long Odd(vector<int> a){
    long res = 0;
    long temp = 0;

    REP(i, a.size()){
        temp += a[i];
        if (i % 2 == 0){
            while (temp >= 0){
            temp += -1;
            res += 1;
            }
        }
        else{
            while (temp <= 0){
            temp += 1;
            res += 1;
            }
        }
    }
    return res;
}

int main() {
    int n, ans;
    cin >> n;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    
    cout << min(Even(a), Odd(a)) << endl;
}