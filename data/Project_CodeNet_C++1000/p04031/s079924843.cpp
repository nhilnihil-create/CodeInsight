    #include<bits/stdc++.h>
    #define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
    #define ll long long
    #define ara(A,N) sort(A,A+N)
    #define rev(A,N) sort(A,A+N,greater<long long>())
    using namespace std;
    int main()
    {
    long long int i,n,sum=0,p;
    cin>>n;
    long long int z[n];
    for(i=0;i<n;i++)
    {
        cin>>z[i];
    }
    for(i=0;i<n;i++)
    {
        sum+=z[i];
    }
    long long int x=(sum/n);
    p=ceil(sum*1.000/n);
   // cout<<p<<endl;

    long long san=0,pan=0;
    for(i=0;i<n;i++)
    {
        san+=pow((z[i]-p),2);
        pan+=pow((z[i]-x),2);
    }
    cout<<min(san,pan)<<endl;

    }
