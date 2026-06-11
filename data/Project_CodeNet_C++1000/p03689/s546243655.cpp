
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;


int main(){
    int H,W,h,w;cin>>H>>W>>h>>w;
    
    if(H%h==0&&W%w==0)printf("No\n");
    else{
        int big=999999937;
        int small=(big/(h*w-1)+1)*(-1);
        
        printf("Yes\n");
        for(int i=0;i<=H-1;i++){
            for(int j=0;j<=W-1;j++){
                if(i%h==0&&j%w==0)printf("%d",big);
                else printf("%d",small);
                if(j!=W-1)printf(" ");
            }
            printf("\n");
        }
        
    }
    
    return 0;
}


