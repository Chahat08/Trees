#include <iostream>
#include <vector>
#define MAX_LEN 20

/*
* PRIORITY QUEUE / HEAP INTERFACE
1. Construction(Heapify)
2. Add(Item) : Insert
3. Poll() : Remove root
4. Remove(Item) : Remove Item
5. Search(Item) : Find Item
6. Peek() : Look at root
*/

struct Min_Heap
{
	int size;
	int MAX_SIZE;
	std::vector<int> heap;

	void Insert(int x)
	{
		if (size == MAX_SIZE) { std::cout << "size is full\n"; return; }

		heap[++size] = x;
		for (int i = size, j = (i - 1) / 2; j >= 0; i = j, j = (i - 1) / 2)
		{
			if (heap[i] >= heap[j]) break;
			std::swap(heap[i], heap[j]);
		}
	}
	void Poll()
	{
		// to remove root:
		// swap root, with last node
		// delete last node
		// sift down the new root

		// O(log n)

		std::swap(heap[0], heap[size]);
		--size;
		for (int i = 0;;)
		{
			if (2 * i + 1 >= size )
			{
				if (2 * i + 1 > size) break; // no child exists, break;

				// otherwise right child doesnt exist, left exits
				if (heap[i] > heap[2 * i + 1]) std::swap(heap[i], heap[2 * i + 1]);
				break;
			}

			if (heap[i] <= heap[2 * i + 1] && heap[i] <= heap[2 * i + 2]) break;

			if(heap[2 * i + 1] <= heap[2 * i + 2])
			{ 
				if (heap[i] > heap[2 * i + 1])
				{
					std::swap(heap[i], heap[2 * i + 1]);
					i = 2 * i + 1;
				}
				else break;
			} 
			else
			{
				if (heap[i] > heap[2 * i + 2])
				{
					std::swap(heap[i], heap[2 * i + 2]);
					i = 2 * i + 2;
				}
				else break;
			};
		}

	}
	int Search(int x)
	{
		// return index of element if it exists, else return -1
		// O(n)
		for (int i = 0; i <= size; ++i)
			if (heap[i] == x) return i;
		return -1;
	}
	void Remove(int x)
	{
		int i = Search(x);
		if (i == -1) { std::cout << "Element doesnt exist.\n"; return; }
		std::swap(heap[i], heap[size]);
		--size;


		// SIFTING
		if (heap[i] > heap[2 * i + 1] || heap[i] > heap[2 * i + 2])
		{
			// sift down
			while (true)
			{
				if (2 * i + 1 >= size)
				{
					if (2 * i + 1 > size) break; // no child exists, break;

					// otherwise right child doesnt exist, left exits
					if (heap[i] > heap[2 * i + 1]) std::swap(heap[i], heap[2 * i + 1]);
					break;
				}

				if (heap[i] <= heap[2 * i + 1] && heap[i] <= heap[2 * i + 2]) break;

				if (heap[2 * i + 1] <= heap[2 * i + 2])
				{
					if (heap[i] > heap[2 * i + 1])
					{
						std::swap(heap[i], heap[2 * i + 1]);
						i = 2 * i + 1;
					}
					else break;
				}
				else
				{
					if (heap[i] > heap[2 * i + 2])
					{
						std::swap(heap[i], heap[2 * i + 2]);
						i = 2 * i + 2;
					}
					else break;
				};
			}
		}
		else if (heap[i] < heap[(i - 1) / 2])
		{
			// sift up
			while ((i - 1) / 2 >= 0)
			{
				std::swap(heap[i], heap[(i - 1) / 2]);
				i = (i - 1) / 2;
			}
		}
	}
	int Peek()
	{
		if (size == -1) { std::cout << "heap empty\n"; return -1; }
		return heap[0];
	}
	void Print()
	{
		for (int i = 0; i <= size; ++i) std::cout << heap[i] << " ";
		std::cout << std::endl;
	}
	void Heapify(std::vector<int>& v)
	{
		for (int& i : v) Insert(i);
	}


	Min_Heap() :size(-1), MAX_SIZE(MAX_LEN) { heap.resize(MAX_SIZE); }
	Min_Heap(int x) :size(-1), MAX_SIZE(MAX_LEN) { heap.resize(MAX_SIZE); }
	Min_Heap(std::vector<int>& v) :size(-1), MAX_SIZE(MAX_LEN)
	{ 
		heap.resize(MAX_SIZE);
		Heapify(v);
	}
};

int main()
{
	std::vector<int> v({ 17,15,10,8,13,3,6,1,5,4,9 });
	Min_Heap h(v);
	h.Print();
	h.Insert(23);
	h.Insert(20);
	h.Insert(17);
	h.Insert(3);
	h.Print();
	std::cout << h.Peek() << std::endl;
	h.Poll();
	h.Poll();
	h.Print();
	h.Remove(8);
	h.Remove(9);
	h.Print();
}