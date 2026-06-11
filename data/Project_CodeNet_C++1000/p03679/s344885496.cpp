#include <iostream>
using namespace std;
int main()
{
    long long X, A, B;
    cin>>X>>A>>B;
    if(A-B>=0) cout<<"delicious"<<endl;
    else if(A-B>=-X) cout<<"safe"<<endl;
    else cout<<"dangerous"<<endl;

    return 0;
}