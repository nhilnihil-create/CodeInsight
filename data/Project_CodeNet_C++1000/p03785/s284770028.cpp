#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N,C,K;
    cin>>N>>C>>K;
    vector<int>T(N);

    for(int i=0;i<N;++i)cin>>T[i];
    sort(T.begin(),T.end());

    int count=0;

        for(int i=0;i<N;){

            int s=i;
            while(T[i]-T[s]<=K && i-s<C && i<N)++i;
        
        ++count;
            
        }
    cout<<count;

}