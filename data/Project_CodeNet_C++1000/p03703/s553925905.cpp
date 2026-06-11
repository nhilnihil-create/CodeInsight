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

long long int K,N,M,x,y,res=0,tmp[200200]={},a[200200],sum[200200]={};
pll ba[200200];
map<long long int,long long int>mp;




//セグメント木
class SegmentTree{
    public:
	long long int dataSize,identityElement;
	pair<long long int,long long int>* treeDataRange;
	long long int* treeData;

	//要素数nと単位元e
	SegmentTree(long long int n,long long int e){
		dataSize=2;
		while(dataSize<n){
			dataSize*=2;
		}
		identityElement=e;
		treeData=new long long int [2*dataSize+1];
		treeDataRange=new pair<long long int,long long int> [2*dataSize+1];
		for(int i=dataSize;i<2*dataSize;i++){
			treeDataRange[i]={i-dataSize,i-dataSize+1};
		}
		for(int i=dataSize-1;i>=1;i--){
			treeDataRange[i]={treeDataRange[2*i].first,treeDataRange[2*i+1].second};
		}
		for(int i=1;i<2*dataSize;i++){
			treeData[i]=e;
		}
	}

    long long int DataChange(long long int id,long long int data){
        treeData[id+dataSize]=data;
        DataChangeLoop((id+dataSize)/2);
		return 0;
    }
    long long int DataChangeLoop(long long int id){
        treeData[id]=Calculation(treeData[2*id],treeData[2*id+1]);
        if(id==1){return 0;}
        DataChangeLoop(id/2);
    }

	long long int Calculation(long long int x,long long int y){
		return x+y;
	}
	//[l,r)の結果を出力
	long long int OutPut(long long int l,long long int r){
		return OutPutLoop(1,l,r);
	}
	
	long long int OutPutLoop(long long int now,long long int l,long long int r){
		
		if(l>=r){return identityElement;}

        if(l==treeDataRange[now].first&&r==treeDataRange[now].second){return treeData[now];}

		return Calculation(OutPutLoop(2*now,l,min(treeDataRange[2*now].second,r)),OutPutLoop(2*now+1,max(treeDataRange[2*now+1].first,l),r));
		
	}
};

int main(){
    cout << fixed << setprecision(18);
    cin>>N>>K;
    for(long long int i = 1; i <= N; i++){
        cin>>a[i];
        a[i]-=K;
        sum[i]=sum[i-1]+a[i];
        tmp[i]=sum[i];
    }
    
    sort(tmp,tmp+N+1);
    
    //DEBUG_OUTPUT_ARRAY(tmp,N+1);
    long long int now=0;
    for(long long int i = 0; i <= N; i++){
        if(i==0||tmp[i]!=tmp[i-1]){
            mp[tmp[i]]=now;
            now++;
        }
    }
    now--;
    //DEBUG_OUTPUT_ARRAY(sum,N+1);
    for(long long int i = 0; i <= N; i++){
        sum[i]=mp[sum[i]];
    }
    //DEBUG_OUTPUT_ARRAY(sum,N+1);
    SegmentTree SEG(200200,0);
    for(long long int i = 0; i <=N; i++){
        res+=SEG.OutPut(0,sum[i]+1);
        SEG.DataChange(sum[i],SEG.OutPut(sum[i],sum[i]+1)+1);
        //cout<<res<<endl;
    }
    cout<<res<<endl;
}


