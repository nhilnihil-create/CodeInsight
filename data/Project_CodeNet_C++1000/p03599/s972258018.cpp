#include<iostream>
using namespace std;

int main(){
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    double den=-1;
    int sw,s;
    for(int i=0;i*100*A<=F;i++){
        for(int j=0;i*100*A+j*100*B<=F;j++){
            for(int k=0;i*100*A+j*100*B+k*C<=F&&k*C<=E*(i*A+j*B);k++){
                for(int h=0;i*100*A+j*100*B+k*C+h*D<=F&&(k*C+h*D)<=E*(i*A+j*B);h++){
                    double tmp=(double)(k*C+h*D)/(double)(i*100*A+j*100*B+k*C+h*D)*100;
                    if(den<tmp){
                      den=tmp;
                        sw=i*100*A+j*100*B+k*C+h*D;
                        s=k*C+h*D;
                    }
                }
            }
        }
    }
    cout<<sw<<' '<<s<<endl;
    return 0;
}