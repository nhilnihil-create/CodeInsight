 #include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;
typedef long double ld;
typedef vector<int> vr;
typedef pair<int, int> pr;
#define pb push_back
#define ff first
#define ss second
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433
#define endl "\n"
//cout << fixed << setprecision(2);

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    string r = s;
    reverse(r.begin(), r.end());
    //cout << "s " << s << endl;
    //cout << "r " << r << endl;
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(r[i] == 'b'){
            r[i] = 'd';
        }
        else if(r[i] == 'd'){
            r[i] = 'b';
        }
        else if(r[i] == 'p'){
            r[i] = 'q';
        }
        else if(r[i] == 'q'){
            r[i] = 'p';
        }
    }

    //cout << "s " << s << endl;
    //cout << "r " << r << endl;
    if(s == r){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}

