#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>

using namespace std;

int main(){
    int N;
    int A[100];
    int Num[101]={};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        Num[A[i]]++;
    }
    sort(A,A+N);
    int MAX=A[N-1];
    bool flag=true;
    for(int i=MAX;i>MAX/2;i--){
        if(Num[i]<2){
            flag=false;
            break;
        }
    }
    if(MAX%2==0){
        if(Num[MAX/2]!=1) flag=false;
    }else{
        if(Num[MAX/2+1]!=2) flag=false;
    }
    for(int i=(MAX-1)/2;i>0;i--){
        if(Num[i]!=0) flag=false;
    }
    if(flag){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
    
    return 0;
}

