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

long long int level[100]={1};
long long int pate[100]={1};
long long int X,Ma,Mb,N,sum=0,res=INF,a[1005],b[1005],c[1005];
long long int dp[1005][10000];
long long int used[500][500]={};
pll key[1005];
string str[1234];
int main()
{
    cout << fixed << setprecision(18);
    cin>>N>>Ma>>Mb;
    for(long long int i = 0; i < N; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(long long int i = 0; i <= 450; i++){
        for(long long int j = 0; j <= 450; j++){
            used[i][j]=INF;
        }
    }
    used[0][0]=0;
    for(long long int i = 0; i < (1<<(N/2)); i++){
        long long int asum=0,bsum=0,csum=0;
        for(long long int j = 0; j < N/2; j++){
            if(((1<<j)&i)!=0){
                asum+=a[j];
                bsum+=b[j];
                csum+=c[j];
            }
        }
        used[asum][bsum]=min(used[asum][bsum],csum);
    }
    for(long long int i = 0; i < (1<<( (N+1) /2) ); i++){
        long long int asum=0,bsum=0,csum=0,add=N/2;
        for(long long int j = 0; j < (N+1)/2; j++){
            if(((1<<j)&i)!=0){
                asum+=a[j+add];
                bsum+=b[j+add];
                csum+=c[j+add];
            }
        }
        //cout<<asum<<" "<<bsum<<endl;
        for(long long int j = 1; max(j*Ma,j*Mb) <= 400; j++){
            if(j*Ma<asum||j*Mb<bsum){continue;}
            res=min(res,used[j*Ma-asum][j*Mb-bsum]+csum);
        }
    }
    if(res==INF){res=-1;}
    cout<<res<<endl;
}
