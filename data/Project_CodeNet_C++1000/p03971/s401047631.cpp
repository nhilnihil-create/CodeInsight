#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
 
    vector<char> s(n);
    for(int i=0;i<n;i++)
        cin >> s.at(i);
 
    int c = 0, cb = 0;
 
    for(int i=0;i<n;i++) {
        if (s.at(i) == 'a') {
            if (c < (a + b)) {
                cout << "Yes" << endl;
                c++;
            } else {
                cout << "No" << endl;
            }
        } else if (s.at(i) == 'b') {
            if (c < (a + b) && cb < b) {
                cout << "Yes" << endl;
                c++;
                cb++;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    while(t--)
    {
        solve();
    }
}
