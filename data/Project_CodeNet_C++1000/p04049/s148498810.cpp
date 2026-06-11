#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N, K;
vector<int> G[2010];
pii es[2010];

int rec(int pos, int prv, int dist){
    int sum = 0;
    if(dist > K / 2) sum++;
    for(int to : G[pos]){
        if(to == prv) continue;
        sum += rec(to, pos, dist + 1);
    }
    return sum;
}

int main(){

    cin >> N >> K;
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        es[i] = pii(a, b);
    }

    int ans = 1 << 29;
    if(K % 2){
        for(int i = 0; i < N - 1; i++){
            int a = es[i].first;
            int b = es[i].second;
            ans = min(ans, rec(a, b, 0) + rec(b, a, 0));
        }
    }
    else{
        for(int i = 0; i < N; i++){
            ans = min(ans, rec(i, -1, 0));
        }
    }

    cout << ans << endl;

    return 0;
}
