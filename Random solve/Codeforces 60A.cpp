#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d\n",&n,&m);

    int ar[n];
    memset(ar,0,sizeof(ar));

    for(int i = 0; i < m; i++)
    {
        string s;
        getline(cin,s);

        int l = s.size();
        int p = 0;
        int r = 1;

        for(int j = l-1; s[j]!=' '; j--)
        {
            p += (s[j]-'0')*r;
            r*=10;
            if(s[j]==' '){
                break;
            }
        }

        if(s[7]=='r')
        {
            for(int k = 0 ; k<p; k++){
                ar[k]=1;
            }
        }

        else if(s[7]=='l')
        {
            for(int k = n-1 ; k>=p-1; k--){
                ar[k]=1;
            }
        }

    }
    int cnt=0;
    for(int t = 0; t < n; t++)
    {
        if(ar[t]==0)
        {
            cnt++;
        }
    }

    if(cnt==0){
        cout<<"-1"<<endl;
    }

    else{
        cout<<cnt<<endl;
    }

    return 0;
}
