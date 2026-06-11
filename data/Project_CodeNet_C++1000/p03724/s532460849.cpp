#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M;cin>>N>>M;
    int array[N]={0};
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
      array[a-1]++;
      array[b-1]++;
    }
    bool ans=1;
    for(int i=0;i<N-1;i++){
        if(array[i]%2)ans=0;
    }

    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}