#include <iostream>
#include <cmath>
using namespace std;

int digsum(long int a,long int b){
    int suma=0;
    int sumb=0;
    int max;
    while(a>0){
        suma += 1;
        a /= 10;
    }
    while(b>0){
        sumb += 1;
        b /= 10;
    }
    if(suma>=sumb){
        max = suma;
    }
    else{
        max = sumb;
    }
    return max;
};

int main(){
    long int N;
    cin>>N;
    int min=15;
    for(long int i=1;i<sqrt(N)+1;i++){
        if(N%i==0){
            long int j=N/i;
            if(digsum(i,j)<min){
                min = digsum(i,j);
            }
        }
    }
    cout<<min<<endl;
}