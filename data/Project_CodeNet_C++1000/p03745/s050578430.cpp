#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int N,i,cnt=1;
bool f;
int main(){
    cin>>N;
    int A[N];
    for(i=0;i<N;i++)cin>>A[i];
    for(i=0;A[i]==A[i+1];i++);
    if(A[i]>A[i+1])f=true;
    for(i++;i<N-1;i++){
        if(f&&A[i]<A[i+1]){
            cnt++;
            for(i++;A[i]==A[i+1];i++);
            f=(A[i]>A[i+1]);
        }
        if(!f&&A[i]>A[i+1]){
            cnt++;
            for(i++;A[i]==A[i+1];i++);
            f=(A[i]>A[i+1]);
        }
    }
    cout<<cnt<<endl;
    return 0;
}