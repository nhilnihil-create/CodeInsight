#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define SIZE 30

int main(){
    int N,K; cin>>N>>K;
    int A[100000],B[100000];
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
    ll ans=0;
    for(int i=0;i<SIZE;i++){
        if((K>>i)&1){
            //Kのi桁目を0にして，それ以下の桁は全部1にする．
            int d[SIZE];
            for(int j=0;j<SIZE;j++){
                if(j<i){
                    d[j]=1;
                }else if(j==i){
                    d[j]=0;
                }else{
                    d[j]=(K>>j)&1;
                }
            }
            ll tmp=0;
            for(int n=0;n<N;n++){
                //A[n]について考える．
                bool flag=true;
                for(int j=0;j<SIZE;j++){
                    if(d[j]==0 && ((A[n]>>j)&1)==1){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    tmp+=B[n];
                }
            }
            ans=max(ans,tmp);
        }
    }
    //補正しないKについて．
    int d[SIZE];
    for(int j=0;j<SIZE;j++){
        d[j]=(K>>j)&1;
    }
    ll tmp=0;
    for(int n=0;n<N;n++){
        //A[n]について考える．
        bool flag=true;
        for(int j=0;j<SIZE;j++){
            if(d[j]==0 && ((A[n]>>j)&1)==1){
                flag=false;
                break;
            }
        }
        if(flag){
            tmp+=B[n];
        }
    }
    ans=max(ans,tmp);
    cout<<ans<<endl;
    return 0;
}
