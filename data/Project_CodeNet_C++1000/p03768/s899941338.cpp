#include <iostream>
#include <vector>
using namespace std;
struct query{
    int v, d, c;
    query(int v, int d, int c) : v(v), d(d), c(c){}
};
vector< vector<int> > edg, clr;
void paint(int v, int d, int c){
    if(clr[v][d] > 0) return;
    for(int i=d;i>=0;i--){
        if(clr[v][i] > 0) break;
        clr[v][i] = c;
    }
    if(d <= 0) return;
    for(int i=0;i<edg[v].size();i++){
        paint(edg[v][i], d-1, c);
    }
}
int main(void){
    int n, m, q;
    vector<query> que;
    cin >> n >> m;
    edg.assign(n, vector<int>());
    clr.assign(n, vector<int>());

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int v, d, c;
        cin >> v >> d >> c;
        que.push_back(query(--v, d, c));
    }
    for(int i=0;i<n;i++){
        clr[i].assign(11, 0);
    }
    for(int i=q-1;i>=0;i--){
        paint(que[i].v, que[i].d, que[i].c);
    }
    for(int i=0;i<n;i++){
        cout << clr[i][0] << endl;
    }
}
