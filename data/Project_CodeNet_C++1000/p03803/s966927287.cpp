//Bismillahir Rahmanir Rahim
#include <iostream>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if((a == b)) {
        cout<<"Draw\n";
    }
    else if((a == 1) || (a > b && b != 1)){
        cout<<"Alice\n";
    }
    else if((b == 1) || (b > a && a != 1) ) {
        cout<<"Bob\n";
    }

    return 0;
}