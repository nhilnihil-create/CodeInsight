#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i=0;i<N;i++)
    {
        cin >> A.at(i);
    }

    int counter = 0;

    for(int i=0;i<N;i++)
    {
        int j=A.at(i);
        if(A.at(j-1)==i+1)
        {
            counter++;
        }
    }

    cout << counter / 2 << endl;

    return 0;
}