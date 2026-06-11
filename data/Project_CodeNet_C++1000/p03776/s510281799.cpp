
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
#include <locale>
#include <omp.h>

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
typedef pair<long long int, pll> lpll;

const long long int mod = 1000000007;
const long long int INF = 1e18;
const long double PI=3.14159265358979323; 
//const long long int pl=1000000;

long long int C[100][100]={};
long long int N,res=0,A,B,v[55],sum=0,cou=0,cou2=0;
bool AllSame=true;

string S[105];
int main(){
    cout << fixed << setprecision(18);
    cin>>N>>A>>B;
    for(long long int i = 0; i <= N; i++){
        C[i][i]=1;
        C[i][0]=1;
    }
    for(long long int i = 2; i <= N; i++){
        for(long long int j = 1; j <= N-1; j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    for(long long int i = 0; i < N; i++){
        cin>>v[i];
    }
    sort(v,v+N);
    for(long long int i = N-A; i < N; i++){
        sum+=v[i];
    }
    cout<<(long double)sum/(long double)(A)<<endl;
    if(sum==A*v[N-A]){
        for(long long int i = 0; i < N; i++){
            if(v[N-A]==v[i]){
                cou++;
            }
        }
        for(long long int i = A; i <= min(B,cou); i++){
            res+=C[cou][i];
        }
        cout<<res<<endl;
    }else{
        for(long long int i = 0; i < N; i++){
            if(v[N-A]==v[i]){
                cou++;
            }
        }
        for(long long int i = N-A; i < N; i++){
            if(v[N-A]==v[i]){
                cou2++;
            }
        }
        res+=C[cou][cou2];
        
        cout<<res<<endl;
    }
}

