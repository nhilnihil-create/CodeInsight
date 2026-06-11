#include<cstdio>
#include<cstring>
using namespace std;
int main(){
  char s[11];
  scanf("%s",s);
  int n=strlen(s);
  if(n>=4&&s[0]=='Y'&&s[1]=='A'&&s[2]=='K'&&s[3]=='I')
    printf("Yes\n");
  else
    printf("No\n");
}