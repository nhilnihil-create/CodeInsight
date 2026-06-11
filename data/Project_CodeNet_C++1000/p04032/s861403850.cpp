//#pragma GCC optimize(\"Ofast,no-stack-protector\")
//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx\")
//#pragma GCC target(\"avx,tune=native\")
// Neil

#include<bits/stdc++.h>

using namespace std;

typedef complex<double> base;
typedef long double ld;
typedef long long ll;

#define endl "\n"
#define pb push_back
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define vvi vector< vi >
const int MAXN=(int)(2e5+5);
const ll MOD=(ll)(1e9+7);
int t;
int dct[26];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str;
    cin>>str;
    bool fl = 0;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]==str[i+1]){
            cout<<i+1<<" "<<i+2<<endl;
            fl = 1;
            break;
        }
    }
    if(!fl){
        for(int i=2;i<str.size();i++){
            memset(dct, 0, sizeof(dct));
            for(int j = i-2;j<=i;j++){
                dct[str[j]-'a']++;
            }
            for(int j=0;j<26;j++){
                if(dct[j]==2){
                    fl = 1;
                    cout<<i-1<<" "<<i+1<<endl;
                    break;
                }
            }
            if(fl==1)
                break;
        }
    }
    if(fl==0)
        cout<<-1<<" "<<-1<<endl;
    return 0;
}