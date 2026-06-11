#include <iostream>

using namespace std;

int main()
{
    string N;
    cin >> N;
    int num = stoi(N);
    int sum = (1 + num)* num / 2;
    cout << sum << endl;

}