/*
Problem Link:
https://codeforces.com/problemset/problem/1611/A

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int l = s.size();
        int i,r=-1;

        if((s[l-1]-'0')%2==0){
           r = 0;
        }
        else{
            if((s[0]-'0')%2==0){
                r = 1;
            }
            else{
                for(i=1; i<l-1; i++){
                    if((s[i]-'0')%2==0){
                        r = 2;
                    }
                }
            }
        }

        cout<<r<<endl;
    }

    return 0;
}
