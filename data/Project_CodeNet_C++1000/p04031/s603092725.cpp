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
    double average_d;
    int average_i=0;
    cin >> N;
    int num[N];
    REP(i, N){
        cin >> num[i];
        average_i += num[i];
    }
    average_d = (double)average_i / N;
    average_i /= N;

    //四捨五入する
    if(average_d*10-average_i*10 > 5){
        average_i++;
    }
    int ans = 0;
    REP(i,N){
        ans += (num[i] - average_i) * (num[i] - average_i);
    }
    fin(ans);
    return 0;
}