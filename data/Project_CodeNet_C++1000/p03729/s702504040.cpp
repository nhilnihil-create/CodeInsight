#include <bits/stdc++.h>
#include <math.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;
const int mINF = -1001001001;


int main() {
char a[10],b[10],c[10];
cin >> a >> b >> c;
int a_num = strlen(a);
int b_num = strlen(b);
string ans ="NO";
if(a[a_num-1]==b[0]&&b[b_num-1]==c[0]) ans="YES";
cout << ans << endl;
return 0;
}
