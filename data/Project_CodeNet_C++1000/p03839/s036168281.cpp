#include <bits/stdc++.h>
using namespace std;

//関数
    //const long INF=1000000000000000;
    
//main関数
int main() {
    
    
    //入力
    long N,K;
    cin>>N>>K;
    vector<long> a(N);
    for(int i=0;i<N;i++){
        cin>>a.at(i);
    }
    
    
    
    
    //計算
    long maxi=0,tempKsum=0,tempKmaxi=0;
    for(int i=0;i<K;i++){
        tempKmaxi+=max((long)0,a.at(i));
        tempKsum+=a.at(i);
    }
    long rakusa=tempKmaxi-max((long)0,tempKsum);
    maxi=tempKmaxi;
    
    //cout<<maxi<<" "<<tempKsum<<" "<<tempKmaxi<<" "<<rakusa<<endl;
    for(int i=K;i<N;i++){
        maxi+=max((long)0,a.at(i));
        tempKsum+=(a.at(i)-a.at(i-K));
        tempKmaxi+=(max((long)0,a.at(i))-max((long)0,a.at(i-K)));
        rakusa=min(rakusa,tempKmaxi-max((long)0,tempKsum));
        
        //cout<<maxi<<" "<<tempKsum<<" "<<tempKmaxi<<" "<<rakusa<<endl;
    }
    
    //出力
    cout<<maxi-rakusa<<endl;
}