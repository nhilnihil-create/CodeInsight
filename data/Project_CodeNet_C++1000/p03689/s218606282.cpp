#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int n,m,h,w;
    cin>>n>>m>>h>>w;
    int ans[n][m]={};
    int a[n+1]={},b[m+1]={};
    a[1] = 1111111;
    b[1] = 1111111;
    for(int i=1;i<n;i++){
        a[i+1] = a[i]+1;
        if(i+1 >= h) a[i+1] = a[i+1-h]-1;
    }
    for(int i=1;i<m;i++){
        b[i+1] = b[i]+1;
        if(i+1>=w) b[i+1] = b[i+1-w]-1;
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j] = a[i+1] - a[i];
            sum += ans[i][j];
        }
    }
    if(sum>0 && n%h){
        cout << "Yes\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
    sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j] = b[j+1] - b[j];
            sum += ans[i][j];
        }
    }
    if(sum > 0 && m%w){
        cout << "Yes\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
    cout << "No\n";
    
}