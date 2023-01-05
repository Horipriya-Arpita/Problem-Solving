#include<bits/stdc++.h>

using namespace std;

struct xyg{
    int x;
    int y;
    int g;
};

xyg ext_euclid(int a, int b)
{
    xyg ans;
    if(b==0)
    {
        ans.x = 1;
        ans.y = 0;
        ans.g = a;
        return ans;
    }

    xyg sm_ans = ext_euclid(b,a%b);

    ans.x = sm_ans.y;
    ans.y = sm_ans.x - (a/b)*sm_ans.y;
    ans.g = sm_ans.g;

    return ans;
}

int crt_weak(int a1, int a2, int m1, int m2)
{
    xyg pq = ext_euclid(m1,m2);
    int p = pq.x;
    int q = pq.y;

    int x = (a1*m2*q + a2*m1*p) % (m1*m2);

    return x;
}

int main()
{
    int a1,a2,m1,m2;
    cin>>a1>>a2>>m1>>m2;

    int x = crt_weak(a1,a2,m1,m2);

    cout<<x<<endl;

    /*xyg s = ext_euclid(80,55);

    cout<<"80 * "<<s.x<<" + 55 * "<<s.y<<" = "<<s.g<<endl;*/

    return 0;
}
