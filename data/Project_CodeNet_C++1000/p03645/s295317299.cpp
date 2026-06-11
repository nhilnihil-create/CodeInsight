#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define test int t; cin>>t; while(t--)
vector<int>arr[200001];
int vis[200001],di[200001];
void bfs(int root)
{

    queue<int> que;


    que.push(root);


    di[root] = 0;


    vis[root] = 1;


    while (!que.empty()) {


       root = que.front();
       que.pop();
        for (int i = 0; i < arr[root].size(); i++) {

            int b = arr[root][i];

            if (!vis[b]) {


                que.push(b);


                di[b] = di[root] + 1;


                vis[b] = 1;
            }
        }
    }
}







int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);

    }
    bfs(1);
    if(di[n]>2 || di[n]==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else cout<<"POSSIBLE"<<endl;

}
