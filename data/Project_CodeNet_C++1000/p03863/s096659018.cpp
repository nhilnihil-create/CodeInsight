#include<iostream>
#include<string>
#include<stdio.h>
main(){
    std::string c;std::cin>>c;
    int len=c.length();
    if(c[0]==c[len-1]){
        if(len%2==0) puts("First");
        else puts("Second");
    }
    else{
        if(len%2==0) puts("Second");
        else puts("First");
    }
    return 0;
}