#include <iostream>

using namespace std;

int main()
{
    string S;
    string T="NSWE";
    int count=0;
    cin>>S;
    int sum=0;
    int L=S.length();
    for(int i=0;i<L;i++){
       if(S[i]==T[0]){
           for(int j=0;j<L;j++){
               if(S[j]==T[1]){
                   count++;
                   break;
               }
           }
       }
       if(S[i]==T[1]){
           for(int j=0;j<L;j++){
               if(S[j]==T[0]){
                   count++;
                   break;
               }
           }
       }
       if(S[i]==T[3]){
           for(int j=0;j<L;j++){
               if(S[j]==T[2]){
                   count++;
                   break;
               }
           }
       }
       if(S[i]==T[2]){
           for(int j=0;j<L;j++){
               if(S[j]==T[3]){
                   count++;
                   break;
               }
           }
       }
    }
    if(count==L){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}