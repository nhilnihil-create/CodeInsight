#include<bits/stdc++.h>
using namespace std;
#define ll long long

int N, Q;
int L;
vector<int> x = {0};
int memo[20][100010];

void build(){
    for(int i = 1; i <= N + 1; i++){
        memo[0][i] = (upper_bound(x.begin(), x.end(), x[i] + L) - x.begin()) - 1;
    }

    for(int i = 0; i < 19; i++){
        for(int j = 1; j <= N + 1; j++){
            memo[i + 1][j] = memo[i][memo[i][j]];
        }
    }
}

int solve(int a, int b){
    int res = 0;
    for(int i = 0; i < 20; i++){
        if(memo[i][a] == b){
            res = 1 << i;
            break;
        }
        if(memo[i][a] > b){
            if(i != 0){
                res += 1 << (i - 1);
                res += solve(memo[i - 1][a], b);
            }else{
                res = 1;
            }
            break;
        }
    }
    return res;
}

int main(){
    cin >> N;
    x.resize(N + 1, 0);
    for(int i = 1; i <= N; i++){
        cin >> x[i];
    }
    x.push_back(x[N] + L);
    cin >> L;

    build();

    cin >> Q;
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        cout << solve(min(a, b), max(a, b)) << endl;
    }
    return 0;
}
