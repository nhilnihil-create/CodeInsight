#include <bits/stdc++.h>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L


typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string str;
    cin>>N>>str;
    int x=0;
    vector<int> vi;
    vi.pb(0);
    for(int i=0;i<str.size();++i){
        if(str[i]=='I'){
            x+=1;
            vi.pb(x);
        }
        else{
            x-=1;
            vi.pb(x);
        }
    }
    SORT(vi);
    cout<<vi[N];
    return 0;
}
