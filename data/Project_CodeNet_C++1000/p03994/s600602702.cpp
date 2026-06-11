#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
using P =pair<int,int>;
//int dy[4] = {-1,0,1,0};
//int dx[4] = {0,-1,0,1};

/*
bool dfs(vector<vector<P>> &data, vector<long long> &d, queue<int> &temp)
{
    while(!temp.empty())
    {
    int i= temp.front();
    temp.pop();
    for(int j=0;j<data[i].size();j++)
    {
        if(d[data[i][j].first] == LONG_LONG_MAX)
        {
            d[data[i][j].first] = d[i] + data[i][j].second;
            temp.push(data[i][j].first);
            
        }
        else if(d[data[i][j].first] != d[i] + data[i][j].second)
        {
            return false;
            break;
        }
    }
    }
    return true;
}


int main()
{
    int N,M;
    cin >>N >> M;
    
    vector<vector<P>> data(N);
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        
        data[a-1].push_back(make_pair(b-1,c));
        data[b-1].push_back(make_pair(a-1,-c));
    }
    
    vector<long long> d(N,LONG_LONG_MAX);
    bool nouse = false;
    if(data[0].size() != 0) d[0] = 0;
    else nouse = true;
    
    bool ok = true;
    
    int k=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<data[i].size();j++)
        {
            if(nouse)
            {
                d[i] = 0;
                nouse = false;
                k=i;
                break;
            }
        }
    }
    
    /*
            }
            if(d[data[i][j].first] == LONG_LONG_MAX)
            {
                d[data[i][j].first] = d[i] + data[i][j].second;
            }
            else if(d[data[i][j].first] != d[i] + data[i][j].second)
            {
                ok = false;
                break;
            }
        }
        if(!ok)
        {
            break;
        }
 
    
    
    queue<int> temp;
    temp.push(k);
    if(dfs(data,d,temp)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
*/





int main()
{
    string s;
    long long k;
    cin >> s;
    cin >> k;
    int t = (int)s.size();
    vector<int> data(t);
    
    for(int i = 0;i<t-1;i++)
    {
        data[i] = (123 - s[i])%26;
    }
    for(int i = 0;i<t-1;i++)
    {
        if(data[i] < k+1)
        {
            s[i] = 'a';
            k -= data[i];
        }
    }
    
    k %= 26;
    
    
    
    if(s[t-1] + k > 122)
    {
        s[t-1] -= 26-k;
    }
    else
    {
        s[t-1] += k;
    }
    
    cout << s << endl;
    
    return 0;
}


