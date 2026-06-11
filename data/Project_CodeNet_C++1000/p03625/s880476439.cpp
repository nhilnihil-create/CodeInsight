#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a.at(i);
    // 同じ長さの組を探して最大の2つを取り出す
    sort(a.begin(), a.end(), greater<>());
    vi candidate;
    int64_t temp = 1;
    rep(i,n-1){
        if((a.at(i) != a.at(i+1))){
            if(temp>=4){
                candidate.push_back(a.at(i));
                candidate.push_back(a.at(i));
            }else if(temp<4 && temp>=2){
                candidate.push_back(a.at(i));
            }
            temp = 1;
            continue;
        }
        temp++;
        if(i == n-2){
            if(temp>=4){
                candidate.push_back(a.at(i));
                candidate.push_back(a.at(i));
            }else if(temp<4 && temp>=2){
                candidate.push_back(a.at(i));
            }
        }
    }
    if(candidate.size()>=2){
        cout << candidate.at(0) * candidate.at(1) << endl;
    }else{
        cout << 0 << endl;
    }
}