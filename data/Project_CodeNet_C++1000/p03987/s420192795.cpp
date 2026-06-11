#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<pair<unsigned long, unsigned long>> stk;
    unsigned long ans{0}, now{0};
    const auto& pop = [&stk, &now](){
        now -= stk.back().first * stk.back().second;
        stk.pop_back();
    };
    const auto& push = [&stk, &now, &pop](unsigned long x){
        pair<unsigned long, unsigned long> tmp{x, 1};
        while(!stk.empty() && stk.back().first > x){
            tmp.second += stk.back().second;
            pop();
        }
        now += tmp.first * tmp.second;
        stk.push_back(move(tmp));
    };
    for(unsigned long i{0}, a; i < N; ++i){
        cin >> a;
        push(a);
        ans += now;
    }
    cout << ans << endl;
    return 0;
}