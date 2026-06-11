#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2

using namespace std;
int MOD = 1000000007;

signed main(){
    int n;
    cin >> n;
    
    int a[100001];
    int s = 0;
    rep(i,n){
        cin >> a[i];
        s += a[i];
    }
    if(s%(n*(n+1)/2) != 0){
        cout << "NO" << endl;
        return 0;
    }
    int x = s/(n*(n+1)/2);
    int sum_sa = 0;
    for(int i = 0;i < n;i++){
        int sa = a[(i+1)%n] - a[i];
        sum_sa += sa;
        if((x-sa)%n == 0 && (x-sa)/n >= 0 && (x-sa)/n <= x){

        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    if(sum_sa != 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;



    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://arc060.contest.atcoder.jp/tasks/arc060_a