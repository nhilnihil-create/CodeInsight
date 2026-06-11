#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    int N,M; cin>>N>>M;
    vector<int> num(N,1);
    vector<bool> red(N,false);
    red[0]=true;

    for(int i=0;i<M;i++){
        int x,y; cin>>x>>y;
        if(red[x-1]==true)red[y-1]=true;
        num[x-1]=num[x-1]-1;
        num[y-1]=num[y-1]+1;
        if(num[x-1]==0)red[x-1]=false;
    }
    int count=0;
    for(int i=0;i<N;i++){
        if(red[i]==true)count++;
    }
    cout<<count;
    return 0;
}