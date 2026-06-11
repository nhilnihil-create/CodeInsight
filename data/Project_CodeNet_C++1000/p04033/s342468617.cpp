//url:
//problem name: Brick Break

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    ll a,b;
    cin >> a >> b;
    if(a == 0 || b == 0 || (a < 0 && 0 < b)) {
        cout << "Zero" << endl;
        return 0;
    }
    if(a > 0 && b > 0) {
        cout << "Positive" << endl;
        return 0;
    }
    if(a < 0 && b < 0 && (b-a+1)%2 == 0) {
        cout << "Positive" << endl;
        return 0;
    }  
    if(a < 0 && b < 0 && (b-a+1)%2 != 0) {
        cout << "Negative" << endl;
        return 0;
    }  
}