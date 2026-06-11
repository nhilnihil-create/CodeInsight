#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n));

void fast() {

    cin.tie(0);
    cin.sync_with_stdio(0);
}

ll n, m;
int freq[26];

int main() {
    fast();
    string s;cin>>s;
    int left=-1,right=-1;
    for (int i = 0; i+2 < s.length(); ++i) {
        if(s[i]==s[i+1]){
            left=i+1,right=i+2;
            break;
        }
        if(s[i]==s[i+2]){
            left=i+1,right=i+3;
            break;

        }
    }
    if(s[s.size()-1]==s[s.size()-2])left=s.size()-1,right=s.size();
    cout<<left<<" "<<right;

}