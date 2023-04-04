/*
Problem link:
https://codeforces.com/problemset/problem/1675/A
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b,c,x,y,p,q;
        cin>>a>>b>>c>>x>>y;

        if(a<x){
            p = x-a;
            if(c>=p){
                c-=p;
            }
            else {
                cout<<"NO"<<endl;
                continue;
            }
        }

        if(b<y){
            q = y-b;
            if(c>=q){
                c-=q;
            }
            else {
                cout<<"NO"<<endl;
                continue;
            }
        }

        cout<<"YES"<<endl;
    }

    return 0;
}

