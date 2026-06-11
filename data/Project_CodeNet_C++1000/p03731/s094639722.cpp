#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    long long int N, T, X = 0; cin >> N >> T;
    vector<long long int> t(N, 0);
    for(long long int i=0; i<N; i++)
    {
        cin >> t[i];
    }
    X = 0;
    for(long long int i=1; i<t.size(); i++)
    {
        long long int temp = t[i]-t[i-1];
        if ( temp <= T) X += temp;
        else X += T;
    }

    X += T;

    cout << X << endl;
    
    return 0;
}