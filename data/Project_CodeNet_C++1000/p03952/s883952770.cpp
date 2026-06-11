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

long long int N,M,A[200200]={},res=0,cou=0,num=3;
string S;
int main()
{
    cout << fixed << setprecision(18);
	
    cin>>N>>M;
	if(N==2&&M==2){
		cout<<"Yes"<<endl;
		cout<<1<<endl<<2<<endl<<3<<endl;
		return 0;
	}else if(M==2){
		cout<<"Yes"<<endl;
		A[(2*N-2)/2]=1;
		A[(2*N-2)/2+1]=2;
		A[(2*N-2)/2+2]=3;
		num=4;
		for(long long int i = 0; i < (2*N-2)/2; i++){
			A[i]=num;
			num++;
		}

		for(long long int i = (2*N-2)/2+3; i < 2*N-1; i++){
			A[i]=num;
			num++;
		}
		for(long long int i = 0; i < 2*N-1; i++){
			cout<<A[i]<<endl;
		}
	}else if(M==2*N-2){
		cout<<"Yes"<<endl;
		A[(2*N-2)/2]=2*N-1;
		A[(2*N-2)/2+1]=2*N-2;
		A[(2*N-2)/2+2]=2*N-3;
		num=1;
		for(long long int i = 0; i < (2*N-2)/2; i++){
			A[i]=num;
			num++;
		}

		for(long long int i = (2*N-2)/2+3; i < 2*N-1; i++){
			A[i]=num;
			num++;
		}
		for(long long int i = 0; i < 2*N-1; i++){
			cout<<A[i]<<endl;
		}
	}else if(2*N-3>=M&&M>=3){
		cout<<"Yes"<<endl;
		A[(2*N-2)/2]=M;
		A[(2*N-2)/2+1]=2*N-1;
		A[(2*N-2)/2-2]=2*N-2;
		A[(2*N-2)/2+2]=1;
		A[(2*N-2)/2-1]=2;
		
		for(long long int i = 0; i < (2*N-2)/2-2; i++){
			if(num==M){num++;}
			A[i]=num;
			num++;
		}

		for(long long int i = (2*N-2)/2+3; i < 2*N-1; i++){
			if(num==M){num++;}
			A[i]=num;
			num++;
		}
		for(long long int i = 0; i < 2*N-1; i++){
			cout<<A[i]<<endl;
		}
	}else{
		cout<<"No"<<endl;
	}
}
