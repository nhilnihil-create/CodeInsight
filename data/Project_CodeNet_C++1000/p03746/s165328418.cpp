//code by lynmisakura.wish to be accepted!
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
vector<int> g[100010];
int used[100010];

vector<int> p_a;
void dfs_1(int x){
    used[x]++;
    p_a.push_back(x);
    for(int i : g[x]){
        // bool check = true;
        if(!used[i]){
            // check = false;
//            cout << i << " " << x << endl;
            dfs_1(i);
            break;
        }
    }
    return;
}
vector<int> p_b;
void dfs_2(int x){
    used[x]++;
    p_b.push_back(x);
    for(int i : g[x]){
        // bool check = true;
        if(!used[i]){
            // check = false;
            dfs_2(i);
            break;
        }
    }
    return;
}

int main(void){
    scanf("%d %d",&n,&m);
    int s,t;
    for (int i = 0; i < m; ++i)
    {
        int a,b;scanf("%d %d",&a,&b);a--,b--;
        if(!i)s=a,t=b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
//    for(auto i : g[1])cout << i << " ";cout << endl;
    used[s]++,used[t]++;
    dfs_1(s);
    dfs_2(t);
    cout << p_a.size() + p_b.size() << endl;
    reverse(p_a.begin(),p_a.end());
    for(auto i : p_a)cout << i+1 << " ";
    for(auto i : p_b)cout << i+1 << " ";
    cout << endl;
}