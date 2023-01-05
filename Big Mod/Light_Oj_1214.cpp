#include<bits/stdc++.h>
#define ll long long
using namespace std;

int cs;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        cs++;
        string a;
        ll b;
        cin>>a;
        cin>>b;

        b = abs(b);

        int p = 0;

        if(a[0]=='-'){
            p = 1;
        }

        ll r = 0;

        for(int j = p; j<a.size(); j++)
        {
            r = r*10+(a[j]-'0');
            r = r%b;
        }

        if(r==0){
            cout<<"Case "<<cs<<": divisible"<<endl;
        }
        else {
            cout<<"Case "<<cs<<": not divisible"<<endl;
        }
    }

    return 0;
}
