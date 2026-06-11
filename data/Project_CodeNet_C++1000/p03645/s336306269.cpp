#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;


vector<int>  v[200001];
int n ,m;
bool ans;

int main()
{

ans=false;
cin>>n>>m;

for(int index = 0;index < m;index++)
{
    int from ,to;
    cin>>from>>to;

    v[from].push_back(to);
    v[to].push_back(from);
}
for(int index = 0 ;index < v[1].size();index++)
{
    for(int i = 0 ;i< v[v[1][index]].size();i++)
    {
        if(v[v[1][index]][i]==n)
        {
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
}

cout<<"IMPOSSIBLE"<<endl;

 return 0;
}
