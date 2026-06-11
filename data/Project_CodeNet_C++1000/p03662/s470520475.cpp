#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
int inf=100000000;
ll INF=100000000000000000;
ll MOD=1000000007;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> e(n,vector<int>(0));
    int y,u;
    rep(i,n-1){
        cin >> y >> u;
        e.at(y-1).push_back(u-1);
        e.at(u-1).push_back(y-1);
    }
    vector<int> b(n);
    rep(i,n) b.at(i)=0;
    b.at(0)=1;
    b.at(n-1)=1;
    queue<pp> q;
    pp v;
    int fe=0,nu=0;
    v.first=0;v.second=0;
    q.push(v);
    v.first=n-1;v.second=1;
    q.push(v);
    while(!q.empty()){
        int o=q.front().first,l=q.front().second;
        q.pop();
        for (int i=0;i<e.at(o).size();i++){
            if (b.at(e.at(o).at(i))==0){
                b.at(e.at(o).at(i))=1;
                if (l==0) fe++;
                if (l==1) nu++;
                v.first=e.at(o).at(i);
                v.second=l;
                q.push(v);
            }
        }
    }
    if (fe>nu) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}
