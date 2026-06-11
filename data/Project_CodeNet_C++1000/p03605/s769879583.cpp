#include<bits/stdc++.h>
using namespace std;

main() {
    int N,x;
    cin>>N;
    x=N%10;
    if(x==9)
        cout<<"Yes";
    else if(N>=90 && N<100)
        cout<<"Yes";
    else
        cout<<"No";
}
