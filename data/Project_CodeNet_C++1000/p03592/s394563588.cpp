#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;



int main(){
    int n,m,k;
    cin >> n >> m >> k;

    //行のボタンを押すと
    //列のボタンを押すと
    //行を1個、列を1個使用すると、1*1個反転する
    //行を2個、列を1個使用すると、2*1個反転する
    //行を3個、列を3個使用すると、3*3個反転する
    string res = "No";
    //n行m列
    //行
    for(int i = 0; i <= n; ++i)
    {
        //列
        for(int j = 0; j <= m; ++j)
        {
            int tmp = m * i + n * j - i * j * 2;
            //cout << i << "," << j << ":" << tmp << endl;
            if(tmp == k)
            {
                res = "Yes";
            }
        }
    }
    cout << res << endl;



    return 0;
}
