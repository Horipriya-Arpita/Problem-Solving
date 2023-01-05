
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

int main()
{

    int a,b;
    cin>>a>>b;

    xyg p = exteuclid(a,b);
    cout<<p.x<<" "<<p.y<<" "<<p.g<<endl;


    return 0;
}
