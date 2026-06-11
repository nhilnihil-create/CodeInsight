#include<iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    int sum1 = a + b;
    int sum2 = b + c;
    int sum3 = c + a;
    int m = min(sum1, sum2);
    m = min(m, sum3);
    cout<<m<<endl;
    return 0;
}
