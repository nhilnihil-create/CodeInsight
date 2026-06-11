#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 
int main(){
    string a,b;
    cin>>a>>b;
    
    if(a=="H"&&b=="H"){cout<<"H";}
    else if(a=="H"&&b=="D"){cout<<"D";}
    else if(a=="D"&&b=="H"){cout<<"D";}
    else if(a=="D"&&b=="D") {cout<<"H";}
    return 0;
}