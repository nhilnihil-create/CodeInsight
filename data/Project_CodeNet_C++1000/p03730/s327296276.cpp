#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	int a,b,c;
  	cin>>a>>b>>c;
  int i=1;
  	while(true){
      if(a*i%b==c){
      	printf("YES");
        break;
      }
      i++;
      if(i>=10000000){
        printf("NO");
        break;
      }
    }
}
