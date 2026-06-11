#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long> A(3);
    cin >> A.at(0) >> A.at(1) >> A.at(2);
    if(A.at(0)%2==0||A.at(1)%2==0||A.at(2)%2==0)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    long long chk=A.at(0)/2;
    cout << abs(A.at(1)*A.at(2)*chk-A.at(1)*A.at(2)*(A.at(0)-chk));
}
