#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#define int long long int

using namespace std;



main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    cin>>N;
    vector<int> X(N);
    for(int i = 0; i < N; ++i)
    {
        cin>>X[i];
    }
    long long ans = 1;
    int mod = 1e9+7;
    int i = 0;
    int sum = 0;
    for(int step = 0; step < N; ++step)
    {
        while(i < N)
        {
            //out<<"A"<<i<<' '<<X[i]<<' '<<sum<<endl;
            if (2 * sum + 1 > X[i])
            {
                break;
            }
            sum++;
            i++;
        }

        //out<<i<<' '<<sum<<endl;
        ans *= (sum + (i != N));
        ans %= mod;
        sum -= 1;
    }
    cout<<ans%mod<<endl;
}
