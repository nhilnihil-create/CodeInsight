#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    vector<long long> cnt(N + 1);
    map<long long, long long> m;
    int MAX = 0, ind = 0;
    vector<P> vec;
    vec.push_back(P(0, -1));
    for(int i = 0; i < N; i++){
        if(MAX < a[i]){
            MAX = a[i];
            ind = i;
            vec.push_back(P(a[i], i));
        }
    }
    reverse(vec.begin(), vec.end());
    int n = vec.size();
    int right = N;
    for(int i = 0; i < n - 1; i++){
        P v = vec[i];
        int now = v.second;
        for(int i = now; i < right; i++){
            m[a[i]]++;
        }
        long long nex = vec[i + 1].first;
        vector<P> temp;
        for(auto ite = m.rbegin(); ite != m.rend(); ite++){
            auto u = *ite;
            if(u.first <= nex) break;
            cnt[now] += (u.first - nex) * u.second;
            temp.push_back(u);
        }
        for(P u: temp){
            m[nex] += u.second;
            m.erase(u.first);
        }
        right = now;
    }
    for(int i = 0; i < N; i++){
        cout << cnt[i] << endl;
    }
}