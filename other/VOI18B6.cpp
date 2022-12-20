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
inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}
void WriteInt(long long x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int a[100005];
void solve()
{
	int n;
	n = ReadInt();
    for (int i = 1; i <= n; i++) 
    {
        a[i] = ReadInt();
    }
    priority_queue<int> q;
 	long long res = 0;
    for (int i=1; i<=n; i++) 
    {
        q.push(a[i]);
        if (q.top() > a[i]) 
        {
            res += q.top() - a[i];
            q.push(a[i]);
            q.pop();
        }
    }
    WriteInt(res);
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
