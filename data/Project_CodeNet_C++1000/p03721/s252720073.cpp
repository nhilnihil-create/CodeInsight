#include <iostream>
#include <cmath>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;
typedef long long ll;
/*
int main(){
for(int i=1;i<=100000;++i){
  cout<<i<<" "<<100000<<endl;
}
}

*/


int main(){
    ll N,K;
    cin>>N>>K;
    ll array[100001];
    
    for(int i=0;i!=100001;++i){
        array[i]=0;
    }
    
    for(int i=1;i!=N+1;++i){
        ll a,b;
        cin>>a>>b;
        array[a]+=b;
    }
    
    ll sum_array[100001];
    sum_array[0]=0;
    
    for(int i=1;i<=100000;++i){
        sum_array[i]=array[i]+sum_array[i-1];
    }
  
    int i;
 
    for(i=1;i<=100000;++i){
        if(sum_array[i-1]<K&&K<=sum_array[i]){
            break;
        }
    }
    
    
    cout<<i<<endl;
        
    
}

