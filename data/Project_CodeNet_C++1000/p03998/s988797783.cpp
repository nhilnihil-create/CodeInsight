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
    string SA,SB,SC;
    cin >> SA >> SB >> SC;
    int a=1,b=0,c=0;
    char next;
    next = SA[0];
    while(true){
        //cout << next;
        if (SA.length() < a)
        {
            fin("A");return 0;
        }
        else if (SB.length() < b)
        {
            fin("B");return 0;
        }
        else if (SC.length() < c)
        {
            fin("C");return 0;
        }
        if(next == 'a'){
            next = SA[a]; a++;
        }else if(next == 'b'){
            next = SB[b]; b++;
        }else{
            next = SC[c]; c++;
        }
    }
    return 0;
}