#include <iostream>
using namespace std;

int main(){
    int a,ai1,aa=0;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        
        ai1=k-a;
        
        if(ai1<a){
            aa+=ai1;
        }else{
            aa+=a;
        }
    }
    cout<<aa*2<<endl;
}    

    
