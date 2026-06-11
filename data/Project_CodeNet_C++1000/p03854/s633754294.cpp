#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    string s; cin >> s;
    vector<string> list = {"maerd", "esare", "remaerd", "resare"};
    string t = s;
    reverse(t.begin(), t.end());
    for(ll i = 0; i < t.length(); ){
        bool z = false;
        for(auto j : list){
            string sub = t.substr(i, j.length());
            if(sub == j){
                i += j.length();
                z = true;
                break;
            }
        }
        if(!z){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}