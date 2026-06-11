#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 
int main(){
    int A,B,C,D;
    int rec1,rec2;
    cin>>A>>B>>C>>D;
    rec1=A*B;rec2=C*D;
    if(rec1>rec2){cout<<rec1;}
    else{cout<<rec2;}
}