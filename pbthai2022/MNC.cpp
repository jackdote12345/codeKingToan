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


char b[2000005];
int p[2000005];

void solve() 
{
	string s;
	cin >> s;
	int cnt = 1;
	int n = (int)s.size();

	b[0] = '!'; b [1] = '#';

	for (int i = 1; i <= n; i++)
	{
		cnt++; b[cnt] = s[i - 1];
		cnt++; b[cnt] = '#';
	}	

	int C = 0, R = 1;
	long long res = 0;
	b[cnt + 1] = '@';

	for (int i = 2; i < cnt; i++)
	{
		int w = 2*C - i;
		p[i] = (R > i ) ? min(R - i, p[w]) : 0;
		while(b[i - 1 - p[i]] == b[i + 1 + p[i]]) p[i]++;
		if (i + p[i] > R)
		{
			C = i; R = i + p[i];
		}
		int val = p[i];
		if (val%2)
		{
			res += (val - 1)/2 + 1;
		}
		else res += (val - 2)/2 + 1;
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
