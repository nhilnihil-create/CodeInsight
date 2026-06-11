#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
  int h,w;
  char m[6];

  scanf(" %d %d",&h,&w);

  for(int i=1;i<=h;i++){
    for(int j=0;j<w;j++){
      scanf(" %s",m);
      if(strcmp(m,"snuke")==0){
        char a='A'+j;
        cout << a << i << endl;
      }
    }
  }

  return 0;

}
