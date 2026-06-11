#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

bool solve(void){
    lint n;
    cin >> n;

    vector<lint> a(n);
    lint sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }

    lint s = n * (n + 1LL) / 2LL;
    if(sum % s != 0LL){
        return false;
    }

    lint k = sum / s;

    vector<lint> diff(n);
    rep(i, n){
        diff[i] = a[(i + 1) % n] - a[i] - k;
        if(diff[i] > 0LL || abs(diff[i]) % n != 0LL){
            return false;
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    if(solve()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}