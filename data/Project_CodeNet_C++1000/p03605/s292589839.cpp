#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long int;
int main()
{
    string N;
    cin >> N;
    cout << (N[0] == '9' || N[1] == '9' ? "Yes" : "No") << endl;
}