#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
const int lim = 1e6 + 1;
int sum[1000005];
int a[1000005];
bool kt[2000005];
int n;
void solve()
{
    int dem = 0;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        if (val == 0) dem++;
        else
        if (kt[val + lim] == false) a[++cnt] = val, kt[val + lim] = true;
    }
    sort(a + 1, a + 1 + cnt);
    n = cnt;
    int res, l = 0;
    if (n > 0) res = 1; else res = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1];
        while(l < i && sum[i] - sum[l] > dem) l++;
        res = max(res, i - l);
        sum[i] += a[i+1] - a[i] - 1;
    }
    cout << res + dem;
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
