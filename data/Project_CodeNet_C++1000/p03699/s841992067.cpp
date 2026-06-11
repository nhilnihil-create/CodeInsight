#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long ;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(int N, vector<int> &s, int &ans){

    int sum{};
    for(auto iter = s.begin(); iter != s.end(); ++iter) sum += *iter;

    sort(s.begin(), s.end());

    bool flg_10mul = false;
    for(auto iter = s.begin(); iter != s.end(); ++iter){
        if(sum%10 != 0){
            flg_10mul = true;
            break;
        }
        else if((*iter)%10 != 0){
            sum -= *iter;
            flg_10mul = true;
            break;
        }
    }
    if(flg_10mul) ans = sum;

    return;
}

int main(){

    int N;
    cin >> N;
    vector<int> s(N);
    for(auto iter = s.begin(); iter != s.end(); ++iter) cin >> *iter;

    int ans{};
    solver(N, s, ans);

    cout << ans << endl;
    return 0;
}