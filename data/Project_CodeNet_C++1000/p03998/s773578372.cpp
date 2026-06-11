#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void dodo(char i,queue<char>qua,queue<char>qub,queue<char>quc){
    if (i == 'a') {
        if(qua.empty()){
            cout << 'A' << endl;
            return;
        }
        char t = qua.front();
        qua.pop();
        dodo(t, qua, qub, quc);
    } else if (i == 'b') {
        if(qub.empty()){
            cout << 'B' << endl;
            return;
        }
        char t = qub.front();
        qub.pop();
        dodo(t, qua, qub, quc);
    } else {
        if(quc.empty()){
            cout << 'C' << endl;
            return;
        }
            char t = quc.front();
            quc.pop();
            dodo(t, qua, qub, quc);
    }
}
int main(){
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    queue<char> a, b, c;
    for (ll i = 0; i < sa.size(); i++) a.push(sa[i]);
    for (ll i = 0; i < sb.size(); i++) b.push(sb[i]);
    for (ll i = 0; i < sc.size(); i++) c.push(sc[i]);
    dodo('a', a, b, c);
}