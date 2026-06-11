#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N, M;
int A[100010];
int B[100010];
vector<int> G[100010];
bool used[100010];

void rec(int pos, int par, vector<int> &v){
    used[pos] = true;
    v.push_back(pos);
    for(int to : G[pos]){
        if(used[to]) continue;
        if(to == par) continue;
        rec(to, pos, v);
        break;
    }
}

int main(){

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    vector<int> v1, v2;
    // back
    {
        rec(0, -1, v1);
    }
    // front
    {
        used[0] = false;
        rec(0, -1, v2);
    }

    reverse(v1.begin(), v1.end());
    
    vector<int> ans = v1;
    for(int a : v2){
        if(a == 0) continue;
        ans.push_back(a);
    }
    
    cout << ans.size() << endl;
    for(int a : ans){
        cout << a + 1 << " ";
    }
    cout << endl;

    return 0;
}
