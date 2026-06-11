// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ull  unsigned long long
typedef string str;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int INF = 1e9 + 5;
const int N = 2e5 + 123;
int main(){
    speed;
    int n;
    cin >> n;
    vi s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    sort(rall(s));
    ll x = 0, y = 0;
    for(int i = 0; i < n - 1; ++i){
        if(s[i] == s[i + 1] && x == 0){
            x = s[i];
            i++;
        }
        else if(s[i] == s[i + 1] && x != 0){
            if(y == 0){
                y = s[i];
                break;
            }
        }
    }
    cout << x * y;
}