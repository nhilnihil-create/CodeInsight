#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin>>n;

    long long x = (-1+sqrt(8*n+1))/2;

    if((x*(x+1))/2 < n)
        cout<<x+1;
    else
    {
        cout<<x;
    }
    

}