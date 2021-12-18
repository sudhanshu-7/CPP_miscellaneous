#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int n;
vector <int> arr;
int dp[(1LL << 18)];

int main() {
	int n , k;
	cin >> n >> k;
	arr = vector <int> (n);
	for (int &x  : arr) cin >> x;
	for (int i = 1; i < (1LL << 18); ++i) {
		dp[i] = -1;
	}
	int sum = 0;
	for (int x : arr) sum += x;
	int target = sum / k;
	cout << "SUM : " << sum << " Target :" << target << endl;
	dp[0] = 0;
	for (int i = 0; i < (1LL << n) ; ++i) {
		for (int j = 0 ; j < n; ++j) {
			if (i & (1 << j)) continue;
			if (dp[i] == -1) continue;
			if (dp[i] + arr[j] > target) continue;
			dp[i | (1 << j)] = dp[i] + arr[j];
			dp[i | (1 << j)] %= target;
		}
	}
	cout << dp[(1 << n) - 1] << endl;

}