#include<iostream>
using namespace std;
int main()
{
    long long int a,b,x,i,cnt=0;
    cin>>a>>b>>x;
    if(a % x == 0){
        cout << b / x - a / x + 1 << endl;
    }
    else{
        cout << b / x - a / x << endl;
    }
    
    return 0;
}
