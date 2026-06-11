#include<bits/stdc++.h>
using namespace std;
int gr[100009];
int f[100009];
vector<int> v[100009];
void dfs(int x){
    f[x] = 1;
    for(auto i : v[x]){
        if(f[i]) continue;
        dfs(i);
        gr[x] ^= gr[i];

    }
    if(x > 1) gr[x] ++;
}
main(){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >>x>> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    if(gr[1] == 0) cout << "Bob"<< endl;
    else cout << "Alice"<<endl;
}
