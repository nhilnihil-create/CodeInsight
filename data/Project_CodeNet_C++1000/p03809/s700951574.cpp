#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int N;
vector<int> A;
vector<vector<int>> G;
vector<int> B;
vector<bool> isVisited;

int maxpair(vector<int> &v){
    if(v.size() <= 1) return 0;

    sort(v.begin(), v.end());

    int sm = 0;
    for(int i=0; i<v.size()-1; i++) sm+=v[i];
    int mx = v.back();
    if(sm >= mx) return (sm+mx)/2;
    else return sm;
}

int dfs(int s){
    isVisited[s] = true;

    int cnt = 0;
    int num = 0;
    vector<int> v;
    for(int t : G[s]){
        if(isVisited[t]) continue;
        num++;
        B[t] = dfs(t);
        cnt += B[t];
        v.push_back(B[t]);
    }
    if(num==0) return A[s];
    int a=2*A[s]-cnt, b=cnt-A[s];
    int maxb = maxpair(v);
    if(a < 0 || b < 0 || b > maxb) return -1;
    return a;
    /*
    a: child -> parent
    b: child -> child
    cnt: from children
    a+2*b=cnt
    A=a+b
    ->a+2*(A-a)=cnt
    ->-a+2A=cnt
    ->a=2A-cnt
    ->b=A-a=cnt-A
     */
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    A.resize(N);
    G.resize(N);
    B.resize(N, 0);
    isVisited.resize(N, false);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    if(N==2){
        if(A[0] == A[1]){
            cout << "YES" << endl;
            return 0;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    int s = 0;
    for(int i=0; i<N; i++){
        if(G[i].size() >= 2){
            s = i;
            break;
        }
    }

    B[s] = dfs(s);

    if(B[s] != 0){
        cout << "NO" << endl;
        return 0;
    }
    for(int i=1; i<N; i++){
        if(B[i] == -1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
