#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<string>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;
#define Mohamed_Gad fast()
#define ll long long
#define ull unsigned long long
#define all(v) v.begin(),v.end()
#define endl "\n"
#define sz(x) size(x)
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Open()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
#endif

}
//long long frq[100009],prf[100009];

int main() {
    fast();
     multiset<int>s;
     int n,a,sum=0;
     cin>>n;
     for(int i=0;i<2*n;i++){
        cin>>a;
        s.insert(a);
     }
     multiset<int>::iterator it=s.begin();
     for(it;it!=s.end();it++){
        sum+=*it;
        it++;
     }
   cout<<sum<<endl;

}
