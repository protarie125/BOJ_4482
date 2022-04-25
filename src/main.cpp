#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

vl memo;

ll solve(ll n) {
	if (memo[n] < 0) {
		for (int i = 2; i <= n; ++i) {
			if (memo[i] < 0) {
				memo[i] = memo[i - 1] + (i * (i + 1)) / 2;
			}
		}
	}

	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	memo = vl(1000, -1);
	memo[0] = 0;
	memo[1] = 1;

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << i + 1 << ": ";

		ll n;
		cin >> n;

		cout << n << ' ' << solve(n);

		cout << '\n';
	}

	return 0;
}