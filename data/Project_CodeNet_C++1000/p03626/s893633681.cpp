#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

int main(){
    ll N;
    cin >> N;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    //X:縦, Y:横
    string s = "";
    for(int i = 0; i < N; ++i)
    {
        if(i == N-1)s+= "X";
        else
        {
            if(s1[i] == s1[i+1])
            {
                s += "Y";
                ++i;
            }
            else 
            {
                s += "X";
            }
        }
    }

    ll res = 1;
    //最初の1個
    if(s[0] == 'X')
    {
        res *= 3;
    }
    else
    {
        res *= 6;
    }
    for(int i = 0; i < s.size() - 1; ++i)
    {
        if(s[i] == 'X' && s[i+1] == 'X')
        {
            res *= 2;
        }
        else if(s[i] == 'X' && s[i+1] == 'Y')
        {
            res *= 2;

        }
        else if(s[i] == 'Y' && s[i+1] == 'X')
        {
            res *= 1;

        }
        else//YY
        {
            res *= 3;
        }
        res %= MOD;
    }

    cout << res << endl;




    return 0;

}
