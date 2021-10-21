#include <iostream>
#include <vector>
#define MAX_LEN 20

// heap: children:2i+1, 21+2

using namespace std;

int len1 = -1;

void min_heap_Insert(std::vector<int>& heap, int x)
{
	heap[++len1] = x;

	for (int i=len1, j = (i-1)/2; j >= 0; j=(i-1)/2)
	{
		if (heap[i] >= heap[j]) break;
		swap(heap[i], heap[j]);
		i = j;
	}
}

void min_heapify(std::vector<int>& v, std::vector<int>& heap)
{
	// create a min heap from v, by doing inserts one-by-one.
	// runtime = O( N logN ) in worst case
	for (int i : v) min_heap_Insert(heap, i);
}

int len2 = -1;

void max_heap_Insert(vector<int>& heap, int x)
{
	// insert new element in the last place
	heap[++len2] = x;

	// sift through the ancestors to find this element's place in the heap
	// ancestor of i is at (i-1)/2
	for (int i = len2, j = (i - 1) / 2; j >= 0; i = j, j = (i - 1) / 2)
	{
		if (heap[i] <= heap[j]) break;
		swap(heap[i], heap[j]);
	}
}

void max_heapify(std::vector<int>& v, std::vector<int>& heap)
{
	// create a max heap from v, by doing inserts one-by-one
	// runtime = O(n log n) in worst case
	for (int i : v) max_heap_Insert(heap, i);
}

int main()
{
	std::vector<int> v = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

	std::vector<int> heap1(MAX_LEN);
	min_heapify(v, heap1);
	for (int i = 0; i <= len1; ++i) std::cout << heap1[i] << " ";
	std::cout << "\n";

	std::vector<int> heap2(MAX_LEN);
	max_heapify(v, heap2);
	for (int i = 0; i <= len2; ++i) std::cout << heap2[i] << " ";
	std::cout << "\n";
}