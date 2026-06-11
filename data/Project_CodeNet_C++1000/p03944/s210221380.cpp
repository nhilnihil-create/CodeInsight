#include<bits/stdc++.h>
using namespace std;
int main(){
    int w,h,n;
    cin >> w >> h >> n;
    int left = 0;
    int right = w;
    int up = 0;
    int down = h;
    for(int i=0;i<n;i++){
        int x,y,a;
        cin >> x >> y >> a;
        if(a==1){
            left = max(left,x);
        }else if(a==2){
            right = min(right,x);
        }else if(a==3){
            up = max(up,y);
        }else{
            down = min(down,y);
        }
    }
    int ans = (right-left)*(down-up);
    if(right-left<=0 || down-up<=0)ans=0;
    cout<<ans<<endl;
}