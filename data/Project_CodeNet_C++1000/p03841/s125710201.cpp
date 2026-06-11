#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    
    int n;
    cin>>n;
    int ans[n*n]={};
    array<int,2> a[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i] = {x,i};
        ans[x-1] = i+1;
    }
    sort(a,a+n);
    int now = 0;
    int cnt = 0;
    for(int i=0;i<n*n;i++){
        if(ans[i]) continue;
        while(now < n && cnt == a[now][1]){
            cnt = 0;
            now++;
        }
        if(now == n) break;
        ans[i] = a[now][1]+1;
        cnt++;
    }
    now = n-1;
    cnt = 0;
    for(int i=n*n-1;i>=0;i--){
        if(ans[i]) continue;
        while(now >=0 && cnt == n - a[now][1] - 1){
            cnt = 0;
            now--;
        }
        if(now == -1) break;
        ans[i] = a[now][1]+1;
        cnt++;
    }
    int c[n+1]={};
    bool pos = true;
    now = 0;
    for(int i=0;i<n*n;i++){
        //cerr << i << " " << ans[i] << endl;
        if(ans[i]==0) pos = false;
        c[ans[i]]++;
        if(a[now][0]-1 == i){
            if(c[a[now][1]+1] != a[now][1]+1){
                pos = false;
            }
            now++;
        }
        if(now == n) break;
    }
    if(pos){
        cout << "Yes\n";
        for(int i=0;i<n*n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else cout << "No\n";
}
