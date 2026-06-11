//Code by ASIM FOIZE AIMON
//CSE'19;CUET
//avoid copy paste//Hit the frined button
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define precise cout.precision(10); cout << fixed;
#define endl "\n"
#define int int64_t
#define ll long long
#define yes printf("Yes\n")
#define no printf("No\n")
#define push_back pb
int32_t main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("/media/AIMON/SSDVol/Progs/CodeForces/input.txt", "r", stdin);
        freopen("/media/AIMON/SSDVol/Progs/CodeForces/output.txt", "w", stdout);
    #endif*/
    long long n,i,l;
    cin>>n>>l;
    vector<string>s(n);
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s.begin(),s.end());
    for(i=0;i<n;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}
