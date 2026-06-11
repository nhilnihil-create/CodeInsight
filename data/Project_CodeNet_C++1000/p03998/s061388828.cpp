#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define mk make_pair
#define S second
#define F first
typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
string s[3];
int v[3], p;

void fim() {
    
}

int main(int argc, char ** argv) {
    rep(i, 0, 3) cin >> s[i];
    while(1 < 2) {
        if(v[p] == s[p].size()) {
            printf("%c\n", p+'A');
            return 0;
        }
        int P = s[p][v[p]]-'a';
        v[p]++;
        p = P;
    }
    return 0;
}
