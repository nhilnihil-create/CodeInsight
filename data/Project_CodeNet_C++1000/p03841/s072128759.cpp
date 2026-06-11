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
struct BIT{
    vector<int> bit;
    int n;
    BIT(int n){
        bit.resize(n+1,0);
        this->n = n;
    }
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i,int x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

int main() {
    int N;
    cin >> N;
    BIT bit(N*N);
    vector<pair<int,int> > x;

    rep(i,1,N+1){
        int tmp;
        cin >> tmp;
        x.emplace_back(tmp,i);
    }
    sort(all(x));
    vector<int> v(N*N+1,0),out;
    rep(i,0,x.size()){
        v[x[i].first] = x[i].second;
    }
    out = v;
    int l = 1,r = N*N;
    rep(i,0,x.size()){
        rep(j,0,x[i].second-1){
            if(l >= x[i].first){
                cout << "No" << endl;
                return 0;
            }else if(out[l] == 0){
                out[l] = x[i].second;
            }else{
                l++;
                j--;
                continue;
            }
        }
    }

    for(int i = x.size() - 1; i >= 0; i--){
        rep(j,0,N - x[i].second){
            if(r <= x[i].first){
                cout << "No" << endl;
                return 0;
            }else if(out[r] == 0){
                out[r] = x[i].second;
            }else{
                r--;
                j--;
                continue;
            }
        }
    }

    cout << "Yes" << endl;
    rep(i,1,out.size()){
        cout << out[i];
        if(i == out.size() - 1){
            cout << endl;
        }else{
            cout << " ";
        }
    }

    return 0;
}
