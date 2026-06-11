#include<iostream>

using namespace std;
int main(){
    int N;
    cin>>N;

    int A,sum=0;
    for(int i=0;i<N;++i){
        cin>>A;
        sum+=A;
    }

        if(sum%2==0){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
}