#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;

using namespace std;
int n, dp[100500];

bool u[100500];

vector<int> a[100500];

int dfs(int v){
    //u[v] = 1;
    vector<int> pp;
    
    
    for(int i=0;i<a[v].size();i++){
        int to = a[v][i];
        pp.pb(dfs(to));
    }

    sort(pp.begin(), pp.end());
    reverse(pp.begin(), pp.end());

    int k = a[v].size();
    for(int i=0;i<pp.size();i++){
        k = max(k, pp[i] + i + 1);
    }
    return k;
}

int main(){

cin >> n;
for(int i=2;i<=n;i++){
    int x;
    cin >> x;
    a[x].pb(i);
}
cout << dfs(1);
return 0;
}
