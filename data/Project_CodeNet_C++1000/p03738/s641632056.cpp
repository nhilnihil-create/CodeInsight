#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;

    if (A == B)
    {
        cout << "EQUAL";
    }

    if (A.length() > B.length())
    {
        cout << "GREATER";
    }

    if (A.length() == B.length() && int(A[0]) > int(B[0]))
    {
        cout << "GREATER";
    }

    if (A.length() < B.length())
    {
        cout << "LESS";
    }

    if (A.length() == B.length() && int(A[0]) < int(B[0]))
    {
        cout << "LESS";
    }
}