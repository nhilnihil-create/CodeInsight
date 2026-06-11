#include<iostream>

int main(){
int n;
 std::cin >> n;
 int a[n+1];
 for(int i=1;i<=n;i++)
     std::cin >> a[i];
 bool f=0;
 int t=0;
 int i=1;
 while(t!=n){
    if(a[i]==2){
          t++;
          f=1;
          break;
    }
    else{
     i=a[i];
    }
    t++;
 }
 f==1?std::cout << t : std::cout << "-1";
 return 0;
}
