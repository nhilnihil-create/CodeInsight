#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
 
int main(){
	string a, b, c;
	cin >> a >> b >> c;
	char dif ='A'-'a';
    cout<<(char)(a[0]+dif)
        <<(char)(b[0]+dif)
        <<(char)(c[0]+dif)<<endl;
	return 0;
}