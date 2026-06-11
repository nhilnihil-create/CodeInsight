#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N;
    int maxmax=0;
    cin>>N;
    int lis[200]={0};
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        lis[a]++;
        maxmax=max(maxmax,a);
    }
    //cout<<maxmax;
    if(maxmax%2==0){
        for(int i=maxmax;i>=maxmax/2;i--){

/*
                            for(int j=0;j<10;j++){
        printf("[%d]",lis[j]);
    }
    puts("");

*/


            lis[i]--;
            if(lis[i]<0){
                puts("Impossible");
                return 0;
            }
        }
/*
            for(int i=0;i<10;i++){
        printf("[%d]",lis[i]);
    }
    puts("");
*/

        for(int i=maxmax/2+1;i<=maxmax;i++){
            lis[i]--;
            if(lis[i]==-1){
                puts("Impossible");
                return 0;
            }
        }
    }
    else{
        for(int i=maxmax;i>maxmax/2;i--){
            lis[i]-=2;
            if(lis[i]<0){
                puts("Impossible");
                return 0;
            }
        }
    }
    for(int i=0;i<200;i++){
        if(lis[i]!=0){
            if(i<=(maxmax+1)/2){
                puts("Impossible");
                return 0;
            }
        }
    }
    puts("Possible");


/*
    for(int i=0;i<10;i++){
        printf("[%d]",lis[i]);
    }
    puts("");
*/


    return 0;
}

