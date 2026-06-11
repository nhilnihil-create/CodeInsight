//                                 Alisher_2211
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        # include <bits/stdc++.h>
# define  long          long long
# define  all(vc)       vc.begin(),vc.end()
# define  allr(vc)      vc.rbegin(),vc.rend()
# define  pb            push_back
# define  fi            first 
# define  se            second
# define  pi            pair <long, long>    
# define  lcm(a, b)     (a * b) / __gcd(a, b)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        using namespace std;
const long N = 100100;
void read(){freopen("input.txt" , "r" , stdin );freopen("output.txt", "w" , stdout );}
long dp[N][2];
string s;
void solve(){
    long n, m;
    cin >> n >> m;
    vector <pi> a(n), b(m);
    for (int i = 0; i < n; ++i){
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 0; i < m; ++i){
        cin >> b[i].fi >> b[i].se;
    }
    for (int i = 0; i < n; ++i){
        long mn = 1e9;
        vector < long > v;
        vector < pair < long, long > > vc;
        for (int j = 0; j < m; ++j){
            long q = abs(a[i].fi - b[j].fi) + abs(a[i].se - b[j].se);
            //cout << q << ' ';
            if( q < mn ){
                v.clear(), vc.clear();
                v.pb(j + 1), vc.pb({ b[i].fi, b[i].se });
                mn = q;
            }
            if( q == mn ){
                vc.pb({ b[i].fi, b[i].se });
                sort( all(vc) );
                if( vc[0].fi == b[i].fi && vc[0].se == b[i].se ){
                    vc.clear();
                    vc.pb({ b[i].fi, b[i].se });
                }
                else{
                    long f = vc[0].fi, g = vc[0].se;
                    vc.clear();
                    vc.pb({ f, g });   
                }
            }   

        }
        cout << v[0] << '\n';

    }
}
int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
        long T = 1;
        //cin >> T;
        while( T-- ){
            solve();
            cout<<'\n';
        }
cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}