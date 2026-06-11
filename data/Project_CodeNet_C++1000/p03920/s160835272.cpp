#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n,m,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        sum+=i;
        if(sum>=n){m=i;break;}
    }
    for(int i=0;i<m;i++){
        if(i+1!=sum-n)cout<<i+1<<endl;
    }
    return 0;
}