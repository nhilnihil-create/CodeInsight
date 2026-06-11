#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    if(C>B)
        cout<<"0"<<endl;
else if(A>D)
cout<<"0"<<endl;
    else
    {
        cout<<min(B,D)-max(A,C)<<endl;
    }

}
