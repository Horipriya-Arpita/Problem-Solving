
#include<bits/stdc++.h>
using namespace std;

struct xyg{
    int x;
    int y;
    int g;
};

xyg exteuclid(int a, int b)
{
    xyg ans;
    if(b==0)
    {
        ans.x=1;
        ans.y=0;
        ans.g=a;

        return ans;
    }

    xyg sm = exteuclid(b,a%b);
    ans.x = sm.y;
    ans.y = sm.x - ((a/b)*sm.y);
    ans.g = sm.g;

    return ans;
}

int inverse(int a, int b)
{
    xyg ans = exteuclid(a,b);

    return ans.x;
}

int main()
{

    int a,m;
    cin>>a>>m;

    int p = inverse(a,m);
    cout<<p<<endl;


    return 0;
}

