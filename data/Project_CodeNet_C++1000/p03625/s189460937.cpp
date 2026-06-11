#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,i,k,l;

    cin>>n;

    vector<long long>a(n);

    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());

    reverse(a.begin(),a.end());

    queue<long long >q;
    for(i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            q.push(a[i]);//so if we get 5 5 5 5 4 4 4 4 3 2 1 then for 2times 5 one will be on q,again 5 will come
            i++;//we will get one value of length though
        }
    }

    if(q.size()>=2)//we got best 2 values already a,b
    {
        k=q.front();//width

        q.pop();//without poping won't get the 2nd element

        l=q.front();//because of poping 2nd element is there
    }

    cout<<k*l<<endl;

    return 0;

}
