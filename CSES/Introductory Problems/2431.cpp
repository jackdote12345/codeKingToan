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

long long de[20];

void solve() 
{
	long long cur = 1;
	for (int i = 1; i <= 17; i++) 
	{
		de[i] = (de[i-1] + 1ll*i*(cur*10 - cur )); cur = cur*10;
	}

	int q;
	cin >> q;
	while(q--)
	{
		long long w; cin >> w;
		long long cur = 1;

		for (int i = 1; i <= 17; i++) 
		{
			if (w <= de[i])
			{
				w -= de[i-1];
				cur += (w/i + (w%i != 0)) - 1; 
				w%=i; w = (i - w)%i; while(w){ cur /= 10; w--;};
				cout << cur%10 << "\n";
				break;

			}
			cur = cur*10;
		}
	}
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
