#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int pairs[100000];
int non_pairs[100000];
map<int,int> nums;

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int X;
        cin>>X;
        nums[X]++;
    }
    for(auto n:nums){
        int N=n.first%M;
        int C=n.second;
        if(C>1){
            if(C%2){
                non_pairs[N]++;
                C--;
            }
            pairs[N]+=C;
        }else{
            non_pairs[N]++;
        }
    }
    // for(int i=0;i<M;i++){
    //     cout<<i<<' '<<non_pairs[i]<<' '<<pairs[i]<<endl;
    // }
    int ans=(non_pairs[0]+pairs[0])/2;
    for(int i=1;i<M;i++){
        if(M%2==0&&i*2==M){
            ans+=(non_pairs[i]+pairs[i])/2;
            non_pairs[i]=pairs[i]=0;
            continue;
        }
        if(non_pairs[i]>0){
            int P=min(non_pairs[i],non_pairs[M-i]);
            ans+=P;
            non_pairs[i]-=P;
            non_pairs[M-i]-=P;
            // if(P)cout<<'P'<<P<<' '<<i<<' '<<M-i<<endl;
            if(non_pairs[i]>0&&pairs[M-i]>0){
                int Q=min(non_pairs[i],pairs[M-i]);
                if(Q%2==0){
                    ans+=Q;
                    non_pairs[i]-=Q;
                    pairs[M-i]-=Q;
                }else{
                    ans+=Q;
                    non_pairs[i]-=Q;
                    pairs[M-i]-=Q+1;
                    non_pairs[M-i]+=1;
                }
                // if(Q)cout<<'Q'<<Q<<' '<<i<<' '<<M-i<<endl;
            }
        }
    }
    // cout<<ans<<endl;
    for(int i=1;i<M;i++){
        ans+=pairs[i]/2;
    }
    cout<<ans<<endl;
    return 0;
}