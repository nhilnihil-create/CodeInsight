#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(100000);
    vector<int> cnt(100000);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]==0){
            cnt[0]++; cnt[1]++; 
        }else if(a[i]==100000-1){
            cnt[100000-2]++; cnt[100000-1]++;
        }else{
            cnt[a[i]-1]++; cnt[a[i]]++; cnt[a[i]+1]++;
        }
    }
    int ans = 0;
    for(int i=0; i<100000; i++){
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;
    return 0;
}