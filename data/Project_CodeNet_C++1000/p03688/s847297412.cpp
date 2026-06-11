#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2003;

int main(){
    
    int N;cin>>N;
    vector<int> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    
    sort(all(S));
    
    if(S[N-1]-S[0]>=2) cout<<"No"<<endl;
    else if(S[N-1]==S[0]){
        if(S[0]==N-1) cout<<"Yes"<<endl;
        else{
            if(S[0]*2<=N) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }else{
        int cnt=0;
        for(int i=0;i<N;i++){
            if(S[i]==S[0]) cnt++;
        }
        int rem=N-cnt;
        if(rem/2+cnt-1>=S[0]&&1+cnt-1<=S[0]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

