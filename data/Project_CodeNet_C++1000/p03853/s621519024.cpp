#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string s[102];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cout << s[i] << endl << s[i] << endl;
}
