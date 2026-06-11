#include<bits/stdc++.h>
using namespace std;
long long division(long long n, long long x){
    if(n==-1){

        return -1;
    }else if(n!=-1){
      
        return n/x;
    }

}

int main(){
    long long a,b,x;
    cin>>a>>b>>x;
    cout<<division(b,x)-division((a-1),x)<<endl;
    return 0;
}
