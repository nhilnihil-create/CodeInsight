#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
using namespace std;
int main() {
   int x;
   cin>>x;
   int n=0;
   for(int i=1;i<=x;i++){
       n+=i;
       if(n>=x){
           cout<<i<<endl;
           return 0;
       }
   }
}   

