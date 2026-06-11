#include<bits/stdc++.h>
using namespace std;
int main()
{
int A;
int B;
int C;
cin>>A;
cin>>B;
cin>>C;

if( A==B+C || B==A+C || C==A+B){
cout<<"Yes";
}
else{
cout<<"No";
}

return 0;
}

