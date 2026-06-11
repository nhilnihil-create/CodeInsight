# include <iostream>
# include <climits>
using namespace std;

string s;
bool letters[27];
int steps[27];
int ans=INT_MAX;

int findsteps (char letter)
{
    int maximum=0;
    int left=0;
    string temp=letter+s+letter;
    
    for (int right=0; right<temp.size(); right++)
    {
        if (temp[right]==letter)
        {
            maximum=max(maximum, right-left-1);
            left=right;
        }
    }

    return maximum;
}

int main()
{
    cin>>s;
    
    for (int i=0; i<s.size(); i++)
    {
        letters[s[i]-'a']=true;
    }

    for (int i=0; i<27; i++)
    {
        if (letters[i])
        {
            steps[i]=findsteps(i+'a');
        }
    }

    for (int i=0; i<27; i++)
    {
        if (letters[i]!=0)
        {
            ans=min(ans, steps[i]);
        }
    }

    cout<<ans<<endl;
}