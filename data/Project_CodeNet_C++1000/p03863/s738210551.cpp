#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

string S;

int main()
{
	cin>>S;
	bool a=S.length()%2==0;
	bool b=S[0]==S[S.length()-1];
	cout<<(a^b?"Second":"First")<<endl;
}
