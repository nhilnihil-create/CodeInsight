#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;

    unsigned long strSize = S.size();

    string result;
    for(unsigned long i = 0; i < strSize ; i = i +2)
    {
        result.push_back(S.at(i));
    }

    cout << result << endl;
    return 0;
}
