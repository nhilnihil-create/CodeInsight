#include<iostream>
using namespace std;

int main(){
  int a,b,c,d;
  int timeMin,timeMax;
  
  cin >> a >> b >> c >> d;
  /*scanf("%d %d %d %d",&a,&b,&c,&d);*/
  
  
  if(a<c)
    timeMin = c;
  else
    timeMin = a;
  if(b<d)
    timeMax = b;
  else
    timeMax = d;
  /*if(a<c){
    timeMin = c;
  }
  else{
    timeMin = a;
  }
  if(b<d){
    timeMax = b;
  }
  else{
    timeMax = d;
  }*/
  
  
  if(timeMax-timeMin > 0)  
    cout << timeMax - timeMin;
    /*printf("%d",timeMax-timeMin);*/
  else
    cout << "0";
    /*printf("0");*/
  
}