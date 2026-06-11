#include<bits/stdc++.h>
using namespace std;
char str[100000+5];
int main() {
    scanf("%s",str);
    int len=strlen(str);
 
    int num=len-2;
    if(str[0]!=str[len-1]){
        if(num%2)
            printf("First\n");
        else
            printf("Second\n");
    }
    else{
        if(num%2)
            printf("Second\n");
        else
            printf("First\n");
    }
 
    return 0;

}
