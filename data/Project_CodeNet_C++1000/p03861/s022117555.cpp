#include <iostream>
#include <string>

int main()
{
    using namespace std;
    
    long int a, b, x;
    cin >> a >> b >> x;

    auto solver = [](long a, long b, long x){
        long int cnt = b/x;
        if(a==0)
            cnt += 1;
        else
            cnt -= (a-1)/x;
        return cnt;
    };

    cout << solver(a,b,x) << endl;
    return 0;
}
