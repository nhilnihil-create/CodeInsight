#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define ceil(n, m) ((n / m) + ( n % m ? 1 : 0))
#define fast_IO  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file_in freopen("input.txt","r",stdin);
#define file_out freopen("output.txt","w",stdout);
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

int main(){
    //fast_IO;

    string s;
    cin >> s;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='B'){
            s[i]=' ';
            bool f = 1;
            for(int j=i-1;j>=0 && f;j--){
                    if(s[j]!=' ')
                        s[j] = ' ',f=0;
            }
        }
    }
    for(int i=0;i<(int)s.size();i++)
        if(s[i]!=' ') cout<<s[i];
    return 0;
}
