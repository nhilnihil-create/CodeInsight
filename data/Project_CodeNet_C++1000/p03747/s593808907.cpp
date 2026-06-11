#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long N,L,T; cin >> N >> L >> T;
    vector<pair<long long,int>> X(N);
    vector<long long> ans(N),ans1(N);
    long long x,w,z;
    pair<long long,int> ant;
    for (int i=0;i<N;i++)
    {
        cin >> x >> w;
        ant=make_pair(x,w);
        X[i]=ant;
        if (w==1)
        {
            ans[i]=(x+T)%L;
            ans1[i]=(x+T)%L;
        }
        else
        {
            ans[i]=((x-T)%L>=0?(x-T)%L:L+(x-T)%L);
            ans1[i]=((x-T)%L>=0?(x-T)%L:L+(x-T)%L);
        }
    }
    long long time=0;
    int index=0,index2;
    if (X[0].second==1)
    {
        for (int i=0;i<N;i++)
        {
            if (X[i].second==2)
            {
                time+=T/L*2;
                if (T%L>=(X[i].first-X[index].first)/2+(X[i].first-X[index].first)%2) time++;
                if (T%L>=(L+X[i].first-X[index].first)/2+(L+X[i].first-X[index].first)%2) time++;
            }
        }
        z=ans[0];
        sort(ans1.begin(),ans1.end());
        for (int i=0;i<N;i++)
        {
            if (ans1[i]==z)
            {
                if ((ans1[(i+1)%N]!=z) & (ans1[i-1>=0?i-1:N-1]!=z)) index=i;
                else
                {
                    if (ans1[i-1>=0?i-1:N-1]==z) index=i;
                }
            }
        }
        index2=(index-time%N>=0?index-time%N:N+index-time%N);
        for (int i=0;i<N;i++) cout << ans1[(index2+i)%N] << endl;
    }
    else
    {
        for (int i=0;i<N;i++)
        {
            if (X[i].second==1)
            {
                   time+=T/L*2;
                if (T%L>=(L-X[i].first+X[0].first)/2+(L-X[i].first+X[0].first)%2) time++;
                if (T%L>=(2*L-X[i].first+X[0].first)/2+(2*L-X[i].first+X[0].first)%2) time++;
            }
        }
        z=ans[0];
        sort(ans1.begin(),ans1.end());
        for (int i=0;i<N;i++)
        {
            if (ans1[i]==z)
            {
                if ((ans1[(i+1)%N]!=z) & (ans1[i-1>=0?i-1:N-1]!=z)) index=i;
                else
                {
                    if (ans1[(i+1)%N]==z) index=i;
                }
            }
        }
        index2=((index-N+time%N)%N>=0?(index-N+time%N)%N:(N+index-N+time%N)%N);
        for (int i=0;i<N;i++) cout << ans1[(index2+i)%N] << endl;
        
    }
   return 0; 
}
