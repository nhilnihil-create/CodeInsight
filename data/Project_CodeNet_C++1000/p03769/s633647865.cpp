#include<bits/stdc++.h>
using namespace std;

using ll=__int128;
const ll INF=1e15;
int main(){
    vector<vector<ll>> comb(300,vector<ll>(300,0));
    for(int i=0;i<300;i++){
        comb[i][0]=1;
        comb[i][i]=1;
    }
    for(int i=1;i<300;i++){
        for(int j=1;j<i;j++){
            comb[i][j]=min(comb[i-1][j]+comb[i-1][j-1],INF);
        }
    }
    long long bufn;
    cin>>bufn;
    ll n=bufn;
    vector<int> ans;

    auto calcPatSingle=[&](int len){
        ll sum=0;
        for(int k=2;k<=len;k+=2){
            sum+=comb[len][k];
        }
        return sum;
    };
    auto calcPatCross=[&](int li,int lk,int lj,int lp){
        ll sum=0;
        for(int i=1;i<=min(li,lk);i++){
            sum+=comb[li][i]*comb[lk][i];
        }
        ll sum2=0;
        for(int i=1;i<=min(lj,lp);i++){
            sum2+=comb[lj][i]*comb[lp][i];
        }
        return sum*sum2;
    };
    int num=1;
    while(n){
        int besti=-1;
        int bestj=-1;
        int bestk=-1;
        int bestp=-1;
        ll bestSum=0;
        for(int i=1;i<=20;i++){
            for(int k=0;i+k<=40;k++){
                for(int j=0;j<=20;j++){
                    for(int p=0;p+j<=i+k;p++){
                        ll sum=calcPatSingle(i+k)+calcPatSingle(j+p)+calcPatCross(i,k,j,p);
                        if(sum<=n && double(bestSum)/(besti+bestj+bestk+bestp)<double(sum)/(i+j+k+p)){
                            besti=i,bestj=j,bestk=k,bestp=p;
                            bestSum=sum;
                        }
                    }
                    
                }
            }
        }
        n-=bestSum;
        
        for(int i=0;i<besti;i++){
            ans.push_back(num);
        }
        for(int j=0;j<bestj;j++){
            ans.push_back(num+1);                
        }
        for(int i=0;i<bestk;i++){
            ans.push_back(num);
        }
        for(int j=0;j<bestp;j++){
            ans.push_back(num+1);                
        }

        num+=2;
    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<(i+1==ans.size() ? "\n" : " ");
    }
    return 0;
}