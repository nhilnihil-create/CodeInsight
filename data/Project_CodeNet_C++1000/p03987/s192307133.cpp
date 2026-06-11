# include <iostream>
# include <deque>
using namespace std;

int N;
int a[200005];
long long minfront[200005];
long long minback[200005];
deque<int> front;
deque<int> back;
long long counter=0;

int main()
{
    cin>>N;

    for (int i=1; i<=N; i++)
    {
        cin>>a[i];
    }

    for (int i=1; i<=N; i++)
    {
        if (i==1)
        {
            front.push_back(a[i]);
            minfront[a[i]]=1;
        }

        else
        {
            minfront[a[i]]=1;
            while (!front.empty() && a[i]<front.back())
            {
                minfront[a[i]]+=minfront[front.back()];
                front.pop_back();
            }
            front.push_back(a[i]);
        }
    }


    for (int i=N; i>=1; i--)
    {
        if (i==N)
        {
            back.push_back(a[i]);
            minback[a[i]]=1;
        }

        else
        {
            minback[a[i]]=1;
            while (!back.empty() && a[i]<back.back())
            {
                minback[a[i]]+=minback[back.back()];
                back.pop_back();
            }
            back.push_back(a[i]);
        }
    }

    for (int i=1; i<=N; i++)
    {
        counter=counter+i*minfront[i]*minback[i];
    }

    cout<<counter<<endl;
}