#include <iostream>
#include <string>

int main()
{
    using namespace std;
    
    long int a, b, x;
    cin >> a >> b >> x;

    auto solver = [](long a, long b, long x) -> long {
        return b/x - (a-1)/((a==0)? 1 : x);
    };

    cout << solver(a,b,x) << endl;
    return 0;
}
