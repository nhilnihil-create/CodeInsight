#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

int main()
{
    string s[3];
    rep(i, 3) {
        cin >> s[i];
        reverse(all(s[i]));
    }

    char next = 'a';
    while(true) {
        int id = next - 'a';
        if(s[id].empty()) {
            cout << char(next - 'a' + 'A') << endl;
            return 0;
        }
        next = s[id].back();
        s[id].pop_back();
    }

    return 0;
}
