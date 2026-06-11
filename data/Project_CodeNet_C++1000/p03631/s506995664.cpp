#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    cin >> N;
    bool isYes = true;

    for(int i=0; i<N.size()/2; i++)
    {
        if(N[i]!=N[N.size()-i-1]) isYes = false; 
    }

    if(isYes) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}