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

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>>str;
    REVERSE(str);
    for(int i=0;i<4;++i){
        REVERSE(divide[i]);
    }
    bool flag=1;
    for(int i=0;i<str.size();){
        bool flag2=0;
        for(int j=0;j<4;++j){
            if(str.substr(i,divide[j].size())==divide[j]){
                flag2=1;
                i+=divide[j].size();
            }
        }
        if(!flag2){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}

