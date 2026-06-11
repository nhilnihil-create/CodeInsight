#include <iostream>
using namespace std;

int main(){
    long int a[200000],n,cha;
    
    cin>>n;
    for(long int i=0;i<n;i++){
        //scanf("%ld",&s[i]);
        cin>>a[i];
    }
    
    long int back = 0;
    for(long int j=1;j<n;j++){
        back += a[j];
    }
    
    long int front = a[0];
    
    cha = abs(back - front);
    
    for(long int k=1;k<n-1;k++){
        front += a[k];
        back -= a[k];
        if(abs(front - back)<cha){
            cha = abs(front -back);
        }
    }
    cout<<cha<<endl;
    //printf("%ld\n",cha);
}
