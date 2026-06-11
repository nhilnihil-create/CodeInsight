//おまじない
#include <iostream>
#include<iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn=100000;

int n;
string s;

int main(){
    
    cin >> s;
    int size = s.size();
    if(size%2==0){
        if(s[0]==s[size-1]){
            cout << "First"<<endl;
        }else{
            cout << "Second"<<endl;
        }
    }else{
        if(s[0]==s[size-1]){
            cout <<"Second"<<endl;
        }else{
            cout <<"First"<<endl;
        }
    }
    
    return 0;
}
