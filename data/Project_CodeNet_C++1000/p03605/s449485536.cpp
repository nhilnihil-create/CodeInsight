#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    string st="No";
    cin >>num;
    if(num/10 == 9) st="Yes";
    if(num%10 == 9) st="Yes";
    cout << st << endl;
    return 0;
}

