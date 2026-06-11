#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
struct edge{int from;int to;ll cost;};
int main(){
    int n,m;cin >> n >> m;
    vector<vector<int>> g(n);
    vector<edge> h(m);
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        ll c;cin >> c;
        a--,b--;
        g[b].push_back(a);
        h[i]=edge{a,b,-c};
    }
    vector<bool> f(n);
    stack<int> st;
    st.push(n-1);
    f[n-1]=true;
    while(!st.empty()){
        int p=st.top();
        st.pop();
        for(auto x:g[p]){
            if(!f[x]){
                st.push(x);
                f[x]=true;
            }
        }
    }
    vector<ll> d(n,INF);
    d[0]=0;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<m;j++){
            int fr=h[j].from,to=h[j].to;
            ll co=h[j].cost;
            if(d[fr]!=INF&&d[to]>d[fr]+co){
                d[to]=d[fr]+co;
                if(i>=n-1&&f[to]){
                    cout << "inf" << endl;
                    return 0;
                }
            }
        }
    }
    cout << -d[n-1] << endl;
}
