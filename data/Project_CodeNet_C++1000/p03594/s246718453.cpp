#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
using namespace std;
using ll = long long;
using pii = pair<int,int>;
template<typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> a){
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os, vector<T> v){
    for(auto x:v)os << x << ' ';
    return os;
}
void debug(){cerr << '\n';}
template<typename H, typename... T>
void debug(H a, T... b){
    cerr << a;
    if(sizeof...(b))cerr << ", ";
    debug(b...);
}
string s = "RYGB";
int main(){
    int h, w, d;
    cin >> h >> w >> d;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int k = (i + j) / d % 2;
            int l = abs(i - j - h + 1) / d % 2;
            cout << s[k * 2 + l];
        }
        cout << "\n";
    }
}