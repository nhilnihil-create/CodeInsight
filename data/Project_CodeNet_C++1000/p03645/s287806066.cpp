#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int c[n];
    for(int i=0;i<n;i++) c[i]=0;
    int d[n];
    for(int i=0;i<n;i++) d[i]=0;
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        if(a==1) c[b-1]++;
        if(b==1) c[a-1]++;
        if(a==n) d[b-1]++;
        if(b==n) d[a-1]++;
    }
    bool flag=false;
    for(int i=1;i<n-1;i++){
        if(c[i]>0&&d[i]>0) flag=true;
    }
    if(flag) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}