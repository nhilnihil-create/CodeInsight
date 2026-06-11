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

long long int N,W,res=0,a[300200],b[200200];
long long int suml=0,sumr=0;
long long int sumrmemo[300200]={};
priority_queue<long long int,vector<long long int>,greater<long long int> >pql;
priority_queue<long long int>pqr;

int main(){
    cout << fixed << setprecision(18);
    cin>>N;
    for(long long int i = 0; i < 3*N; i++){
        cin>>a[i];
    }
    for(long long int i = 0; i < N; i++){
        pql.push(a[i]);
        pqr.push(a[2*N+i]);
        suml+=a[i];
        sumr+=a[2*N+i];
    }
    sumrmemo[2*N]=sumr;
    for(long long int i = 2*N-1; i >=N; i--){
        if(pqr.top()-a[i]>0){
            sumr+=a[i]-pqr.top();
            pqr.pop();
            pqr.push(a[i]);
           
        }
         sumrmemo[i]=sumr;
    }
    res=suml-sumrmemo[N];
    //DEBUG_OUTPUT_ARRAY(sumrmemo,10);
    for(long long int i = N; i < 2*N; i++){
        if(a[i]-pql.top()>0){
            suml+=a[i]-pql.top();
            pql.pop();
            pql.push(a[i]);
        }
        res=max(res,suml-sumrmemo[i+1]);
    }

    cout<<res<<endl;
}


