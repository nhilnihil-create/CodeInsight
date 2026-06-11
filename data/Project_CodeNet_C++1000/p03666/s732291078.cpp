#include <bits/stdc++.h>
using namespace std;

//関数
    //const long INF=1000000000000000;
    
//main関数
int main() {
    
    
    //入力
    long N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;
    
    
    
    //計算
    bool possible=false;
    
    for(int k=0;k<=N-1;k++){
        if(B-A+k*C-(N-1-k)*D<=0 && 0<=B-A+k*D-(N-1-k)*C){
            possible=true;
            //cout<<k<<endl;
        }
    }
    
    //出力
    if(possible){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}