#include <bits/stdc++.h>
using namespace std;

int A,B,C,D;

int main()
{
    cin>>A>>B>>C>>D;

    int t = 0;
    int s = max(A,C);
    int e = min(B,D);

    t = max(t,e-s);

    cout << t << endl;
}
