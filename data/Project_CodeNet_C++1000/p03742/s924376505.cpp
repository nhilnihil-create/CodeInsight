#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int ,int > P;

int main()
{

long long  x , y;
    for(;cin >> x >> y;)
    {
        if( abs(x - y) <= 1)
            cout << "Brown" <<endl;
        else
            cout << "Alice" <<endl;
    }
}
