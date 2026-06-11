#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n1,n2,n;
    cin>>n1>>n2;
    n=n1+n2;
    if(n<10){
        cout<<n1+n2<<endl;
    }
    else{
        cout<<"error"<<endl;
    }
    return 0;
}

