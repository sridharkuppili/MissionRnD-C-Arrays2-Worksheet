/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int dates(char *dob1, char *dob2) {
	int d1, d2, m1, m2, y1, y2;
	d1 = ((dob1[0] - 48) * 10) + (dob1[1] - 48);
	d2 = ((dob2[0] - 48) * 10) + (dob2[1] - 48);
	m1 = ((dob1[3] - 48) * 10) + (dob1[4] - 48);
	m2 = ((dob2[3] - 48) * 10) + (dob2[4] - 48);
	y1 = (((dob1[6] - 48) * 1000) + ((dob1[7] - 48) * 100) + ((dob1[8] - 48) * 10) + (dob1[9] - 48));
	y2 = (((dob2[6] - 48) * 1000) + ((dob2[7] - 48) * 100) + ((dob2[8] - 48) * 10) + (dob2[9] - 48));
	if ((((d1 >= 1) && (d1 <= 31)) && ((m1 >= 1) && (m1<13)) && (y1 != 0)) && ((d2 >= 1) && (d2 <= 31) && (m2<13) && (m2 >= 1) && (y2 != 0)))
	{

		if ((((m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12) && (d1 <= 31)) || ((m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11) && (d1 <= 30)) || ((m1 == 2) && (y1 % 4 == 0) && (d1<30)) || ((m1 == 2) && (y1 % 4 != 0) && (d1<29))) && (((m2 == 1 || m2 == 3 || m2 == 5 || m2 == 7 || m2 == 8 || m2 == 10 || m2 == 12) && (d2 <= 31)) || ((m2 == 4 || m2 == 6 || m2 == 9 || m2 == 11) && (d2 <= 30)) || ((m2 == 2) && (y2 % 4 == 0) && (d2<30)) || ((m2 == 2) && (y2 % 4 != 0) && (d2<29))))

		{
			if ((y1 == y2) && (m1 == m2) && (d1 == d2))
				return 0;
			else
			if ((y1<y2) || ((y1 == y2) && (m1<m2)) || ((y1 == y2) && (m1 == m2) && (d1<d2)))
			{
				return 1;
			}
			else
			if ((y2<y1) || ((y1 == y2) && (m2<m1)) || ((y1 == y2) && (m1 == m2) && (d2<d1)))
				return 2;


			else
				return -1;
		}

		else
			return -1;
	}return -1;

}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{

	int res, i, j, count = 0, k = 0;
	struct transaction *ans;
	ans = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
	if (A == NULL || B == NULL)
	{
		return NULL;
	}
	else
	{
		for (i = 0; i < ALen; i++)
		{
			for (j = 0; j < BLen; j++)
			{
				res = dates(A[i].date, B[j].date);

				if (res == 0)
				{
					ans[k] = A[i];

					k++;

				}
				else if (res == -1)
				{
					return NULL;
				}

			}
		}
		if (k > 0)
			return ans;
		else
			return NULL;
	}
}