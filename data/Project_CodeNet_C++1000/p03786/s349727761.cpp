#include<iostream>
#include<algorithm>
using namespace std;
int N;
int A[100000];
bool f(int n){
    long long size=A[n];
    for(int i=N-1;i>=0;i--){
        if(i==n)continue;
        if(A[i]<=size*2)size+=A[i];
        else return false;
    }
    return true;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>A[i];
    sort(A,A+N,greater<int>());
    int ok=0,ng=N,mid;
    while(abs(ok-ng)>1LL)mid=(ok+ng)/2LL,(f(mid))?ok=mid:ng=mid;
    cout<<ok+1<<endl;
    return 0;
}