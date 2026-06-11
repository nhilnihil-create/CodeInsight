#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    int set = 2;
    cin >> N;

    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1 ; i < 7 ; i++){
        if (set <= N && set * 2 > N)
        {
            cout << set << endl;
            return 0;
        }
        set = set * 2;
    }

        
}
