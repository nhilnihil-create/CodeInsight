#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<int,int> p;

int N, M; 
vector<vector<int>> A(310, vector<int>(310));

p max_participant(set<int> sports){
    vector<int> cnt(M,0); // 各競技の参加人数
    rep(i,N) rep(j,M){
        if(sports.find(A[i][j]) != sports.end()){
            cnt[A[i][j]]++; break;
        }
    }

    int max_id = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    int max_p = cnt[max_id];
    return p(max_id, max_p);
}

int solve(set<int> sports){
    if(sports.empty()) return 1e8;

    p now = max_participant(sports);
    int max_id_now = now.first, max_p_now = now.second;
    //cout << max_id_now << " " << max_p_now << endl;

    sports.erase(max_id_now);
    p next = max_participant(sports);
    int max_id_next = next.first, max_p_next = next.second;

    return min(max_p_now, solve(sports));
}

int main(){
    cin >> N >> M;
    
    rep(i,N)rep(j,M){
        cin >> A[i][j]; A[i][j]--;
    }

    set<int> sports; // 開催する競技の集合
    rep(i,M) sports.insert(i);

    int ans = solve(sports);
    cout << ans << endl;
}
