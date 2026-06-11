#include<bits/stdc++.h>
using namespace std;

int main(){

    int x;
    scanf("%d", &x);


    int num=0;
    for(int i=1; ; ++i){
        num=(i*(i+1))/2;
        if(num>=x){
            /*if(num==x){
                printf("%d\n", i);
                break;
            }
            else{
                int num2=num-i;
                //printf("%d\n%d\n%d\n", num, num2, i);
                printf("%d\n", min( ((x-num2)+(i-1)), ((i+1)+(num-x)) ) );
                break;
            }*/
            printf("%d", i);
            break;
        }
    }






    return 0;
}
