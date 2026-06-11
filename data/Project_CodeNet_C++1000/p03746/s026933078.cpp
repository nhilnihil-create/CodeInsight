#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N, M, A, B;
    cin >> N >> M;
    vector<int> edge[N+1];
    rep(i, M){
        cin >> A >> B;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }
    bool used[N+1];
    fill_n(used, N+1, false);
    int L = 1, R = edge[L][0];
    used[L] = true, used[R] = true;
    vector<int> vecl, vecr;
    vecl.push_back(L);
    vecr.push_back(R);
    int i = 0;
    while(true){
        int l = vecl[i];
        int p = 0;
        rep(k, edge[l].size()){
            if(!used[edge[l][k]]){
                p = edge[l][k];
                break;
            }
        }
        if(p){
            vecl.push_back(p);
            used[p] = true;
            i++;
        }
        else break;
    }
    int j = 0;
    while(true){
        int r = vecr[j];
        int p = 0;
        rep(k, edge[r].size()){
            if(!used[edge[r][k]]){
                p = edge[r][k];
                break;
            }
        }
        if(p){
            vecr.push_back(p);
            used[p] = true;
            j++;
        }
        else break;
    }
    cout << vecl.size() + vecr.size() << endl;
    for(int i = vecl.size()-1; i >= 0; i--){
        cout << vecl[i] << ' ';
    }
    rep(i, vecr.size()){
        cout << vecr[i] << ' ';
    }
}