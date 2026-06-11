#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>());
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(auto s : v[n-1]){
        for(auto t : v[s]){
            if(t == 0){
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
