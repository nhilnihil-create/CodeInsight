#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int main(){
    int H,W;cin>>H>>W;
    if(H%3==0 || W%3==0){
        cout<<0<<endl;
        return 0;
    }
    else{
        ll ans=min(H,W);
        ll S1,S2,S3,dS;
        for(int w=1;w<=W-1;w++){
            S1=(ll)w*(ll)H;
            if(H%2==0){
                S2=S3=(ll)(W-w)*(ll)(H/2);
                dS=abs(S1-S2);
            }
            else{
                S2=(ll)(W-w)*(ll)(H/2);
                S3=(ll)(W-w)*(ll)(H/2+1);
                dS=max(S3-S2,max(abs(S1-S2),abs(S1-S3)));
            }
            ans=min(ans,dS);
        }
        for(int h=1;h<=H-1;h++){
            S1=(ll)h*(ll)W;
            if(W%2==0){
                S2=S3=(ll)(H-h)*(ll)(W/2);
                dS=abs(S1-S2);
            }
            else{
                S2=(ll)(H-h)*(ll)(W/2);
                S3=(ll)(H-h)*(ll)(W/2+1);
                dS=max(S3-S2,max(abs(S1-S2),abs(S1-S3)));
            }
            ans=min(ans,dS);
        } 
        cout<<ans<<endl;
        return 0;       
    }
    return 0;
}