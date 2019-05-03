#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
void string_Kmp(string & tcmp, string & text)
{	
	int cmp_num = 0;
	vector<int> pos_next(tcmp.length()+1);
	int local_i = 0; // for text
	int local_j = -1; // for cmp
	pos_next[0] = -1;
	while (local_i < tcmp.length())
	{
		while ((local_j == -1) || tcmp[local_i] == tcmp[local_j])
		{
			pos_next[local_i + 1] = local_j + 1;
			local_j++;
			local_i++;
		}
		if (local_j != 0)
		{
			local_j = pos_next[local_j];
		}
		else
		{
			pos_next[local_i + 1] = 0;
			local_i++;
		}
	}
	int i = 0, j = 0;
	while (i < text.length() - tcmp.length())
	{
			while (pos_next[j] == -1 || text[i] == tcmp[j])
			{
				i++;
				j++;
			}
			if (j == tcmp.length())
			{
				cout <<"Matched String = '"<< tcmp  <<"'"<< endl;
				cout << "Matched string found starting at text position " << i - tcmp.length() << "." << endl;
				cout << "Total number of character comparisons =" << cmp_num << endl;
				break;
			}
			j = pos_next[j];
			cmp_num++;
	}
	cout << tcmp << endl;
	cout << "no match!" << endl;
}

void string_Add(string s1, string s2, string s3, string s)
{
	string tcmp;
	int string_round = 0;
	for (string_round = 0; string_round < 10; string_round++)
	{
		tcmp.append(s1);
		for (int j = 0; j < string_round; j++)
		{
			tcmp.append(s2);
		}
		tcmp.append(s3);
		if (tcmp.length() <= s.length())
		{
			string_Kmp(tcmp, s);
			tcmp.clear();
		}
		else
		{	
			
			cout << tcmp << endl;
			cout << "out of range!" << endl;
			tcmp.clear();
		}
	}
}

int main() {  // to do list :the text can be add 

	ifstream in("data1.txt");
	string T, s, s1, s2, s3;
	getline(in, s1);
	getline(in, s2);
	getline(in, s3);
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	while (!in.eof()) {
		getline(in, s);
		T.append(s);
	}
	cout << "s =" << T << endl;
	in.close();
	string_Add(s1, s2, s3, T);
	system("pause");
	return 0;
}