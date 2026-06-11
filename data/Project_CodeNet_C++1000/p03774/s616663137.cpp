#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

template <class T, class U> ostream& operator<< (ostream &out, pair<T,U> c) { out << "(" << c.first << " "; out << c.second << ")"; return out; }
template <class T> ostream& operator<< (ostream &out, vector<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
const double PI  = 3.141592653589793238463;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> s(n);
    vector<pair<int,int>> p(m);
    int a, b;
    FOR(i,0,n){
        cin >> a >> b;
        s[i] = MP(a,b);
    }
    FOR(i,0,m){
        cin >> a >> b;
        p[i] = MP(a,b);
    }
    FOR(i,0,n){
        int ind;
        int mini = 1e9;
        FOR(j,0,m){
            int distance = abs(s[i].first - p[j].first) + abs(s[i].second - p[j].second);
            if (distance < mini){
                mini = distance;
                ind = j + 1;
            }
        }
        cout << ind << endl;
    }
}
