#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)
#define P pair<int,int>

int main(void){
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> v(n);
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    
    for(int i = 0;i < n;i++){
        cout << v[i].size() << endl;
    }
}