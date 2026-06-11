#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const int MOD = 1000000007;
using namespace std;


int main(){
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    string ar = "";
    REP(i, n){
        if(s1[i] == s2[i]) ar += 'p';
        else{
            ar += 't'; ++i;
        }
    }
    ll cnt = 1;
    int prv = 0; //1ならp(縦) 2ならt(横)
    REP(i, ar.length()){
         if(!prv){
             if(ar[i] == 'p'){
                 cnt = 3; prv = 1;
             }else{
                 cnt = 6; prv = 2;
             }
         }
         else if(prv == 1){
             if(ar[i] == 'p'){
                cnt = cnt * 2 % MOD; prv = 1;
             }else{
                cnt = cnt * 2 % MOD; prv = 2;
             }
         }else{
             if(ar[i] == 'p'){
                 prv = 1;
             }else{
                 cnt = cnt * 3 % MOD; prv = 2;
             }
         }
    }
    cout << cnt << "\n";
    return 0;
}