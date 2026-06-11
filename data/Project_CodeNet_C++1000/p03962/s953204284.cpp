#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;
    cin>>a>>b>>c;

    set<int> nums;

    nums.insert(a);
    nums.insert(b);
    nums.insert(c);

    cout<<nums.size()<<"\n";

    return 0;
}
