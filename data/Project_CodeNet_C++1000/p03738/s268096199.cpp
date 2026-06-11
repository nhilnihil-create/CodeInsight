#include <iostream>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;

    string result;
    if(A.size() > B.size())
    {
        result = "GREATER";
        cout << result << endl;
        return 0;
    }
    else if (A.size() < B.size())
    {
        result = "LESS";
        cout << result << endl;
        return 0;
    }

    if(std::string(A) > std::string(B))
    {
        result = "GREATER";
        cout << result << endl;
        return 0;
    }
    else if (std::string(A) < std::string(B))
    {
        result = "LESS";
        cout << result << endl;
        return 0;
    }
    else {
        result = "EQUAL";
        cout << result << endl;
        return 0;
    }
}
