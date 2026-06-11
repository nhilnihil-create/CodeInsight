#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main(){
    int n,m;
    cin >> n >> m;
    struct edge{int from,to,cost;};
    vector<edge> v;
    rep(i,m){
        int aa,bb,cc;
        cin >> aa >> bb >> cc;
        edge e= {aa-1,bb-1,cc};
        v.push_back(e);
    }

    int d[n];
    for(int i=0;i<n;i++) d[i]=-100000000000000000;
    d[0]=0;
    int count=0;
    bool z=false;
    bool f=false;
    while(true){
        bool update = false;
        for(int i=0;i<v.size();i++){
            edge e = v[i];
            
            if(d[e.from]!=-100000000000000000 && d[e.to] < d[e.from]+e.cost){
                if(count==n-1 && e.to==n-1) z=true;
                d[e.to]=d[e.from]+e.cost;
                update=true;
                if(count==n-1){
                    if(z){
                        cout << "inf" << endl;
                        return 0;
                    }
                    f=true;
                }
            }
        }
        if(f) break;
        if(!update) break;/*
        if(count>=n-1 && update){
            cout << "inf" << endl;
            return 0;
        }*/
        count++;
    }
    cout << d[n-1] << endl;

}