#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) x.begin(),x.end()
#define ceil(n, m) ((n / m) + ( n % m ? 1 : 0))
#define fast_IO  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file_in freopen("input.txt","r",stdin);
#define file_out freopen("output.txt","w",stdout);
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

int main(){
    //fast_IO;

    int a,b,c;
    cin >> a >> b >> c;
    if((a==5&&b==5&&c==7)||(a==5&&b==7&&c==5)||(a==7&&b==5&&c==5))
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
