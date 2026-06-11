#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

int prv[N][26];
int f[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;   f[0] = 1;

    reverse(all(S));

    for(int i = 1 ; i <= sz(S) ; ++i)   {
        for(int j = 0 ; j < 26 ; ++j)
            prv[i][j] = prv[i - 1][j];
        
        prv[i][S[i - 1] - 'a'] = i;

        for(int j = 0 ; j < 26 ; ++j)
            if (prv[i][j] == 0) {
                f[i] = 1;
                break;
            }
        if (f[i])   continue;

        f[i] = 1e9;

        for(int j = 0 ; j < 26 ; ++j)
            if (f[i] > f[prv[i][j] - 1] + 1)
                f[i] = f[prv[i][j] - 1] + 1;
    }
    string res = "";

    for(int i = sz(S) ;;)
    for(int j = 0 ; j < 26 ; ++j)   {
        if (prv[i][j] == 0) {
            res += (char)(j + 'a');

            cout << res;
            return  0;            
        }
        if (f[i] == f[prv[i][j] - 1] + 1)   {
            res += (char)(j + 'a');
            i = prv[i][j] - 1;
            break;
        }
    }
}