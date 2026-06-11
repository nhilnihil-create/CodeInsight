#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    long c[n];
    vector<set<pair<int,long> > >tree(n+1);
    for(int i=0;i<n-1;i++){
        cin >> a[i]>>b[i]>>c[i];
        tree[a[i]].insert(make_pair(b[i],c[i]));
        tree[b[i]].insert(make_pair(a[i],c[i]));
    }
    int q,k;
    cin >> q >> k;
    vector<long>distance(n+1,-1);
    distance[k]=0;
    queue<int>que;
    que.push(k);
    
    long ans[q];
    int x[q];
    int y[q];
    for(int i=0;i<q;i++){
        cin >> x[i] >> y[i];
       
    }

    while(!que.empty()){
        int cur = que.front();
        que.pop();
        // cout << cur<<endl;
        for(auto j:tree[cur]){
            if(distance[j.first] == -1){
                que.push(j.first);
                distance[j.first] = distance[cur] + j.second;
                // cout << j.first<<endl;
            }
        }
    }

    for(int i=0;i<q;i++){
         ans[i] = distance[x[i]] + distance[y[i]];
    }
    for(int i=0;i<q;i++)cout<<ans[i]<<endl;
}