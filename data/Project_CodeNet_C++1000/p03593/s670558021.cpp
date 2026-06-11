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


long long  int H,W,K,A[200050],sum=0,res=0,num[200020]={};
long long int ten[7]={0,0,10,100,1000},t[100];

string s[505];
int main()
{
    cout << fixed << setprecision(18);
    
    cin>>H>>W;
    for(long long int i = 0; i < H; i++){
        cin>>s[i];
        for(long long int j = 0; j < W; j++){
            num[s[i][j]-'a']++;
        }
    }
    long long int nokori=H*W;
    for(long long int i = 0; i < 26; i++){
        if(num[i]>=4){
            nokori-=4*(num[i]/4);
            num[i]-=4*(num[i]/4);
        }
    }

    if(H%2==0&&W%2==0&&nokori!=0){
        cout<<"No"<<endl;
        return 0;
    }
    if((H%2==1&&W%2==0&&nokori>W||H%2==0&&W%2==1&&nokori>H)){
        cout<<"No"<<endl;
        return 0;
    }
    if(H%2==1&&W%2==1&&nokori>H+W-1){
        cout<<"No"<<endl;
        return 0;
    }
    for(long long int i = 0; i < 26; i++){
        if(num[i]>=2){
            nokori-=2*(num[i]/2);
        }
    }
    if((H%2==1&&W%2==0||H%2==0&&W%2==1)&&nokori!=0){
        cout<<"No"<<endl;
        return 0;
    }
    if(H%2==1&&W%2==1&&nokori!=1){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;

}
