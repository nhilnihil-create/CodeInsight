#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
int A[101010];
LL ans[101010];
LL T[101010];
vector<int> V, id;

void update(int t){
    while (t <= N){
        T[t]++;
        t += t & -t;
    }
}

LL read(int t){
    LL ret=0;
    while (t){
        ret += T[t];
        t -= t & -t;
    }
    return ret;
}

int main(){
    scanf("%d", &N);
    V.push_back(0);
    id.push_back(0);
    for (int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        if (V.back() >= A[i]){
            int k = upper_bound(V.begin(), V.end(), A[i]) - V.begin();
            if (k > 1) update(k-1);
            if (k < V.size()) ans[id[k]] += A[i] - V[k-1];
        }
        else{
            if (!V.empty()) update(V.size());
            V.push_back(A[i]);
            id.push_back(i);
        }
    }
    for (int i=1; i<(int)V.size(); i++) ans[id[i]] += (read(N) - read(i-1)) * (V[i] - V[i-1]);
    for (int i=1; i<=N; i++) printf("%lld\n", ans[i]);
    return 0;
}
