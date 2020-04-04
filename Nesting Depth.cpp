//#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	string tmp;
	getline(cin, tmp);
	for (int k = 0; k < T; k++)
	{
		string s;
		getline(cin, s);
		int n = s.length();
		vector<int> num(n, 0);

		for (int i = 0; i < n; i++)
		{
			num[i] = int(s[i]) - 48;
			//cout << num[i] << " ";
		}

		string result("");
		int remain = 0;
		for (int i = 0; i < n; i++)
		{
			if (num[i] == 0)
			{
				result+=s[i];
			}

			if (num[i] > 0)
			{
				for (int j = 0; j < num[i]; j++)
					result += '(';
				result += s[i];
				int shift = num[i];
				for (int j = i; j < n; j++)
					num[j] -= shift;
				remain += shift;
			}

			if (num[i] < 0)
			{
				for (int j = 0; j < -num[i]; j++)
					result += ')';
				result += s[i];
				int shift = num[i];
				for (int j = i; j < n; j++)
					num[j] -= shift;
				remain += shift;
			}

		}

		for (int j = 0; j < remain; j++)
			result += ')';

		cout << "Case #" << k + 1 << ": " << result << endl;
	}
}
