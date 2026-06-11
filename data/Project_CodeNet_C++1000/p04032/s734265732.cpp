#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}


/*
長さ4以上のアンバランスあったとすると
その中には必ずaba あるいはaab bba なる区間がある
*/

int main() {
    string S; 
    cin >> S;
    int N = S.length();

    if (S[0] == S[1]) {
        cout << "1 2\n"; return 0;
    }
    for (int i = 2; i < N; i++) {
        if (S[i] == S[i-1]) {
            cout << i << " " << i+1 << endl; return 0;
        } else if (S[i] == S[i-2]) {
            cout << i-1 << " " << i+1 << endl; return 0;
        }
    }
    cout << "-1 -1\n";


}
