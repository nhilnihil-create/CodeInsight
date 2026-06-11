    #include<iostream>
    #include<vector>
    using namespace std;
    int main(){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>roads(n,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            int f,s;    
            cin>>f>>s;
            f--,s--;
            roads[f][s]++;
            roads[s][f]++;
        }
        for(int i=0;i<n;i++)
        {
            int result=0;
            for(int j=0;j<n;j++)
            {
                result+=roads[i][j];
            }
            cout<<result<<endl;
        }
    }