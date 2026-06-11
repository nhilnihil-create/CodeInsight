#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];

int main(){
        int n;
        cin >> n;

        int a, b;
        for(int i = 0;i < n-1;i++){
                cin >> a >> b;
                a--; b--;
                graph[a].push_back(b);
                graph[b].push_back(a);
        }


        queue<pair<int, int> > que;
        que.push(make_pair(0, 1));
        que.push(make_pair(n-1, 2));

        int dist[100010] = {};

        while(!que.empty()){
                int idx = que.front().first;
                int num = que.front().second;
                que.pop();

                if(dist[idx] != 0) continue;

                dist[idx] = num;

                for(int i = 0;i < graph[idx].size();i++){
                        que.push(make_pair(graph[idx][i], num+2));
                }
        }

        int f = 0;
        int s = 0;
        for(int i = 0;i < n;i++){
                if(dist[i] % 2 == 1){
                        f++;
                }else{
                        s++;
                }
        }

        if(f > s){
                cout << "Fennec" << endl;
        }else{
                cout << "Snuke" << endl;
        }

        return 0;
}

