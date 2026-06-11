#include <iostream>
using namespace std;

int main(){
    int n,i,l,r,g=0;
    
    
    cin>>n;
    for(i=0;i<n;i++){
        
        cin>>l>>r;
        g+=(r-l+1);
        
    }
    cout<<g<<endl;
    return 0;
    

    
}
