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

int crt_strong(int a1, int a2, int m1, int m2)
{
    int gc = __gcd(m1,m2);

    if(a1%gc != a2%gc){

        return -1;
    }

    cout<<gc<<"gc"<<endl;
    xyg pq = ext_euclid(m1/gc,m2/gc);

    int mod = (m1/gc)*m2;

    int p = pq.x;
    int q = pq.y;

    cout<<p<<" " <<q<<endl;

    int x = (a1*(m2/gc)*q + a2*(m1/gc)*p) % mod;

    x+=mod;
    x+=mod;

    return x;
}

int main()
{
    int a1,a2,m1,m2;
    cin>>a1>>a2>>m1>>m2;

    int x = crt_strong(a1,a2,m1,m2);

    cout<<x<<endl;


    return 0;
}

