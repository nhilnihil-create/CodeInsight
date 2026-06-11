#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1000000007;
const double PI = 3.141592653589793238463;
const ll N=2e5+9;
int main()
{
    FASTINOUT;
    map<int,int>m;
    int x,y,c=0,l=0;
    cin>>x;
    for (int i=0;i<x;i++){
        cin>>y;
        if (!m[y]){
            c++;
            m[y]=1;
        }
        else{
            l++;
        }
    }
    cout<<(l%2==0?c:c-1);
    return 0;
}
