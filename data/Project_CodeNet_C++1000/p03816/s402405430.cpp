#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
map<int,int>mp;
vector<int>vec;

int n;
cin >> n;
for(int i=0; i<n; i++)
{
    int val;
    cin >> val;
    if(!mp[val])
        vec.push_back(val);
    mp[val]++;
}

int cnt = 0;
for(int i=0; i<vec.size(); i++)
{
    if(mp[vec[i]]%2==1)
        mp[vec[i]] = 1;
    else mp[vec[i]] = 2,cnt++;
}

//cout << cnt << endl;
if(cnt%2==0)
    cout << vec.size() << endl;
else
{
    cout << vec.size() - 1 << endl;
}


}
