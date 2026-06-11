#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"Yes"<<endl; return 0;
#define NO cout<<"No"<<endl; return 0;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define pll pair <ll, ll>
#define setbiti(x) __builtin_popcount(x)
#define setbitll(x) __builtin_popcountll(x)
#define gcd(a, b) __gcd(a, b)

#define        MX        200005
int visited[200];
int main()
{
    optimize
    string str;
    cin>>str;

    for(int i = 0; i < str.size(); i++){
        visited[str[i]]++;
    }
    for(int i = 'a'; i <= 'z'; i++){
        if(visited[i] & 1){
            NO;
        }
    }
    YES;

}
