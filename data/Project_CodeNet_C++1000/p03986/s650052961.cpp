#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    string S; cin >> S;
    int N = S.size();
    deque<char> deq;
    REP(i,N) {
        if(S[i] == 'T') {
            if(deq.empty()) deq.push_front('T');
            else if(deq.front() == 'S') deq.pop_front();
            else deq.push_front('T');
        } else deq.push_front('S');
    }
    cout << deq.size() << endl;
}