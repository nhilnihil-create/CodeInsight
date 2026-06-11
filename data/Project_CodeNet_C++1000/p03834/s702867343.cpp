#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define endll "\n"

#define fin             freopen("input.txt","r",stdin);
#define fout            freopen("output.txt","w",stdout);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]==','){
            cout << " ";
        }
        else cout << s[i];
    }
    cout << endl;

    return 0;
}

