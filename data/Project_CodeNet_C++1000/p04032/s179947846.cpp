#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}

#define ANTHRO(args...) {__anthro_begin(__LINE__); __anthro(split(#args, ',').begin(), args);}

inline void __anthro_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __anthro_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __anthro_out_var(T* val) { cerr << arrStr(val,2); } //Change the values in case you want to debug something
template<typename T> inline void __anthro_out_var(T val) { cerr << val; }
inline void __anthro(vector<string>::iterator it) { cerr << endl; }

template<typename T, typename... Args>
inline void __anthro(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __anthro_out_var(a);
    cerr << "; ";
    __anthro(++it, args...);
}
//Simple Debugger

#define ll long long
#define MOD 1000000007
#define EPS 1e-9
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
/*
    This is D.Unbalanced
*/

int main(){
    string s; cin>>s;
    for(auto& c:s) c-='a';
    vector<vector<int>> a(100010,vector<int> (26,0));
    bool flag=false;
    int k=0,st=0,en=0;
    for(int i=1;i<=s.length();i++){
        a[i]=a[i-1];
        a[i][s[i-1]]++;
        //ANTHRO(a[i-1],a[i],a[i][s[i-1]],a[i-2][s[i-1]]);
        if((i-2)>=0 && (a[i][s[i-1]]-a[i-2][s[i-1]])>=2){
            st=i-1;
            en=i;
            break;
        }
        else if((i-3)>=0 && (a[i][s[i-1]]-a[i-3][s[i-1]])>=2)
        {
            st=i-2;
            en=i;
            break;
        }
    }
    if(st==0&&en==0){
        cout<<-1<<" "<<-1;
    }
    else{
        cout<<st<<" "<<en;
    }
    return 0;
}
