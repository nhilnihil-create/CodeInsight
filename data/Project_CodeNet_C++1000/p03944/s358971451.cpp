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
    int N;
    int xy[5] = {0};
    int tempx,tempy,tempa;
    cin >> xy[2] >> xy[4] >> N;
    REP(i,N){
        cin >>tempx >> tempy >> tempa;
        if(tempa <= 2){
            if(tempa%2){
                //1
                xy[tempa] = max(xy[tempa],tempx);
            }else{
                //2
                xy[tempa] = min(xy[tempa],tempx);
            }
        }else{
            if(tempa % 2){
                xy[tempa] = max(xy[tempa],tempy);
            }else{
                xy[tempa] = min(xy[tempa],tempy);
            }
        }
    }
    //cout << xy[1] << xy[2] << xy[3] << xy[4] << endl;
    if(xy[2] - xy[1] <= 0 || xy[4]-xy[3] <= 0){
        fin(0);
    }else{
        fin((xy[2]-xy[1]) * (xy[4]-xy[3]));
    }
    return 0;
}