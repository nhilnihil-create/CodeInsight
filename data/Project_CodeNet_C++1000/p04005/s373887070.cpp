#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long int> block(3);
    for(int i=0; i<3; i++)
        cin >> block.at(i);
    sort(block.begin(),block.end());
    if(block.at(0)%2==0 || block.at(1)%2==0 || block.at(2)%2==0)
        cout << 0 << endl;
    else
        cout << block.at(0)*block.at(1) << endl;
    return 0;
}
