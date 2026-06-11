#include<bits/stdc++.h>
using namespace std;



int main(){

    long long a, b, x;
    cin>>a>>b>>x;
 
   cout<<(a%x==0 ?   b/x-a/x + 1 : b/x-a/x);
}
