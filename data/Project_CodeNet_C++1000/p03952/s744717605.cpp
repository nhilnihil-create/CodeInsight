#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

int main(){
    
    int N,x;cin>>N>>x;
    if(x==1||x==2*N-1) cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        if(x>=N){
            for(int i=0;i<2*N-1;i++){
                int a=(x+i-(N-1)-1)%(2*N-1)+1;
                printf("%d\n",a);
            }
        }else{
            for(int i=0;i<2*N-1;i++){
                int a=(x+i+N-1)%(2*N-1)+1;
                printf("%d\n",a);
            }
        }
    }
}
