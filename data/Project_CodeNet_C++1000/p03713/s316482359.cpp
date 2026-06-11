#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    long long H,W;
    cin>>H>>W;
    if(H%3==0||W%3==0){
        cout << 0 << endl;
        return 0;
    }
    //横T字その１
    long long left = W/3;
    long long right = W-left;
    long long leftb =H*left;
    long long Hhalf = H/2;
    long long rightupb = Hhalf*right;
    long long rightdob = (H-Hhalf)*right;
    long long Smax=max(max(leftb,rightupb),rightdob);
    long long Smin=min(min(leftb,rightupb),rightdob);

    long long ans = Smax-Smin;
    //  横T字その２
    left=W/3+1;
    right = W-left;
    leftb =H*left;
    rightupb = Hhalf*right;
    rightdob = (H-Hhalf)*right;
    Smax=max(max(leftb,rightupb),rightdob);
    Smin=min(min(leftb,rightupb),rightdob);

    ans = min(ans,Smax-Smin);
    //縦T字その１
    long long up = H/3;
    long long upb=up*W;
    long long down=H-up;
    long long Whalf = W/2;
    long long downrightb=Whalf*down;
    long long downleftb = (W-Whalf)*down;
    Smax=max(max(upb,downleftb),downrightb);
    Smin=min(min(upb,downleftb),downrightb);
    
    ans = min(ans,Smax-Smin);

    //縦T字その２
    up = H/3+1;
    upb=up*H;
    down=H-up;
    downrightb=Whalf*down;
    downleftb=(W-Whalf)*down;
    Smax=max(max(upb,downleftb),downrightb);
    Smin=min(min(upb,downleftb),downrightb);
    
    ans = min(ans,Smax-Smin);

    //縦3等分
    ans=min(ans,W);
    //横3等分
    ans=min(ans,H);

    cout << ans << endl;
    return 0;
}