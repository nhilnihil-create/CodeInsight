#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i=s;i<n;i++)
#define MAX_N 20

long long calc(string s)
{
    int len = s.size();
    long long ans = stoll(s);
    
    rep(i,1,len)
    {
        string left = s.substr(0,i);
        string right = s.substr(i,len-1);
        ans += stoll(left) * pow(2,right.size()-1);
        ans += calc(right);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << calc(s) << endl;
}