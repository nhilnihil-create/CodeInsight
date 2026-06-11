#include <bits/stdc++.h>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))

typedef long long ll;

string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>s;
    int ans=0;
    for(int i=0;i<s.size()-1;++i){
        if(s[i]!=s[i+1])ans++;
    }
    cout<<ans;

    return 0;
}
