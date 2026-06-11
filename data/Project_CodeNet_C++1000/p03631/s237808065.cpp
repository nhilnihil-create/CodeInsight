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
    bool ans = true;
    REP(i,S.length()){
        if(S[i] == S[S.length()-1-i])continue;
        else{ans = false; break;}
    }
    if(!ans) fin("No");
    else fin("Yes");
    return 0;
}