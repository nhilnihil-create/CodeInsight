#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;++i)cin>>A[i];
    sort(A,A+N);

    int count=0,i=0,sum;
    while(i<N){
        sum=0;
        int temp=A[i];
            while(i<N && A[i]==temp)++i,sum++;
        count+=sum%2;
    }
    cout<<count;
}