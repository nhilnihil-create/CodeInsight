#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define pi  3.14159265359
#define mod 1000000007


bool chekeven(string x)
{
    int len=x.size();
    for(int i=0;i<len/2;i++)
    {
        if(x[i]!=x[i+len/2]){
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin>>str;
    str.pop_back();
    for(int i=str.size()-1;i>=1;i--)
    {
        if(chekeven(str)&&str.size()%2==0){
            cout<<str.size()<<endl;
            break;
        }
       str.pop_back();
    }


}
