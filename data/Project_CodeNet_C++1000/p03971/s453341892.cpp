#include <stdio.h>
#include <math.h>
#include <string.h>



int main(void){
  int n,a,b,kaigai,kouho=0;
  char s[100005];
  
  scanf("%d %d %d", &n,&a,&b);
  	  scanf("%s", s);

  
  
  for(int i=0;i<n;i++){

    if(s[i] =='a'){
      if(kouho<(a+b)){
        printf("Yes\n");
        kouho++;
      }
      else printf("No\n");
    }
    else if(s[i] =='b'){
      if(kouho<(a+b) && kaigai <b){
	      kaigai++;
        printf("Yes\n");
        kouho++;
      }
      else printf("No\n");
    }
    else printf("No\n");
  }
    
    return 0;
}
