#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INT_MAX 0x7fffffff
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

typedef long long LL;
const int MAXN = 100000;
int N, M, A, B;
int a[MAXN + 5], dp[MAXN + 5]; // a[i]表示去i层的人数, dp[i]表示电梯停在第i层的最小消耗

void myjun()
{
    int up2, up3, t = MIN(A, B);
    dp[3] = a[2] * t;
    dp[4] = a[3] * t;
    for (int i = 5; i <= N; ++i)
    {
        // 跳一层停
        up2 = dp[i - 2] + a[i - 1] * t;
        
        // 跳两层停
        if (A * 2 < B) // 全采取上楼的方式
            up3 = dp[i - 3] + a[i - 1] * A * 2 + a[i - 2] * A;
        else if (A > B * 2) // 全采取下楼的方式
            up3 = dp[i - 3] + a[i - 1] * B + a[i - 2] * B * 2;
        else // 一层上楼，一层下楼
            up3 = dp[i - 3] + a[i - 1] * B + a[i - 2] * A;
        dp[i] = MIN(up2, up3);
    }
}

int main()
{
    int T, t, i, x;
    cin >> T;
    for (t = 1; t <= T; ++t)
    {
        cin >> N >> M >> A >> B;
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for (i = 0; i < M; ++i)
        {
            cin >> x;
            ++a[x];
        }
        myjun();
        cout << "Case " << t << ": " << dp[N] << endl;
    }
}
