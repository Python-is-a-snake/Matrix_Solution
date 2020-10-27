#include <iostream>
using namespace std;

int main()
{
    int a[100][100], i, j, k, p, s[100], l, buf, m, n;
    cout << "Enter n and m(size of matrix): ";
    cin >> n;
    cin >> m;
    k = 0;
    cout << "Enter matrix: ";
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    for (j = 0; j < n; j++)
    {
        p = 0;
        for (i = 0; i < m; i++)
            if (a[i][j] == 0)
                p = 1;
        if (p == 0)
            k++;
    }
    for (i = 0; i < m; i++)
        s[i] = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if ((a[i][j] > 0) && (a[i][j] % 2 == 0))
                s[i] = s[i] + a[i][j];
    for (l = 0; l < m; l++)
        for (i = 0; i < m - 1; i++)
        {
            if (s[i] > s[i + 1])
            {
                buf = s[i];
                s[i] = s[i + 1];
                s[i + 1] = buf;
                for (j = 0; j < n; j++)
                {
                    buf = a[i][j];
                    a[i][j] = a[i + 1][j];
                    a[i + 1][j] = buf;
                }
            }
        }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << endl;
    }

}