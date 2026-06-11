#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void yes(){
    cout << "Yes" << endl;
    exit(0);
}

void no(){
    cout << "No" << endl;
    exit(0);
}

int main() {
    string s;
    cin >> s;
    bool N, W, S, E;
    N = W = S = E = false;

    for (int i=0; i<s.size(); i++){
        if (s[i] == 'N')N = true;
        if (s[i] == 'W')W = true;
        if (s[i] == 'S')S = true;
        if (s[i] == 'E')E = true;
    }

    if (N){
        if(!S)no();
    }
    if (W){
        if (!E)no();
    }
    if (S){
        if(!N)no();
    }

    if (E){
        if(!W)no();
    }
    
    yes();  
}