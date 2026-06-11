#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  char c[105];
  for(int i=0;i<a;i++){
    scanf("%s",c);
    printf("%s\n%s\n",c,c);
  }
  return 0;
}
