/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

/*  Macros from Endagorion */
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


int main(){
        
    ios_base::sync_with_stdio(0);
    
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    int w,h,n;
    cin>>w>>h>>n;
    int rec[w][h];
    forn(i,w){
        forn(j,h){
            rec[i][j]=0;
        }
    }
    int area = h*w;
    forn(i,n){
        int x,y,a;
        cin>>x>>y>>a;
        //x--,y--;
        if(a==1){
            forn(j,x){
                forn(k,h){
                    if(rec[j][k]==0){
                        rec[j][k] = 1;
                        area--;
                    }
                }
            }
        }
        else if(a==2){
            for(int j=x;j<w;j++){
                forn(k,h){
                    if(rec[j][k]==0){
                        rec[j][k] = 1;
                        area--;
                    }
                }
            }
        }
        else if(a==3){
            forn(j,w){
                forn(k,y){
                    if(rec[j][k]==0){
                        rec[j][k] = 1;
                        area--;
                    }
                }
            }
        }
        else{
            forn(j,w){
                for(int k=y;k<h;k++){
                    if(rec[j][k]==0){
                        rec[j][k] = 1;
                        area--;
                    }
                }
            }
        }
    }
    /*
    forn(i,w){
        forn(j,h){
            cout<<rec[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    cout<<area<<endl;
    return 0;
}

