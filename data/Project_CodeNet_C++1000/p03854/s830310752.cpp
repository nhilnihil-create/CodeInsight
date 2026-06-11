#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}

const int MAX = 510000;
const int MOD = 1000000007;

int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

bool sjudge(string &s, int b,int n){
    if (n == 5)
    {
        return (s.substr(b,5) == "dream" || s.substr(b,5) == "erase") ;
    }
    if (n == 6)
    {
        return (s.substr(b,6) == "eraser") ;
    }
    if (n == 7)
    {
        return (s.substr(b,7) == "dreamer") ;
    }
    
    
    /*
    bool go = (s.substr(b,5) == "dream" || s.substr(b,5) == "erase") ;
    bool ro = (s.substr(b,6) == "eraser") ;
    bool na = (s.substr(b,7) == "dreamer") ;
    return go||ro||na ;
    */
}

bool judge(string &s, int a, vector<bool> &table){
    bool ans ;
    if (a > 4)
    {
        ans = table.at(a-5) && sjudge(s,a-5,5) ;
    }
    if (a > 5)
    {
        ans = ans || (table.at(a-6) && sjudge(s,a-6,6)) ;
    }
    if (a > 6)
    {
        ans = ans || (table.at(a-7) && sjudge(s,a-7,7)) ;
    }
    
    return ans ;
}



int main(){
    string s ;
    cin >> s ;
    vector<bool> table(s.size()+1,0);
    table.at(0) = 1 ;
    for (size_t i = 5; i < s.size() + 1; i++)
    {
        table.at(i) = judge(s,i,table) ;
    }
    if (table.at(s.size()) == 1)
    {
        cout << "YES" ;
    }else
    {
        cout << "NO" ;
    }
    cout << endl ;
    
}