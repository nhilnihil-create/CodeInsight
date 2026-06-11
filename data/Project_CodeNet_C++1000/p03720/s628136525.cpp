#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,m;
    cin >> n >> m;
    
    int ans[n];
    for(int i=0;i<n;i++)    ans[i] = 0;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        
        ans[a-1]++;
        ans[b-1]++;
    }
    
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
    
    return 0;
}
