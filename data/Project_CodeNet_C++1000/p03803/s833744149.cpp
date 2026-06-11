#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B;
    cin >> A >> B;

    if(A==B)
        cout << "Draw";
    else if(A==1 || (B < A && B!=1))
        cout << "Alice";
    else
        cout << "Bob";
    
    cout << endl;
    return 0;
}