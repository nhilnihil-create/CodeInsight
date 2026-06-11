#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 20)
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//ここから編集する
int dp[5001][5000];

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> a;
    int need = 0;
    rep(i,0,N){
        int tmp;
        cin >> tmp;
        if(tmp >= K){
            need++;
        }else{
            a.push_back(tmp);
        }
    }
    vector<int> rui;
    rui.push_back(0);
    sort(all(a));
    rep(i,0,a.size()-1){
        rui.push_back(*(rui.end()-1) + a[i]);
    }
    reverse(all(rui));

    reverse(all(a));

    dp[0][0] = 1;
    int ans = a.size();
    rep(i,0,a.size()){
        bool iscont = false;

        rep(j,0,5000){
            if(dp[i][j]){

                if(j+a[i] >= K){
                    iscont = true;
                }else{
                    dp[i+1][j+a[i]] = 1;
                }
                dp[i+1][j] = 1;
            }
        }
        rep(j,0,K){
            if(dp[i+1][j]){
                if(j+rui[i] >= K){
                    iscont = true;
                    break;
                }
            }
        }
        if(!iscont){
            break;
        }else{
            ans--;
        }
    }



    cout << ans << endl;
    return 0;
}
