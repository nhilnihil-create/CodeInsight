#include <iostream>
const int maxn = 100005 ; 
int a[maxn] ;
using namespace std;
int main(int argc, char *argv[])
{
    int n,k=0;
    cin>>n;
    for(int i= 0;i<n;i++){
        cin>>a[i];    
    }
    int i ;
    for(i=0;i<n;i++){
        if(a[i]==i+1){
        int t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
            k++;        
        }
    if(a[i]==i+1&&i==n-1){
        int t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
            k++;        
        }    
    }
    cout<<k<<endl;
    return 0;
}