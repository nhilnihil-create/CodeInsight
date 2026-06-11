#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>

using namespace std;

int main(){

    int N;cin>>N;
    int x[N];REP(i,N)cin>>x[i];
    map<int,int> mp;
    REP(i,N)mp[x[i]]=i+1;
    int ans[N*N+1];
    fill_n(ans,N*N+1,-1);
    REP(i,N)ans[x[i]]=i+1;
    sort(x,x+N);
    int index=1;
    REP(i,N){
        int p = ans[x[i]];//埋める数字
        int cnt = p-1;
        while(cnt){
            if(index>x[i]){
                cout<<"No"<<endl;
                return 0;
            }

            if(ans[index]<0){
                ans[index]=p;
                cnt--;
            }
            index++;
        }
    }
    index = N*N;
    for(int i=N-1;i>=0;i--){
        int p = ans[x[i]];//埋める数字
        int cnt = N-p;
        while(cnt){

            if(index<x[i]){
                cout<<"No"<<endl;
                return 0;
            }
            if(ans[index]<0){
                ans[index]=p;
                cnt--;
            }
            index--;
        }
    }
    cout<<"Yes"<<endl;
    REP(i,N*N)cout<<ans[i+1]<<" ";
    cout<<endl;

    return 0;
}