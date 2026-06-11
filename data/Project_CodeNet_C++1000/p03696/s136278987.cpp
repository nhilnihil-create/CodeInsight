#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output_tate(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output_yoko(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}

int MOD = pow(10, 9) + 7;

int kaijou(int n){
    if(n==0) return 1;
    else{
        return ((n%MOD)*(kaijou(n-1)%MOD))%MOD;
    }
}

bool ispow(int n){
    int rn=sqrt(n);
    if(rn*rn==n) return true;
    else return false;
}

signed main() {
    int n; cin>>n;
    string s; cin>>s;
    stack<char> kako;
    
    int left=0;
    int right=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]==')'){
            left++;
        }else{
            if(left>0){
                left--;
            }else right++;
        }
    }

    string ans="";
    for(int i=0;i<left;i++){
        ans+='(';
    }
    ans+=s;
    for(int i=0;i<right;i++){
        ans+=')';
    }

    cout<<ans<<endl;
    
}
