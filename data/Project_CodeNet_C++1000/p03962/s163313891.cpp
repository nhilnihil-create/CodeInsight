#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
 

int main(){
	VL A(3);
    cin>>A[0]>>A[1]>>A[2];
    sort(A.begin(),A.end());
    if(A[0]==A[1]&&A[1]==A[2])cout<<1;
    else if((A[0]!=A[1]&&A[1]==A[2])||(A[1]!=A[2]&&A[0]==A[1]))cout<<2;
    else cout<<3;
    return 0;
}