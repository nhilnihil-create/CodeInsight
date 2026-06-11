#include<stdio.h>
#include<string.h>

int main() {
  int n,k;
  scanf("%d%d", &n, &k);
  char buffer[101];
  char str[100][101];
  
  for(int i=0; i<n; i++){
    scanf("%s", &str[i]);
  }

  for(int i=0; i<n-1; i++){
    for(int j=n-1; i<j; j--){
      if(strcmp(str[j-1], str[j])>0){
        strcpy(buffer, str[j]);
        strcpy(str[j], str[j-1]);
        strcpy(str[j-1], buffer);
      }
    }
  }

  for(int i=0; i<n; i++){
    if(i==n-1){
      printf("%s\n", str[i]);
    }else{
      printf("%s", str[i]);
    }
  }
  return 0;
}
