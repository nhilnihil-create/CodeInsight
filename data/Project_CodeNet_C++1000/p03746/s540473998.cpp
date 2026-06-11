#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int n, m;
vector<pair<int, int>> veze;
vector<int> g[500000];
vector<int> sol;
vector<int> sol2;
bool bio[500000];
vector<int> k;
int gran1, gran2;
void f(){
    if (sol.size()==0 || gran1 != sol[sol.size()-1])sol.push_back(gran1);
    if (sol2.size()==0 || gran2 != sol2[sol2.size()-1])sol2.push_back(gran2);
    bool c = 0;
    bool d = 0;
    ///cout <<gran1 <<" " <<gran2 <<endl;
    for (int i = 0; i < g[gran1].size(); ++i){
        if (!bio[g[gran1][i]] && !c){
            ///cout <<"sdfsdfsdfsdf";
            c=1;
            bio[g[gran1][i]] = 1;
            gran1 = g[gran1][i];
            break;
        }
    }

    for (int i = 0; i < g[gran2].size(); ++i){
        if (!bio[g[gran2][i]] && !d){
            d=1;
            bio[g[gran2][i]] = 1;
            gran2 = g[gran2][i];
            break;
        }
    }
    ///cout <<gran1 <<" " <<gran2 <<" " <<c <<" " <<d <<endl;
    ///system("pause");
    if (!c && !d){
        return;
    }
    f();
}
int main()
{
    cin >>n >>m;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >>a >>b;
        veze.push_back({a, b});
        g[a].push_back(b);
        g[b].push_back(a);
    }
    gran1 = 1;
    gran2 = g[1][0];
    bio[gran1] = 1;
    bio[gran2] = 1;
    f();
    cout <<sol.size() + sol2.size() <<endl;
    reverse(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); ++i){
        cout <<sol[i] <<" ";
    }
    for (int i = 0; i < sol2.size(); ++i)cout <<sol2[i] <<" ";
return 0;
}
