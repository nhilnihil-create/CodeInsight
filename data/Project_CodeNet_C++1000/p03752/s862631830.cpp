#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
#include<set>
 
using namespace std;
#define SAY_YES cout<<"YES"<<endl;
#define SAY_Yes cout<<"Yes"<<endl;
#define SAY_NO cout<<"NO"<<endl;
#define SAY_No cout<<"No"<<endl;
#define IFYES(TRUE_OR_FALSE) if(TRUE_OR_FALSE){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;} 
#define IFYes(TRUE_OR_FALSE) if(TRUE_OR_FALSE){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;} 
#define IFyes(TRUE_OR_FALSE) if(TRUE_OR_FALSE){cout<<"yes"<<endl;}else{cout<<"no"<<endl;} 
#define DEBUG_OUTPUT_ARRAY(XXX,ONE) for(int i=0;i<(ONE);i++){cout<<"DEBUG: i = "<<i<<" -> "<<XXX[i]<<endl;}
#define DEBUG_OUTPUT_ARRAY2(XXX,ONE,TWO) for(int i=0;i<(ONE);i++){cout<<"<<< i = "<<i<<" >>>"<<endl;for(int j=0;j<(TWO);j++){cout<<"DEBUG: j = "<<j<<" -> "<<XXX[i][j]<<endl; } }
#define DEBUG_OUTPUT_ARRAY2_BOX(XXX,ONE,TWO) for(int i=0;i<(ONE);i++){cout<<i<<"  ";for(int j=0;j<(TWO);j++){cout<<XXX[i][j]<<" "; } cout<<endl;}
 
typedef pair<long long int,long long int> pll;
 
 
const long long int mod=1000000007;
const long long int INF=99999999999999999;
 
long long int N,K,a[105],res=INF;
int main() {
	cout << fixed << setprecision(18);
    cin>>N>>K;
    for(int i=0;i<N;i++){cin>>a[i];}
    for(int i=0;i<(1<<N-1);i++){
        long long int tmp=1,mymax=a[0],money=0;
        for(int j=0;j<N-1;j++){
            if(((1<<j)&i)==0){
                if(mymax>=a[j+1]){
                    money+=(-a[j+1]+mymax)+1;
                    mymax++;
                }
                tmp++;
            }else if(mymax<a[j+1]){
                tmp++;
            }
            mymax=max(mymax,a[j+1]);
        }
        if(tmp>=K){res=min(res,money);}
    }
    cout<<res<<endl;
} 