#include <bits/stdc++.h>
using namespace std;
int ca[200005];
int cb[200005];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(a==1)ca[b]++;
        else if(b==n)cb[a]++;
    }
    for(int i=1;i<=n;i++){
        if(ca[i]>0 && cb[i]>0){
            cout << "POSSIBLE";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}