#include <iostream>
#include <vector>

using namespace std;

void Insert(vector<int>& v, int idx)
{
	// insert into a max heap
	for (int i = idx, j = (i - 1) / 2; j >= 0; i = j, j = (i - 1) / 2)
	{
		if (v[i] <= v[j]) break;
		swap(v[i], v[j]);
	}
}
void max_heapify(vector<int>& v)
{
	// create a max heap
	for (int i = 0; i < v.size(); ++i)
		Insert(v, i);

}

int main()
{
	vector<int> vect({ 1,8,5,3,2,9 });
	for (int& i : vect) cout << i << " ";

	max_heapify(vect);

	cout << endl;
	for (int& i : vect) cout << i << " ";
	cout << endl;

	return 0;
}