#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> edges[2000];
int a[2000];
int b[2000];

int d[2000];

void bfs_init(int N){
    for(int i = 0; i < N; i++){
        d[i] = -1;
    }
    return;
}

void bfs(int start){
    queue <int> q;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < edges[cur].size(); i++){
            int next = edges[cur][i];
            if(d[next] < 0){
                d[next] = d[cur] + 1;
                q.push(next);
            }
        }
    }
    return;
}

int main(void){
    // Your code here!
    int N;
    int K;
    cin >> N;
    cin >> K;
    for(int i = 0; i < N - 1; i++){
        cin >> a[i] >> b[i];
        edges[a[i] - 1].push_back(b[i] - 1);
        edges[b[i] - 1].push_back(a[i] - 1);
    }
    
    int ans = 0;
    if(K % 2 == 0){
        for(int i = 0; i < N; i++){
            int tmp_ans = 0;
            bfs_init(N);
            d[i] = 0;
            bfs(i);
            for(int i = 0; i < N; i++){
                if(d[i] <= K / 2){
                    tmp_ans ++;
                }
            }
            ans = max(ans, tmp_ans);
        }
    } else {
        for(int i = 0; i < N - 1; i++){
            int tmp_ans = 0;
            bfs_init(N);
            d[a[i] - 1] = 0;
            d[b[i] - 1] = 0;
            bfs(a[i] - 1);
            bfs(b[i] - 1);
            for(int i = 0; i < N; i++){
                if(d[i] <= K / 2){
                    tmp_ans ++;
                }
            }
            ans = max(ans, tmp_ans);
        }
    }
    cout << N - ans << endl;
    return 0;
}