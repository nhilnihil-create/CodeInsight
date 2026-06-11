#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    map<int,int>mp;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
     mp[s[i]]=1;
    for(int i='a';i<='z';i++){
        if(mp[i]==0){
            cout<<(char)i<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}
