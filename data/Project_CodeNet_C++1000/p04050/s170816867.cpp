#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    int x = 0;
    rep(i,m){
        cin >> a[i];
        if(a[i]%2==1)x++;
    }
    vector<int>b;
    if(n%2==0){
        if(x>2){
            cout << "Impossible" << endl;
            return 0;
        }
        if(x==2){
            if(m==2){
                if(a[0]==1&&a[1]==1){
                    cout << "1 1" << endl;
                    b.PB(2);
                }else{
                    cout << a[0] << " " << a[1] << endl;
                    b.PB(a[0]+1);
                    b.PB(n-a[0]-1);
                }
            }else{
                int s = -1;
                int t = -1;
                vector<int> c;
                rep(i,m){
                    if(a[i]%2==1){

                        if(s==-1){
                            s = a[i];
                        }else{
                            t = a[i];
                        }
                    }else{
                        c.PB(a[i]);
                    }
                }
                cout << s << " ";
                rep(i,c.size())cout << c[i] << " ";
                cout << t << endl;
                b.PB(s+1);
                rep(i,c.size()){
                    b.PB(c[i]);
                }
                if(t!=1){
                    b.PB(t-1);
                }
            }
        }
        if(x==0){
            if(m==1){
                cout << n << endl;
                b.PB(1);
                b.PB(n-1);
            }else{
                rep(i,m){
                    cout << a[i];
                    if(i!=m-1)cout << " ";
                }
                cout << endl;
                b.PB(1);
                rep(i,m){
                    b.PB(a[i]);
                }
                b[m]--;
            }
        }
    }
    if(n%2==1){
        if(x!=1){
            cout << "Impossible" << endl;
            return 0;
        }
        if(m==1){
            if(n==1){
                cout << 1 <<endl;
                cout << 1 << endl;
                cout << 1 << endl;
                return 0;
            }
            cout << n << endl;
            cout << 2 << endl;
            cout << 1 << " " << n-1 << endl;
            return 0;
        }
        vector<int> c;
        int s;
        rep(i,m){
            if(a[i]%2!=0){
                s = a[i];
            }else{
                c.PB(a[i]);
            }
        }
        cout << s << " ";
        rep(i,c.size())cout << c[i] << " ";
        cout << endl;
        b.PB(s+1);
        rep(i,c.size()){
            b.PB(c[i]);
        }
        b[b.size()-1]--;
    }
    cout << b.size() << endl;
    rep(i,b.size()){
        cout << b[i];
        if(i!=b.size()-1)cout << " ";
    }
    cout << endl;
    return 0;
}