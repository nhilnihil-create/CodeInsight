#include<bits/stdc++.h>
using namespace std;

int d[305][305];

int main()
{
    long long n;

    cin>>n;

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cin>>d[i][j];

    for(int k = 1; k<=n; k++)
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
                if(d[i][k] + d[k][j] < d[i][j])
                {
                    puts("-1");
                    return 0;
                }


    long long res;



    bool lagbena[305][305];
    memset(lagbena, 0, sizeof(lagbena));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n; k++){
                if(d[i][j] == d[i][k] + d[k][j]){
                    if(d[i][k] && d[k][j]){
                        lagbena[i][j] = true;
                    }

                }
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            if(!lagbena[i][j]) res += d[i][j];
        }
    }

    cout<<res<<endl;










}
