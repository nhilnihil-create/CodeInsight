#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MAX = 100000;
vector<int> edges[MAX];
int color[MAX];

bool check_bipart(int i, int prev, int c){
    color[i] = c;
    bool ret = true;
    for(auto j : edges[i]){
        if(j == prev) continue;
        if(color[j] == 0){
            ret &= check_bipart(j, i, -c);
        }else{
            ret &= (c != color[j]);
        }
    }
    return ret;
}

int main(){
    int i, j, k;
    cin >> N >> M;
    for(i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    long long I=0, P=0, Q=0;
    for(i=0; i<N; i++){
        if(color[i] != 0) continue;
        if(edges[i].size()==0){
            I++;
        }else if(check_bipart(i, -1, 1)){
            Q++;
        }else{
            P++;
        }
    }
    long long ans = I*I + 2*I*(N-I) + P*P + 2*P*Q + 2*Q*Q;
    cout << ans << endl;
    return 0;
}