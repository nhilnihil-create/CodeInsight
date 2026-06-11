#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int f(long long A){
    int res=0;
    while(A>0){
        A/=10;
        res++;
    }
    return res;
}

int F(long long A,long long B){
    return max(f(A),f(B));
}

long long a[100005],b[100005];
int main(void){
    // Your code here!
    long long n;
    cin>>n;
    
    int k=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            a[k]=i;
            b[k]=n/i;
            //cout<<a[k]<<" "<<b[k]<<endl;
            k++;
        }
    }
    int minute=2000000;
    for(int i=0;i<k;i++){
        minute=min(minute,F(a[i],b[i]));
    }
    cout<<minute<<endl;
    return 0;
}
