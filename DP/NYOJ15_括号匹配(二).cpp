#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INT_MAX 0x7fffffff
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;

typedef long long LL;
char s[105];
int dp[105][105];

/*
 * 思路："(S)"或"[S]"的情况等于"S"的情况；
 *       将S分割，即S(i,j)的情况等于(S(i,k)+S(k+1,j)) (k = i...j-1)的情况
 *       即dp[i][j] =min{
 *                         1                       (i = j)
 *                         dp[i+1][j-1]            (s[i]和s[j]匹配)
 *                         dp[i][k] + dp[k+1][j]   (k = i...j-1, k∈N*)
 *                      }
 */
int myjun(int i, int j)
{
    if (i > j) // 不存在的情况
        return 0;
    if (dp[i][j] >= 0) // 已经计算过的情况
        return dp[i][j];

    int res = 105;
    if (i == j)
        res = 1;
    if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']')) // "(S)"或者"[S]"等于"S"
        res = MIN(res, myjun(i + 1, j - 1));
    for (int k = i; k < j; ++k) // 将"S"分割
        res = MIN(res, myjun(i, k) + myjun(k + 1, j));

    return dp[i][j] = res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> s;
        cout << myjun(0, strlen(s) - 1) << endl;
    }
}
