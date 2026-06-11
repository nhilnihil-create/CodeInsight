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
	ll A,B;
    cin>>A>>B;
    if(A==B)cout<<"Draw";
    else if(A==1)cout<<"Alice";
    else if(B==1)cout<<"Bob";
    else if(A>B) cout<<"Alice";
    else if(A<B) cout<<"Bob";
	return 0;
}