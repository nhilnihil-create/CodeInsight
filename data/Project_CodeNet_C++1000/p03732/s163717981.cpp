#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,w,w1,a,b,ans,num[4];
long long W[4];
vector<int> v[4];
int main(){
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(!i)w1=a;
        v[a-w1].push_back(b);
    }
    for(int i=0;i<4;i++)sort(v[i].begin(),v[i].end(),greater<int>());
    for(int A=0;A<=v[0].size();A++){
        if(A){
            W[0]+=w1;
            num[0]+=v[0][A-1];
        }W[1]=W[0];
        num[1]=num[0];
        for(int B=0;B<=v[1].size();B++){
            if(B){
                W[1]+=w1+1;
                num[1]+=v[1][B-1];
            }W[2]=W[1];
            num[2]=num[1];
            for(int C=0;C<=v[2].size();C++){
                if(C){
                    W[2]+=w1+2;
                    num[2]+=v[2][C-1];
                }W[3]=W[2];
                num[3]=num[2];
                for(int D=0;D<=v[3].size();D++){
                    if(D){
                        W[3]+=w1+3;
                        num[3]+=v[3][D-1];
                    }
                    if(W[3]>w)continue;
                    ans=max(ans,num[3]);
                }
            }
        }
    }
    cout<<ans<<endl;
}