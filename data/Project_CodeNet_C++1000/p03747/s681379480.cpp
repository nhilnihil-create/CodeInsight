#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <stack>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;
constexpr uint64_t L1 = 1ull;
constexpr ull bit(int n){ return 1ull << n;}

// for(auto && i : Range(l,r))
// -> i = [l..r)
class Range {
private: struct It{ int x; int operator*(){return x;}
 bool operator!=(It& lhs){ return x<lhs.x;} void operator++(){++x;} }; It l,r;
public: Range(int n):l({0}),r({n}){} Range(int i,int n):l({i}),r({n})
 {}It& begin(){return l;} It& end(){return r;} };

void solve(istream& cin) {
    ll N, L, T;
    while(cin >> N >> L >> T){
        vector<ll> V, W;
        for (int i = 0; i < N; ++i) {
            int tmp;
            cin >> tmp;
            V.push_back(tmp);
            cin >> tmp;
            W.push_back(tmp == 1 ? 1 : -1);
        }
        ll col_n = 0;
        for (int i = 1; i < N; ++i) {
            if(W[0] != W[i]){
                ll tcol = -W[0] * V[0] - W[i] * V[i];
                tcol = (tcol + L) % L;
                if (tcol < 2*T){
                    ll tm = 2*T - tcol-1;
                    tcol = 1 + tm / L;
                }
                else tcol = 0;
                col_n += tcol;
            }
        }
        ll num0 = (W[0] * col_n);
        num0 = (num0 + 1000000ll*N) % N;
        ll ls0 = (V[0] + W[0] * T + 10000000*L) % L;
        vector<ll> last;
        last.push_back(ls0);
        for (int i = 1; i < V.size(); ++i) {
            last.push_back((V[i] + W[i] * T + 10000000*L) % L);
//            cerr << "last[" << i << "] :" << last.back() << endl;
        }
        sort(last.begin(), last.end());
        vector<ll> ans(N);
        auto pos0l = lower_bound(last.begin(), last.end(), ls0);
        auto pos0u = upper_bound(last.begin(), last.end(), ls0);
        if(pos0u - pos0l == 2){
            if(W[0] == -1){
                num0--;
            }
        }
        for (int i = 0; i < N; ++i) {
            ans[(i+num0) % N] = *pos0l;
            pos0l++;
            if(pos0l == last.end()) pos0l = last.begin();
        }
        for (int i = 0; i < N; ++i) {
            cout << ans.at(i) << '\n';
        }
    }
}

int main(int argc, char *argv[]) {
    string FileName("AGC013C"), Modifier("MEPH_");
    string ExecutionName = Modifier + FileName;
    string sub(argv[0]);
    if(sub.size() > ExecutionName.size())
        sub = sub.substr(sub.size()-ExecutionName.size(), ExecutionName.size());
    cerr << sub << endl;
    if (sub != ExecutionName) {
        cin.tie(0);
        ios::sync_with_stdio(false);
        solve(cin);
    }
    else {
        string inFile = "sample.txt";
        auto fs = fstream(inFile, fstream::in);
        solve(fs);
    }
}