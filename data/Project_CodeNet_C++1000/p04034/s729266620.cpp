#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;cin>>N>>M;
    vector<int> array(N,1);
    vector<bool> red(N,0); 
    int ans=0;
    red[0]=1;
    for(int i=0;i<M;i++){
        int x,y;cin>>x>>y;
        if(red[x-1])red[y-1]=1;
        if(array[x-1]<=1)red[x-1]=0;
        array[x-1]--;
        array[y-1]++;
    }
    for(int i=0;i<N;i++)if(red[i])ans++;
    cout<<ans<<endl;
}