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

int myjun(char s[])
{
    int k = 0;
    char t[10005];
    for (int i = 0; i < strlen(s); ++i)
    {
        switch (s[i])
        {
        case '(':
        case '[':
            t[k++] = s[i];
            break;
        case ')':
            if (t[k - 1] == '(')
                k--;
            else
                return 0;
            break;
        case ']':
            if (t[k - 1] == '[')
                k--;
            else
                return 0;
            break;
        }
    }
    if (k)
        return 0;
    else
        return 1;
}

int main()
{
    int n;
    char s[10005];
    cin >> n;
    while (n--)
    {
        cin >> s;
        cout << (myjun(s) ? "Yes" : "No") << endl;
    }
}

