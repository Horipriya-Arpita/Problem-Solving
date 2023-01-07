#include<bits/stdc++.h>
#define M 10
using namespace std;

vector<int>mp(M+1);
vector<int>pr;

void printmp()
{
    for(int i =0; i<M; i++)
    {
        cout<<i<<"-"<<mp[i]<<"   ";
    }
    cout<<endl;
}
void linear_sieve(int n)
{
    int i,j;
    for(i=2; i<n; i++)
    {
        if(mp[i]==0)
        {
            mp[i] = i;
            pr.push_back(i);
        }

        printmp();

        for(j=0; i*pr[j]<=n && pr[j]<=mp[i] && j<pr.size(); j++)
        {
            mp[i*pr[j]] = pr[j];
        }
    }

    for(i=0; i<pr.size(); i++)
    {
        cout<<pr[i]<< " "<<endl;
    }
    cout<<endl;
}

int main()
{
    linear_sieve(M);
}
