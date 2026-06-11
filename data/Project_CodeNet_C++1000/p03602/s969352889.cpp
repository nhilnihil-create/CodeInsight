#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <istream>
#define INF 2147483647
#define LLINF 9223372036854775807
typedef long long ll;
using namespace std;
int a[310][310];
bool vis[310][310];
int main(){//kij
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int k=1;k<=n;k++)      
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(k!=j&&k!=i&&i!=j){
                    if(a[i][j]==a[i][k]+a[k][j])vis[i][j]=1;
                    if(a[i][j]>a[i][k]+a[k][j]){
                        cout<<"-1"<<endl;
                        return 0;
                    }
                }
            }
	long long cnt=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(!vis[i][j])cnt+=a[i][j];
		}
	}
	cout<<cnt/2<<endl;
	return 0;
}