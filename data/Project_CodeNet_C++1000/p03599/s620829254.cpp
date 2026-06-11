#include <iostream>
#include <vector>
#include <set>


using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)

int main(){

   int A,B,C,D,E,F;
   scanf("%d %d %d %d %d %d",&A,&B,&C,&D,&E,&F);

   //cout<<"A:"<<A<<"B:"<<B<<"C:"<<C<<"D:"<<D<<"E:"<<E<<"F:"<<F<<endl;
   


   set<int> set_w;
   set<int> set_s;

   int max_w=100*A;;
   int max_s=0;

   double max_f=0;
   double f;


   

   for(int a=0;a*A*100<=F;++a){
       for(int b=0;b*B*100<=F;++b){
           if(a*A*100+b*B*100<=F){
               set_w.insert(a*A*100+b*B*100);
           }

       }
   }
   /*
    for(set<int>::iterator i=set_w.begin();i!=set_w.end();++i){
       cout<<*i<<endl;
   }
   */

   for(int c=0;c*C<=F;++c){
       for(int d=0;d*D<=F;++d){
           if(c*C+d*D<=F){
               set_s.insert(c*C+d*D);
           }
       }
   }
/*
   for(set<int>::iterator i=set_s.begin();i!=set_s.end();++i){
       cout<<*i<<endl;
   }
*/

   for(set<int>::iterator w=set_w.begin();w!=set_w.end();++w){
       for(set<int>::iterator s=set_s.begin();s!=set_s.end();++s){
           if((*w)+(*s)<=F&&(E*(*w)>=(*s)*100)){
               if(*s==0){
                   f=0;
               }else{
                   f=(*s)*1.0/((*s)+(*w));
               }
               
               if(max_f<f){
                   max_f=f;
                   max_w=*w;
                   max_s=*s;
               }
           }
       }

   }

   cout<<max_w+max_s<<" "<<max_s<<endl;
}
