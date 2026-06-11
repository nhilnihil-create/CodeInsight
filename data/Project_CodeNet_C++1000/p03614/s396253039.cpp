#include <iostream>
#include <algorithm>
#define INF 10000000000

using namespace std;
int main(void){
    int N;
    cin>>N;
    int P[N+1]; P[0]=0;
    for(int i=1;i<=N;i++){
        cin>>P[i];
    }
    int ans=0;
    for(int i=1;i<N;i++){
        if(i==P[i]){swap(P[i],P[i+1]); ans++;}
    }
    if(N==P[N]){ans++;}
    cout<<ans;
    return 0;
}
