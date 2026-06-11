#include <iostream>
using namespace std;
int main() {
    int n;
    int x=0;
    int b=0;
    cin>>n;
    char a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]=='I'){
            x=x+1;
            
        }
        else if(a[i]=='D'){
            x=x-1;
        }
        b=max(b,x);
    }cout<<b;
    return 0;


}
