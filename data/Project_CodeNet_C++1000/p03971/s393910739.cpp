#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int temp = a + b;
    for (int i = 0; i < (int)s.length(); i++){

        if (s[i] == 'a' && temp > 0) {
            cout << "Yes" << endl;
            temp--;
        }
        else if (s[i] == 'b' && temp > 0 && b > 0) {
            cout << "Yes" << endl;
            temp--;
            b--;
        }
        else cout << "No" << endl;
    }
    return 0;
}
