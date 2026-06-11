#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int A,B,C;
    cin >> A >> B >> C;
    int sum = max({A, B, C});
    cout << A+B+C-sum << endl;
}