#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll a, b;

int main()
{
    cin>>a>>b;
    if(max(a - b, b - a) < 2) cout<<"Brown"<<endl;
    else cout<<"Alice"<<endl;
    return 0;
}
