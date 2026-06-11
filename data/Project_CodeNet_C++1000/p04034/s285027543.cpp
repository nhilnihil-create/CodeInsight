#include<iostream>
using namespace std;
int N,M,x,y,ans;
int main(){
    cin>>N>>M;
    int ball[N];
    bool red[N];
    for(auto &x:ball)x=1;
    for(auto &x:red)x=false;
    red[0]=true;
    for(int i=0;i<M;i++){
        cin>>x>>y;
        x--,y--;
        if(red[x]){
            if(ball[x]==1){
                red[x]=false;
                red[y]=true;
            }
            else red[y]=true;
        }
        ball[x]--;
        ball[y]++;
    }
    for(int i=0;i<N;i++)ans+=red[i];
    cout<<ans<<endl;
    return 0;
}