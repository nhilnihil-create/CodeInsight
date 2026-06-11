#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    pair<int,int>ans=make_pair(100*A,0);
    for(int i=0;i<=100;i++){
        if(100*A*i<=F){
            int J=(F-100*A*i)/(100*B);
            for(int j=0;j<=J;j++){
                if(100*A*i+100*B*j<=F){
                    int K=(F-100*A*i-100*B*j)/C;
                    for(int k=0;k<=K;k++){
                        if((A*i+B*j)*E>=k*C&&100*A*i+100*B*j+C*k<=F){
                            int L=(F-100*A*i-100*B*j-C*k)/D;
                            for(int l=0;l<=L;l++){
                                int sugar=k*C+l*D;
                                int water=100*(A*i+B*j);
                                if(sugar<=E*(A*i+B*j)&&sugar+water<=F&&sugar+water>0){
                                    if(double(100*sugar)/double(water+sugar)>double(ans.second*100)/double(ans.first)){
                                        ans.first=sugar+water;
                                        ans.second=sugar;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}