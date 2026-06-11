#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
   string astring;
   cin >> astring;
   for(int i = 0; i<19; i++){
   		if(astring[i] == ','){
   			printf(" ");
   		} else {
   			printf("%c", astring[i]);
   		}
   }
   printf("\n");
}
