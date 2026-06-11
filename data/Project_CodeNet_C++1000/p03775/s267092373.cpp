#include<iostream>
#include<algorithm>

using namespace std;

int digit(long long x){
    int count=0;
        while(x>0){
            x/=10;
            count++;
        }
    return count;
}

int main(){
    long long N;
    cin>>N;
    int mini=digit(N);
        for(long long i=1;i*i<=N;++i){
            if(N%i!=0)continue;
            const long long j=N/i;
            const int compare=max(digit(i),digit(j));
            mini=min(compare,mini);

        }
    cout<<mini;
}