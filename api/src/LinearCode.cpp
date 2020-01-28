#include "LinearCode.h"
#include "SpectreElement.h"


LinearCode::LinearCode()
{
}


LinearCode::~LinearCode()
{
}

string * LinearCode::CalculateMatrix(int64_t n, int64_t m)
{
	bool **A = new bool*[m];//bin
	int *B = new int[(int)(pow(2., (double)(n)) - 1)];//dec

	for (int i = 0; i < m; i++)//vavejda se matricata
	{
		A[i] = new bool[n];
		bitset<64> number;

		for (int j = 0; j < n; j++)
		{
			number.set(n - 1 - j, A[i][j]);
		}

		B[i] = number.to_ulong();
	}

	return Combinations(m, n, B);//namirame kombinaciite
}

bool LinearCode::nextComb(int n, int k, int * comb)
{
	int i = k - 1;
	for (; i >= 0, comb[i] == n - k + i + 1; i--);
	if (i < 0) return false;
	comb[i]++;
	for (i++; i < k; i++) comb[i] = comb[i - 1] + 1;
	return true;
}

string* LinearCode::Combinations(int m, int n, int * B)
{
	int combinations = (int)(pow(2., (double)(n)));
	vector<SpectreElement> result = vector<SpectreElement>();

	int *C = new int[combinations];
	for (int k = 0; k <= (int)(pow(2., (double)(m)) - 1); k++)
	{
		if (k > m || m < 1)
			break;

		for (int i = 0; i < k; i++)
			C[i] = i + 1;

		do
		{
			SpectreElement element;
			for (int i = 0; i < k; i++) //B[C[i]-1]
			{
				element.AddValue(B[C[i] - 1]);
			}

			if (k != 0)
			{
				element.Calculate();
				result.push_back(element);
			}

		} while (nextComb(m, k, C));
	}

	sort(result.begin(), result.end());

	string* strResults = new string[result.size()];

	int j = 0;
	for (auto i = result.begin(); i != result.end(); i++, j++)
	{
		strResults[j] = (*i).ToString(n);
	}

	return strResults;
}
