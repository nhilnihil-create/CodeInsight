#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <iomanip>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(long long int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){
    long long int n, k;
    cin >> n >> k;
    vector<long long int> v(n),w(n);
    REP(i,n){
        cin >> v[i];
    }
    long long int max_high,tmp_price, result = linf,mieru_num;
    REP(i,1<<n){
        copy(v.begin(), v.end(), w.begin());
        tmp_price = 0;
        max_high = w[0];
        mieru_num = 1;
        FOR(j,1,n){
            if(i&(1<<j)){
                if(w[j]<=max_high){
                    tmp_price += max_high + 1 - w[j];
                    w[j] = max_high + 1;
                }
                
            }
            if(max_high<w[j]){
                max_high = w[j];
                mieru_num++;
            }
        }
        if(mieru_num>=k){
            result = min(result, tmp_price);
        }
    }
    cout << result << endl;
}