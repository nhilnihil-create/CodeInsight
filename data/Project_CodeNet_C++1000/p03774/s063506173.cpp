#include <bits/stdc++.h>
using namespace std;
typedef struct _dot{
    int a;
    int b;
}Dot;

int Distance(Dot a,Dot b){
    
    return abs(a.a-b.a) + abs(a.b - b.b);
}
int main(void){
    
   int N,M;
   cin >> N >> M;
   
   Dot student[N];
   Dot CheckPoint[M];
   
   for(int i=0;i<N;i++){
       cin >> student[i].a;
       cin >> student[i].b;
   }
   
   for(int i=0;i<M;i++){
       cin >> CheckPoint[i].a;
       cin >> CheckPoint[i].b;
   }
   
   for(int i=0;i<N;i++){
       int max,index=1;
       for(int j=0;j<M;j++){
           if(j==0){max = Distance(student[i],CheckPoint[j]);}
           else{if(max > Distance(student[i],CheckPoint[j])){ max = Distance(student[i],CheckPoint[j]); index = j+1;}}
       }
       cout << index << endl;
   }
}