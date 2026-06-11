#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    bool ookii=false;
    bool hikui=false;

    int cnt=1;

    
    for(int i=0;i<n-1;i++){
        
        if(a[i]<a[i+1]){
            ookii=true;
        }
        else if(a[i]>a[i+1]){
            hikui=true;
        }
        if(ookii && hikui){
            ookii=false;
            hikui=false;
            cnt++;
        }
    }
    cout<<cnt;
    
    
    return 0;
    }
