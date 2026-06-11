#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    string sa, sb ,sc;
    cin >> sa >> sb >> sc;

    queue<char> a;
    queue<char> b;
    queue<char> c;
    for(int ia=0;ia<sa.size();ia++) {
        a.push(sa.at(ia));
    }
    for(int ib=0;ib<sb.size();ib++) {
        b.push(sb.at(ib));
    }
    for(int ic=0;ic<sc.size();ic++) {
        c.push(sc.at(ic));
    }

    char p = 'a', card;
    while(1) {
        // cout << p;
        if(p=='a') {
            if(a.empty()) {
                cout << "A" << endl;
                return 0;
            }
            else {
                card = a.front(); a.pop();
            }
        }
        else if(p=='b') {
            if(b.empty()) {
                cout << "B" << endl; 
                return 0;
            }
            else {
                card = b.front(); b.pop();
            }
        }
        else { 
            if(c.empty()) {
                cout << "C" << endl; 
                return 0;
            }
            card = c.front(); c.pop();
        }
        p = card;
    }
    return 0;
}
