#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string A,B,C;
    cin>>A>>B>>C;
    char S=A[0]-('a'-'A');
    char S1=B[0]-('a'-'A');
    char S2=C[0]-('a'-'A');
    cout<<S<<S1<<S2<<endl;
    return 0;

}
