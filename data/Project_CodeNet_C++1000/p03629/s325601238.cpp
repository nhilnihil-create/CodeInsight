#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const int maxN = 2e5 + 10;
const int inf = 1e9 + 7;

string s, ans;
int n;
int f[maxN], p[30], t[maxN][30];

void trace(int pos)
{
    if(f[pos] == 0){
        int tmp = -1;
        for(int i = 0; i < 26; ++i){
            if(t[pos][i] == -1){
                tmp = i;
                break;
            }
        }
        ans += (tmp + 'a');
    }
    else{
        int tmp = -1;
        for(int i = 0; i < 26; ++i){
            if(f[t[pos][i]] + 1 == f[pos]){
                tmp = i;
                break;
            }
        }
        ans += (tmp + 'a');
        trace(t[pos][tmp]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();

    cin >> s;
    n = s.length();

    s = " " + s;

    for(int i = 0; i < 26; ++i)
        p[i] = -1;
    for(int i = n; i >= 0; --i){
        for(int j = 0; j < 26; ++j)
            t[i][j] = p[j];
        if(i) p[s[i] - 'a'] = i;
    }

    for(int i = n; i >= 0; --i){
        int minn = inf, flag = 1;
        for(int j = 0; j < 26; ++j){
            if(t[i][j] == -1){
                flag = 0;
                break;
            }
            else
                minn = min(minn, f[t[i][j]]);
        }
        if(flag) f[i] = minn + 1;
        else f[i] = 0;
    }

    //cout << f[0] + 1 << endl;
    trace(0);
    cout << ans;
}
