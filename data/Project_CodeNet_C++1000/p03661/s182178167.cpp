#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int N;
    cin >> N;
    vector<int> a;
    for(int i=0;i<N;++i)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }

    vector<long long> b;
    b.push_back(a[0]);

    for(int i=1;i<N;++i)
    {
        b.push_back(b[i-1]+a[i]);
    }

    long long x,y,m=9e18;
    for(int i=0;i<N-1;++i)
    {
        x=b[i];
        y=b[N-1]-x;
        if(abs(x-y)<m)
            m=abs(x-y);
    }
    cout << m;



	return 0;
}
