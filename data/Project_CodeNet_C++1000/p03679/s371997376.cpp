#include<iostream>
using namespace std;
int main()
{
    long long int X,A,B;
    cin>>X>>A>>B;
    if(B<=A)
    {
        cout<<"delicious"<<endl;
    }
    else if(B>A && B<=(X+A))
    {
        cout<<"safe"<<endl;
    }
    else if(B>(X+A))
    {
        cout<<"dangerous"<<endl;
    }
    return 0;
}
