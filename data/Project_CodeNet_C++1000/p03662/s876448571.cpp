#include <bits/stdc++.h>
using namespace std;

int N;

void search1(vector<vector<int>> &connect,vector<int> &length, int temp, int k)
{
    for(int i = 0;i<connect[k].size();i++)
    {
        if(length[connect[k][i]] == 0 && connect[k][i] != 0)
        {
            length[connect[k][i]] = temp + 1;
            search1(connect,length,temp+1,connect[k][i]);
        }
    }
}
void search2(vector<vector<int>> &connect,vector<int> &length, int temp, int k)
{
    for(int i = 0;i<connect[k].size();i++)
    {
        if(length[connect[k][i]] == 0 && connect[k][i] != N-1)
        {
            length[connect[k][i]] = temp + 1;
            search2(connect,length,temp+1,connect[k][i]);
        }
    }
}

int main()
{
    
    cin >> N;
    
    vector<vector<int>> connect(N);
    for(int i = 0;i<N-1;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    
    vector<int> lengthF(N,0);
    vector<int> lengthS(N,0);
    
    search1(connect,lengthF,0,0);
    search2(connect,lengthS,0,N-1);
    
    int f,s;
    f = 0;
    s= 0;
    for(int i = 0;i<N;i++)
    {
        if(lengthF[i] <= lengthS[i])
        {
            f++;
        }
        else
        {
            s++;
        }
    }
    
    if(f>s)
    {
        cout << "Fennec" << endl;
    }
    else
    {
        cout << "Snuke" << endl;
    }
    
    
    //Fennec ->
    
    return 0;
    
}