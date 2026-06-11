#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    int d1=a+b, d2=a+c, d3=b+c;
    cout<<min(d3, min(d1, d2))<<endl;
    return 0;

}