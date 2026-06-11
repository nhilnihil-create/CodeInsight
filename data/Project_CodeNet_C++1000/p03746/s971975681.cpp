#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll qo(bool q){ return (q ? 0 : qo(q)); }

const int mnx = 1e6 + 9;
const int mod = 1e9 + 7;

int n, m;
int a[mnx], b[mnx];
vector<int> e[mnx];
vector<int> ans1, ans2;
bool used[mnx];

int ok(int x){
    for(int i = 0; i < e[x].size(); i++){
        if(!used[e[x][i]]) return e[x][i];
    }
    return -1;
}
 
int main(){
 
cin >> n >> m;

for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    e[a[i]].push_back(b[i]);
    e[b[i]].push_back(a[i]);
}
 
int x = a[0],y = b[0];
queue<int> q;
q.push(x);
used[x] = 1;
used[y] = 1;
ans1.push_back(x);

while(!q.empty()){
    x=q.front();
    q.pop();
    if(ok(x)==-1) break;
    q.push(ok(x));
    ans1.push_back(ok(x));
    used[ok(x)]=1;
}

queue<int> q2;
q2.push(y);
ans2.push_back(y);

while(!q2.empty()){
    y = q2.front();
    q2.pop();
    if(ok(y) == -1) break;
    q2.push(ok(y));
    ans2.push_back(ok(y));
    used[ok(y)] = 1;
}

cout << ans2.size() + ans1.size() << endl;

for(int i = ans2.size() - 1;i >= 0; i--){
    cout << ans2[i] << " ";
}

for(int i = 0; i < ans1.size(); i++){
    cout << ans1[i] << " ";
}

qo(true);

}