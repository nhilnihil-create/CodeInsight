#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int shi[100005];
int main(){
    int a;
    while(~scanf("%d",&a)){
        int pan=0;
        for(int i=0;i<a;i++)scanf("%d",&shi[i]);
        sort(shi,shi+a);
        if(shi[0]>=a){
                if((shi[0]-a+1)%2==1)printf("Second\n");
                else printf("First\n");
                continue;
        }
        int ru=1;int s=a;s-=shi[0];
        while(shi[ru]-shi[ru-1]+1<s){
            s-=(shi[ru]-shi[ru-1]+1);
            if(shi[ru]==shi[ru-1]){
                if(pan==0)pan=1;else pan=0;
            }
            else pan=0;
            ru++;
        }
        int k=shi[ru]-shi[ru-1];
        if(k%2==1&&pan==1)pan=0;
        if(s==1){
            if(pan==0)printf("First\n");
            else printf("Second\n");
        }
        else{
            int l=shi[ru]-shi[ru-1]+1-s+1;
            if(l%2==1)printf("Second\n");
            else printf("First\n");
        }
    }
}
/*
1
0
6
5 5 5 4 4 3
6
5 4 4 4 4 3
6
3 4 3 1 2 0
*/

