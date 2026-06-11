#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl

int main(){
    int K, S; cin>>K>>S;
    int cnt=0;

    for(int x=0; x<=K; x++){
        for(int y=0; y<=K; y++){
            if(x+ y+ max(0, S-x-y) ==S && S-x-y<=K){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}