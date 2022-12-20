#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int lim = 3000000;
int sl[3000005];
bool dd[3000005];
int a[1000005];

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dd[a[i]] = true;
		sl[a[i]]++;
	}
	for (int i = lim; i; i--)
	if (sl[i])
	{
		for (int j = 2*i; j <= lim; j+= i)
			sl[j] += sl[i];
	}
	long long res = 0;
	for (int i = 2; i <= lim; i++)
	if (dd[i] && sl[i])
	{
		for (int j = 2*i; j <= lim; j += i) if (dd[j]) res += sl[i]-1;
	}
	cout << res;
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
