#include<bits/stdc++.h>
#define ll long long

using namespace std;

int cs;
ll mx = 1000009;
ll md = 1000003;
ll fc[mx];
void precalculate(ll p)
{
    fc[0]=1;
    fc[1]=1;
    fc[2]=2;

    for(int i = 3; i<mx; i++)
    {
        fc[i] = ((fc[i-1]%md)*(i%md))%md;
    }

}

void nCr(int n, int r)
{
    ll ans = ((fc[n-r]%md)*(fc[r]%md))%md;
}
int main()
{
    int t;
    cin>>t;
    precalculate(mx);

    while(t--)
    {
        cs++;
        ll n,r;
        cin>>n>>r;
        nCr(n,r);
    }

}
