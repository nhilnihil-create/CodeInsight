#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    vector<int> v;
    for(int i = 0; i < N; i++){
        v.push_back(a[i]);
        v.push_back(a[i]+1);
        v.push_back(a[i]-1);
    }

    map<int, int> mp;
    for(auto vv: v){
        mp[vv]++;
    }

    int MAX = -1;
    for(auto mmp:mp){
        MAX = max(MAX, mmp.second);
    }
    cout << MAX << endl;



    // int max_ans = -1;
    // for(int i = 0; i < 1e5 + 5; i++){
    //     int X = i;

    //     max_ans = max(ans, max_ans)
    // }



    // set<int> s;
    // for(int i = 0; i < N; i++){
    //     cin >> a[i];
    //     s.insert(a[i]);
    // }

    // int max_ans = -1;
    // for(auto ss: s){
    //     int ans = 0;
    //     for(int i = 0; i < N; i++){
    //         if(ss == a[i] || ss == (a[i]-1)  || ss == a[i]+1){
    //             ans++;
    //         }
    //     }
    //     max_ans = max(ans, max_ans);
    // }
    // cout << max_ans << endl;

    return 0;
}