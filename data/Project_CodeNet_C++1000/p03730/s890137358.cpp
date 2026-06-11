#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    if (c%gcd(a,b)==0){
        cout<<"YES";
    }
    else{cout<<"NO";}
    
}
