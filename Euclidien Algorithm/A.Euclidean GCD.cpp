#include<bits/stdc++.h>
using namespace std;

int euclidean(int a, int b)
{
    if(a==0)
        return b;

    return euclidean(b%a,a);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b;
        cin>>a>>b;

        int gcd = euclidean(a,b);

        cout<<gcd<<endl;
    }

    return 0;
}
