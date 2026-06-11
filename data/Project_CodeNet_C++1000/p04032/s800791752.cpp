#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'
/*

*/
int main()
{
    string S;
    cin >> S;
    int l = S.length();
    int st = -1,ed = -1;
    //DPクソもないけどoxoみたいな構造を探してやればいいらしい。そりゃそうだ
    if(l == 2){
        if(S[0] == S[1]){
            cout << "1 2" << endl;
        }else{
            cout << "-1 -1" << endl;
        }
        return 0;
    }
    REP(i,l-2){
        //cout << S[i] << S[i + 1] << S[i + 2] << endl;
        if (S[i] == S[i + 1] || S[i] == S[i + 2] || S[i + 1] == S[i + 2])
        {
            st = i+1;
            ed = i+3;
            break;
        }
    }
    cout << st << " " << ed << endl;
    return 0;
}