#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[100010];
int k;
inline void w(){
    for(int i=0;i<k/2;i++){
    	int u=s[i]-s[k-i-1];
    	if(u<0)u=-u;
        if(u!=1&&u!=2){
        	printf("No");
            return;
        }
    }
    printf("Yes");
}
int main(){
    scanf("%s",&s);
    k=strlen(s);
	if(k%2!=0){ 
        printf("No");
        return 0;
    }
    w();
    return 0;
}