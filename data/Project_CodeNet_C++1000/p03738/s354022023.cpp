#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A,B;
    cin >> A >> B;

    if(A.size() < B.size()) cout << "LESS";
    else if(B.size() < A.size()) cout << "GREATER";
    else
    {
        if(A < B) cout << "LESS";
        else if(B < A) cout << "GREATER";
        else cout << "EQUAL";   
    }
    
    cout << endl;
    return 0;
}