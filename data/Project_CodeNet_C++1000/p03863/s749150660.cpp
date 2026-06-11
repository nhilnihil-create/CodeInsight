#include<iostream>
#include<string>
#include<string.h>
using namespace std;
char str[100005];
int main(){
	scanf("%s",str);
    int N=strlen(str);
    if(str[0]==str[N-1]){
        if(N%2==0){
            printf("First\n");
        }
        else{
        	printf("Second\n");
        }
    }
    else{
        if(N%2==0){
        	printf("Second\n");
        }
        else{
        	printf("First\n");
        }
    }
    //AC!
    return 0;
}