#include <bits/stdc++.h>
using namespace std;

//関数
void display(vector<long> B){
    for(int i=0;i<B.size();i++){
        cout<<B.at(i)<<endl;
    }
    cout<<endl;
}


    
//main関数
int main() {
    
    
    //入力
    long N;
    cin>>N;
    vector<long> A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }
    
    
    
    
    
    //計算
    long sum=0,times=0;
    for(int i=0;i<N;i++){
        sum+=A.at(i);
    }
    if(sum%((N*(N+1))/2)!=0){
        cout<<"NO"<<endl;
        return 0;
    }else{
        times=sum/((N*(N+1))/2);
    }
    vector<long> B(N);
    B.at(0)=A.at(0)-A.at(N-1);
    for(int i=1;i<N;i++){
        B.at(i)=A.at(i)-A.at(i-1);
    }
    
    //display(B);
    //cout<<times<<endl;
    
    for(int i=0;i<N;i++){
        B.at(i)-=times;
    }
    
    //display(B);
    
    vector<long> C(N);
    for(int i=0;i<N;i++){
        if((0-B.at(i))%N!=0 ||(0-B.at(i))<0){
            cout<<"NO"<<endl;
            return 0;
        }
        C.at(i)=(0-B.at(i))/N;
    }
    //display(C);
    
    long sumC=0;
    for(int i=0;i<N;i++){
        sumC+=C.at(i);
    }
    if(sumC!=times){
        cout<<"NO"<<endl;
        return 0;
    }
    
    
    
    //出力
    cout<<"YES"<<endl;

}