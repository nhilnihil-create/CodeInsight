#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

vector<vector<int> > v(100000);
bool maki[100000];
deque<int> ans;

void dfs1(int n){
    int s=v[n].size();
    for(int i=0;i<s;i++){
        if(!maki[v[n][i]]){
            ans.push_front(v[n][i]);
            maki[v[n][i]]=1;
            dfs1(v[n][i]);
            return;
        }
    }
    return;
}
void dfs2(int n){
    int s=v[n].size();
    for(int i=0;i<s;i++){
        if(maki[v[n][i]])continue;
        else{
            ans.pb(v[n][i]);
            maki[v[n][i]]=1;
            dfs2(v[n][i]);
            return;
        }
    }
    return;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    int niko;
    memset(maki,0,sizeof(maki));
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
        if(a==0)niko=b;
    }

    ans.pb(0);
    ans.pb(niko);
    maki[0]=maki[niko]=1;
    dfs1(0);
    dfs2(niko);
    cout << ans.size() <<endl;
    while(!ans.empty()){
        cout << (ans.front())+1 <<" ";
        ans.pop_front();
    }
    cout <<endl;
    return 0;
}
