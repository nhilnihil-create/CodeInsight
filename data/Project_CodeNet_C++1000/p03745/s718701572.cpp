#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;++i)cin>>A[i];

    int count=0;
       for(int i=0;i<N;){
               while(A[i]==A[i+1]){
                    ++i;
               }

           if(A[i]<A[i+1]){
               while(A[i]<=A[i+1]){
                   ++i;
               }
           }else if(A[i]>A[i+1]){
               while(A[i]>=A[i+1]){
                   ++i;
               }
           }
           
           ++i;
           ++count;
       } 
    cout<<count;
}

