#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    string s;
    
    for(int i = 0;i < abs(y2-y1);i++) s += "U";
    for(int i = 0;i < abs(x2-x1);i++) s += "R";
    s += "U";
    for(int i = 0;i < abs(x2-(x1-1));i++) s+= "L";
    for(int i = 0;i < abs(y2-(y1-1));i++) s += "D";
    s += "R";
    for(int i = 0;i < abs(x2-x1);i++) s += "R";
    for(int i = 0;i < abs(y2-y1);i++) s += "U";
    s += "R";
    for(int i = 0;i < abs(y2-(y1-1));i++) s += "D";
    for(int i = 0;i < abs((x2+1)-x1);i++) s += "L";
    s += "U";
    cout << s;
}


