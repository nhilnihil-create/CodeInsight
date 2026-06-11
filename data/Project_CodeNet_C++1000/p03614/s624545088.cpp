#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>
#include<array>
#include<numeric>

using namespace std;

int n,x[100010],tc=0,tk=0;

int tp(int a){
    return (a+1)/2;
}


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
        if(x[i]==i+1)tc++;
        else{
            if(tc)tk+=tp(tc);
            tc=0;
        }
    }
    tk+=tp(tc);
    printf("%d\n",tk);
    
}