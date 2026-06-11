#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{

    string devide[4] = {"dream", "dreamer", "erase", "eraser"};
    string S;
    bool flag1,flag2;

    cin >> S;

    reverse(S.begin(),S.end());

    rep(i, 4)
        reverse(devide[i].begin(), devide[i].end());

    flag1 = true;

    for(int i = 0;i < S.size();){
        flag2 = false;
        rep(j,4){
            string s = devide[j];

            if(S.substr(i,s.size() ) == s){
                flag2 = true;
                i += s.size();
            }
        }
        if(flag2 == false){
            flag1 = false;
            break;
        }
    }

    if(flag1)
        cout << "YES" << endl;

    else
        cout << "NO" << endl;
    

    return 0;
}