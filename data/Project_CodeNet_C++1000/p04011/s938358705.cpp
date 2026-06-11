#include <bits/stdc++.h>

using namespace std;




int main(void)
{
    int N,K,X,Y,ans;

    cin>>N>>K>>X>>Y;

    ans=min(N,K)*X+max(N-K,0)*Y;

    cout<<ans<<endl;

	return 0;
}
