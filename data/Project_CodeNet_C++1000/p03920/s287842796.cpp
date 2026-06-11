#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll ;

int main(){
    int N,a=0,i=0;
    cin>>N;
    while(a<N){
        i++;
        a+=i;
    }
    while(N>0){
        if(N>=i){
            N-=i;
            cout<<i<<endl;
        }
        i--;
    }
    return 0;
}