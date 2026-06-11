#include <iostream>

using namespace std;

int main()
{
    long long A,B,C,D,a;
    cin>>A>>B>>C>>D;
    a=(A*B>=C*D)?A*B:C*D;
    cout<<a;
    return 0;
}
