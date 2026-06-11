#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(void){
    int h,w; cin >> h >> w;
    int n; cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int index = 0,cnt=0;
    string ans="";
    for(int i=0;i<h;i++){
        if(i%2==0){
            for(int j=0;j<w;j++){
                if(a[index]<=cnt){
                    index++;
                    cnt =0;
                }
                if(ans.length()==0){
                    ans = to_string(index+1);
                }else{
                    ans += ' '+to_string(index+1);
                }
                // cout << index << '-';
                cnt++;
            }
        }else{
            for(int j=w-1;0<=j;j--){
                if(a[index]<=cnt){
                    index++;
                    cnt =0;
                }
                if(ans.length()==0){
                    ans = to_string(index+1);
                }else{
                    ans = to_string(index+1) + ' ' + ans;
                }
                
                cnt++;
            }
        }
        cout << ans << endl;
        ans = "";
    }
    return 0;
}