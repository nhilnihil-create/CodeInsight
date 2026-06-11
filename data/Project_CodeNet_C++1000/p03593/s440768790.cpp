#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm> // sort

#define DEBUG 0

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll mod = 1000000007;
static const ll INF = 1000000000000000000LL;
                    //999999997000000003
                    //1000000000000000000

using namespace std;

int main(){
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll H,W;
    cin >> H >> W;
    vector <string> a(H);
    REP(i,H)
    {
        cin >> a[i];
    }

    vector <int> alpha(26,0);
    REP(i,H)
    {
        REP(j,W)
        {
            ++alpha[a[i][j] - 'a'];
        }
    }

    //例えば5, 1なら (2,2,1 or 5)の構成で勝てる
    //これが2,5になると、4,4,2でないと勝てない。(4,4,6でも勝てる)
    //これが3,5になると、4,4,2,{5 or(2,2,1)}でも勝てるようになる
    //これが4,4になると、4,4,2でないと勝てない。

    //H,Wから、4を何組、2を何組、1を何組必要か求める
    //alphaをアッパーでソートして、あてがう

    int hitu4,hitu2,hitu1;
    //4で必要な数 2*2 -> 1 4 * 4 -> 4
    hitu4 = (H/2) * (W/2);
    hitu2 = (H*W - hitu4*4) / 2;
    hitu1 = (H*W) % 2;

    sort(alpha.rbegin(),alpha.rend());

    string res;

    int cnt = hitu4 + hitu2 + hitu1;
    int tar = 0;
    while(cnt > 0)
    {
        for(int i = 0; i < 26; ++i)
        {
            if(alpha[i] == 0)continue;
            if(alpha[i] >= 4 && hitu4 > 0)
            {
                --hitu4;
                --cnt;
                alpha[i] -= 4;
            }
            else if(alpha[i] >= 2 && hitu2 > 0)
            {
                --hitu2;
                --cnt;
                alpha[i] -= 2;
            }
            else if(alpha[i] >= 1)
            {
                --hitu1;
                --cnt;
                alpha[i] -= 1;
            }
        }
    }

    if(hitu4 == 0 && hitu2 == 0 && hitu1 == 0)
    {
        res = "Yes";
    }
    else res = "No";

    

    cout << res << endl;

    return 0;
}
