#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long int LLI;

int main()
{
    string s;
    cin >> s;
    cout << s[0] << s.size()-2 << s[s.size()-1];
}