#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  
   int N,sum=0;
   cin >> N;
   int data[N];
   for(int i=0;i<N;i++){ cin >> data[i]; sum+= data[i];}
   
   if(sum %10 == 0){
       sort(data,data+N);
   
       for(int i=0;i<N;i++){
           if((sum-data[i]) %10 != 0){sum -= data[i]; break;}
       }
       
       if(sum %10 == 0) sum = 0;
   }
   
   cout << sum << endl;
}