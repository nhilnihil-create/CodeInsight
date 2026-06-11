#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(lint i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(lint i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())

const int IINF = 1e9 + 10;
const lint LLINF = (lint)1e18 + 10;
const lint MOD = (lint)1e9 + 7;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

lint n;

bool check(lint x){
    if(x * (x + 1) / 2 >= n){
        return true;
    }else{
        return false;
    }
}

pair<lint, lint> meguruSearch(lint ok, lint ng){
    lint mid;
    pair<lint, lint> res = make_pair(ok, 0);
    while(abs(ok - ng) > 1){
        mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
            res.first = mid;
            res.second = (mid * (mid + 1) / 2) - n;
        }else{
            ng = mid;
        }
    }
    return res;
}

int main(){
    cin >> n;
    pair<lint, lint> ans = meguruSearch(n+1, 0);
    REP(i, 1, ans.first + 1){
        if(i == ans.second){
            continue;
        }
        cout << i << endl;
    }
    return 0;
}