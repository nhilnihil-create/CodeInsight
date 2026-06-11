#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int count(vector<long long> &v){
    int cnt = 0;
    int N = v.size();
    while(true){
        long long mx = -1;
        for(int i=0; i<N; i++)
            mx = max(mx, v[i]);
        if(mx <= N-1) break;

        mx = -1;
        int j;
        for(int i=0; i<N; i++){
            if(v[i] > mx){
                mx = v[i];
                j = i;
            }
        }
        v[j] -= N+1;
        for(int i=0; i<N; i++) v[i]++;

        cnt++;
    }
    return cnt;
}

vector<long long> solve(int N, long long K){
    vector<long long> v(N);
    for(int i=0; i<N; i++) v[i] = i;
    long long M = K / N;
    for(int i=0; i<N; i++) v[i] += M;

    int R = K % N;
    for(int i=0; i<R; i++){
        bool flag = false;
        sort(v.begin(), v.end());

        for(int j=0; j<N; j++){
            vector<long long> tmp = v;
            tmp[j] += N+1;
            for(int k=0; k<N; k++) tmp[k]--;

            long long mx = 0;
            long long mn = 0;
            for(int k=0; k<N; k++){
                mx = max(mx, tmp[k]);
                mn = min(mn, tmp[k]);
            }
            if(mx == tmp[j] && mn >= 0){
                v = tmp;
                flag = true;
                break;
            }
        }
        if(!flag) return vector<long long>();
    }
    for(int i=0; i<N; i++)
        if(v[i] > 10000000000000000 + 1000) return vector<long long>();
    return v;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long K;
    cin >> K;

    vector<long long> ans;
    for(int N=2; N<=50; N++){
        ans = solve(N, K);
        if(!ans.empty()) break;
    }

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}