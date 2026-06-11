// ABC64-D
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n;
    cin>>n;
    deque<char> info;
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') a++;
        else{
            if(0<a) a--;
        }
        info.push_back(s[i]);
    }
    for(int i=n-1;0<=i;i--){
        if(s[i]==')') b++;
        else{
            if(0<b) b--;
        }
    }
    for(int i=0;i<a;i++){
        info.push_back(')');
    }
    for(int i=0;i<b;i++){
        info.push_front('(');
    }
    for(int i=0;i<info.size();i++){
        cout<<info[i];
    }
    cout<<endl;
    return 0;
}