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

#define REP(i, m, n) for(int i=int(m);i<int(n);i++)
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

//ここから編集する


int main() {
    int N,T;
    cin >> N >> T;
    vector<ll> A(N);
    vector<ll> B(N);

    REP(i,0,N){
        cin >> A[i];
    }
    ll min_b = A[0];
    B[1] = min_b;
    REP(i,2,N){
        min_b = min(min_b,A[i-1]);
        B[i] = min_b;
    }
    ll max_m =A[1] - B[1];
    int ans = 1;
    REP(i,2,N){
        if(A[i]-B[i] == max_m){
            ans++;
        }else if(A[i]-B[i] < max_m){
            continue;
        }else{
            ans = 1;
            max_m = A[i]-B[i];
        }
    }
    cout << ans << endl;
    return 0;
}
