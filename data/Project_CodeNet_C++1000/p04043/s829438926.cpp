#include<iostream>
using namespace std;
int main()
{
    int a,b,c,count=0;

    cin >> a >> b >> c;

    if(a==7)
        count++;
    if(b==7)
        count++;
    if(c==7)
        count++;

    if(count>=2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
