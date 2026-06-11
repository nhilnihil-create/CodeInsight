#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    int sum = 0;
    int num;
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += i;
        if (sum >= n) {
            num = sum-n;
            sum = i;
            break;
        }
    }

    for (int i = 1; i <= sum; i++) {
        if (i != num) {
            cout << i << endl;
        }
    }

    return (0);
}
