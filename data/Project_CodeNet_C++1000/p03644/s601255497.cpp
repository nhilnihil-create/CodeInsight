#include <bits/stdc++.h>
using namespace std;
int countNoOfTwos(int N){
    int noTwos = 0;
    while(N){
        if(N%2==0){
            noTwos++;
            N = N / 2;
        }else{
            break;
        }
    }
    return noTwos;
}
int main(){
    int N;
    cin>>N;
    int finNo,finMax = INT_MIN;
    for(int i=1;i<=N;i++){
        if(finMax < countNoOfTwos(i)){
            finMax = countNoOfTwos(i);
            finNo = i;
        }
    }
    cout<<finNo<<endl;
}