#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 2000000;
int n;
int a[1005], sum[1005], dp[1005][1005]; // sum[i]表示前i个数的和，dp[i][j]表示从第i个数到第j个数能取到的最大和

int myjun(int i, int j) // myjun(i, j)表示从第i个数到第j个数能取到的最大和
{
    if (i > j) return 0;
    if (i == j) return a[i];
    if (dp[i][j] != INF) return dp[i][j];
    int l = a[i] + sum[j] - sum[i] - myjun(i + 1, j); // 从左边取
    int r = a[j] + sum[j - 1] - sum[i - 1] - myjun(i, j - 1); // 从右边取
    return dp[i][j] = max(l, r);
}

int main()
{
    while (cin >> n)
    {
        sum[0] = a[0] = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = INF;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        int t = myjun(1, n);
        cout << t * 2 - sum[n] << endl;
    }
}
