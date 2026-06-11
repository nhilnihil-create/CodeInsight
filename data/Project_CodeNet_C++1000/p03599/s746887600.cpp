#include<iostream>

using namespace std;

int main(){
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    A*=100;
    B*=100;
    double condence,max_=0.0;
    int Weight=0,Sugar=0;

        for(int a=0;F>=a*A;++a){
            for(int b=0;F-a*A>=b*B;++b){
                for(int c=0;F-a*A-b*B>=c*C;++c){
                    for(int d=0;F-a*A-b*B-c*C>=d*D;++d){
                        if(c*C+d*D<=(a*A+b*B)/100*E){
                            condence=(double)(c*C+d*D)/(double)(a*A+b*B+c*C+d*D)*100.0;
                            if(condence>=max_){
                                max_=condence;
                                Weight=a*A+b*B+c*C+d*D;
                                Sugar=c*C+d*D;

                            }
                        }
                    }
                }
            }
        }
    cout<<Weight<<" "<<Sugar;

}