#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
long long t[10];
int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    if((a%2 == 0)||(b%2 == 0)||(c%2 == 0)){
        cout<<"0"<<endl;
        return 0;
    }
    t[1] = a*b; t[2] = a*c; t[3] = b*c;
    long long ans = t[1];
    if(ans > t[2]) ans = t[2];
    if(ans > t[3]) ans = t[3];
    cout<<ans<<endl;
    return 0; 
}