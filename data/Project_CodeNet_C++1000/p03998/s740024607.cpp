#include <bits/stdc++.h>

using namespace std;

#define vit vector<int>::iterator
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fr first
#define sc second
#define skip continue
#define PI 3.14159265

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;

const int INF = 1e9 + 5;
const long long MAXN=2e5 + 5;;

void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(const string& a, const string& b) {
	return (a + b) < (b + a);
}

vector<int> Reversed(const vector<int>& s){
   vector<int> d = s;
   reverse(all(d));
   return d;
}

void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    int sa = a.size(), sb = b.size(), sc = c.size(), i = 1, j = 0, k = 0;
    char ch = a[0];
    while(1){
        if(ch == 'a'){
            if(i == sa){
                cout << 'A';
                return;
            }
            ch = a[i];
            i++;
            continue;
        }
        if(ch == 'b'){
            if(j == sb){
                cout << 'B';
                return;
            }
            ch = b[j];
            j++;
            continue;
        }
        if(ch == 'c'){
            if(k == sc){
                cout << 'C';
                return;
            }
            ch = c[k];
            k++;
            continue;
        }
    }
}


int main(){
    //freopen("slalom.in","r",stdin);
    //freopen("slalom.out","w",stdout);
    //faster();
    int n = 1;
    //cin >> n;
    while(n--){
        solve();
        cout << endl;
    }
    //fclose(stdout);
}
