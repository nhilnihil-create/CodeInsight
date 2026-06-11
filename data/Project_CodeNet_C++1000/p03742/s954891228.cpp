#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long x,y;
    cin>>x>>y;

    if(x+y<=1)
        cout<<"Brown\n";
    else if(abs(x-y)<=1)
        cout<<"Brown\n";
    else
        cout<<"Alice\n";
    return 0;
}
