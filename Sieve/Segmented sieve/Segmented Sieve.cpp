#include<bits/stdc++.h>
#define M 1000
#define ll long long
using namespace std;

vector<int>prm;
bool mrk[M];

void sieve(int n)
{
    ll i,j;
    mrk[0]=mrk[1]=true;

    prm.push_back(2);
    for(i=4; i<=n; i+=2)
    {
        mrk[i] = true;
    }

    for(i=3; i*i<=n; i+=2)
    {
        if(mrk[i]==false)
        {
            prm.push_back(i);
            for(j=i*i; j<=n; j+=2*i)
            {
                mrk[j] = true;
            }
        }
    }
}

void segmented_sieve(int L, int R)
{
    bool isprm[R-L+1];

    for(ll i=0; i<=R-L; i++)
    {
        isprm[i]=true;
    }

    if(L==1){
        isprm[0] = false;
    }

    for(ll i=0; prm[i]*prm[i]<=R; i++)
    {
        ll curp = prm[i];
        ll base = curp*curp;

        if(base<L)
        {
            base = ((L+curp-1)/curp)*curp;
        }

        for(ll j=base; j<=R; j+=curp)
        {
            isprm[j-L]=false;
        }
    }

    for(ll i=0; i<=R-L; i++)
    {
        if(isprm[i]==true){
            cout<<L+i<<" ";
        }
    }
    cout<<endl;


}
int main()
{
    int L = 29;
    int R = 700;
    sieve(M);
    segmented_sieve(L,R);

    return 0;
}
