#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
ll arr[51] = {0};
int main(){
    ll int n;
    int i;
    while(scanf("%lld",&n)!=EOF){
        for(i = 0;i < 50;i++){
            arr[i] = 49+n/50;
        }
        //cout<<"*****"<<endl;
        ll m = n%50;
        for(i = 0;i < 50;i++){
            arr[i] = arr[i]-m;
        }

        for(i = 0;i < m;i++){
            arr[i] = arr[i]+50;
        }
         printf("50\n");
        for(int i=0;i<50;i++)printf("%lld ",arr[i]);
        printf("\n");
    }
}
