
#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct xyg{
    int x;
    int y;
    int g;
};

xyg extended_euclid(ll a, ll b)
{
    xyg ans;
    if(b==0)
    {
        ans.x=1;
        ans.y=0;
        ans.g=a;

        return ans;
    }

    xyg sm = extended_euclid(b,a%b);
    ans.x = sm.y;
    ans.y = sm.x - ((a/b)*sm.y);
    ans.g = sm.g;

    return ans;

}

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b) != EOF)
    {
        xyg t = extended_euclid(a,b);

        printf("%d %d %d\n",t.x,t.y,t.g);

    }

}
