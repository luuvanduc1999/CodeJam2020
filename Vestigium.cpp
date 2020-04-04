//#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		int n;
		cin >> n;
		int a[101][101];
		int col[101][101] = { 0 };
		int row[101][101] = { 0 };
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
				col[j][a[i][j]]++;
				row[i][a[i][j]]++;
			}

		int result = 0;
		for (int i = 0; i < n; i++)
			result += a[i][i];

		int resultRow = 0;
		int resultCol = 0;
		for (int i = 0; i < n; i++)
		{
			bool flagRow = 0;
			bool flagCol = 0;
			for (int j = 0; j <=n; j++)
			{
				if ((flagRow == 0) && (row[i][j] > 1)) {
					resultRow++;
					flagRow = 1;
				}

				if ((flagCol == 0) && (col[i][j] > 1)) {
					resultCol++;
					flagCol = 1;
				}
			}
		}
		cout << "Case #" << k+1 << ": " << result << " " << resultRow << " " << resultCol << endl;
	}
}
