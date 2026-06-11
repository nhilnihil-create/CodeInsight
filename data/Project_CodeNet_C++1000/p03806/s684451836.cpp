#include <algorithm>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <type_traits>


using namespace std;
#define SAY_YES cout << "YES" << endl;
#define SAY_Yes cout << "Yes" << endl;
#define SAY_NO cout << "NO" << endl;
#define SAY_No cout << "No" << endl;
#define IFYES(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "YES" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << endl;  \
    }
#define IFYes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "Yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "No" << endl;  \
    }
#define IFyes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "no" << endl;  \
    }
#define DEBUG_OUTPUT_ARRAY(XXX, ONE)                            \
    for (int i = 0; i < (ONE); i++)                             \
    {                                                           \
        cout << "DEBUG: i = " << i << " -> " << XXX[i] << endl; \
    }
#define DEBUG_OUTPUT_ARRAY2(XXX, ONE, TWO)                             \
    for (int i = 0; i < (ONE); i++)                                    \
    {                                                                  \
        cout << "<<< i = " << i << " >>>" << endl;                     \
        for (int j = 0; j < (TWO); j++)                                \
        {                                                              \
            cout << "DEBUG: j = " << j << " -> " << XXX[i][j] << endl; \
        }                                                              \
    }
#define DEBUG_OUTPUT_ARRAY2_BOX(XXX, ONE, TWO) \
    for (int i = 0; i < (ONE); i++)            \
    {                                          \
        cout << i << "  ";                     \
        for (int j = 0; j < (TWO); j++)        \
        {                                      \
            cout << XXX[i][j] << " ";          \
        }                                      \
        cout << endl;                          \
    }

typedef pair<long long int, long long int> pll;


const long long int mod = 1000000007;
const long long int INF = 1e18;
const long double PI=3.14159265358979323; 


long long int N,Ma,Mb,a[100],b[100],c[100],res=INF;
long long int cost[405][405]={};

int main()
{
    cout << fixed << setprecision(18);
    cin>>N>>Ma>>Mb;

    for(long long int i = 0; i < N; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(long long int i = 0; i <= 400; i++){
        for(long long int j = 0; j <= 400; j++){
            cost[i][j]=INF;
        }
    }

    for(long long int i = 0; i < (1<<(N/2)); i++){
        long long int ma=0,mb=0,co=0;
        for(long long int j = 0; j < N/2; j++){
            if((i&(1<<j))!=0){
                ma+=a[j];
                mb+=b[j];
                co+=c[j];
            }
        }
        cost[ma][mb]=min(cost[ma][mb],co);

    }
    
    long long int tyousei=N/2;
    for(long long int i = 0; i < (1<<N-tyousei); i++){
        long long int ma=0,mb=0,co=0;
        for(long long int j = 0; j < N-tyousei; j++){
            if((i&(1<<j))!=0){
                ma+=a[j+tyousei];
                mb+=b[j+tyousei];
                co+=c[j+tyousei];
            }
        }
        long long int tmpMa=Ma,tmpMb=Mb;
        for(long long int i = 1; i*max(Ma,Mb) <= 400; i++){
            if(i*Ma<ma||i*Mb<mb){continue;}
            res=min(res,co+cost[i*Ma-ma][i*Mb-mb]);
        }

    }
    if(res==INF){res=-1;}
    cout<<res<<endl;

}    
