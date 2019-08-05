#include "MySort.h"
void MySort::qsort()
{
	int left = 0;
	int right = this->data.size() - 1;
	if (left < right)
		qsort2(data, left, right);
}
void MySort::qsort2(vector<int>& data, int left, int right)
{
	int p = data[left];
	int l = left;
	int r = right;
	while (left < right)
	{
		while (left < right && data[right] > p)
			right--;
		if (left <= right)
			data[left] = data[right];
		while (left < right && data[left] <= p)
			left++;
		if (left <= right)
			data[right] = data[left];
	}
	data[left] = p;
	if (l < left - 1)
		qsort2(data, l, left - 1);
	if (r > left + 1)
		qsort2(data, left + 1, r);
}
void MySort::insertsort()
{
	for (int i = 1; i < data.size(); i++)
	{
		int now = data[i];
		int j = i;
		while (j - 1 >= 0 && data[j - 1] > now)
		{
			data[j] = data[j - 1];
			j--;
		}
		data[j] = now;

	}
}
void MySort::maopao()
{
	for (int i = data.size() - 1; i >= 0; i--)
	{
		int ok = 1;
		for (int j = 0; j < i; j++)
		{
			if (data[j] > data[j + 1])
			{
				data[j] = data[j] ^ data[j + 1];
				data[j + 1] = data[j] ^ data[j + 1];
				data[j] = data[j] ^ data[j + 1];
				ok = 0;
			}
		}
		if (ok == 1)
			break;

	}
}
void MySort::selectsort()
{
	int min = 0;
	for (int i = 0; i < data.size() - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < data.size(); j++)
		{
			if (data[min] > data[j])
				min = j;
		}
		if (min != i)
		{
			data[i] = data[i] ^ data[min];
			data[min] = data[i] ^ data[min];
			data[i] = data[i] ^ data[min];
		}
	}
}
void MySort::heapsort()
{
	vector<int> heap(data.size() + 1);
	buildheap(data, heap);
	int length = data.size();
	while (length > 0)
	{
		cout << heap[1];
		heap[1] = heap[length] ^ heap[1];
		heap[length] = heap[length] ^ heap[1];
		heap[1] = heap[length] ^ heap[1];
		adjust(heap, 1, length);
		length--;
	}

}
void MySort::adjust(vector<int>& heap, int j, int length)
{
	int max = j;
	int maxv = heap[j];
	if (j * 2 <= length - 1 && heap[j * 2] > maxv)
	{
		max = j * 2;
		maxv = heap[j * 2];
	}
	if (j * 2 + 1 <= length - 1 && heap[j * 2 + 1] > maxv)
	{
		max = j * 2 + 1;
	}

	if (j != max)
	{

		heap[j] = heap[j] ^ heap[max];
		heap[max] = heap[j] ^ heap[max];
		heap[j] = heap[j] ^ heap[max];
		adjust(heap, max, length);
	}

}

void MySort::buildheap(vector<int>& data, vector<int>& heap)
{

	int i = 1;
	for (auto b = data.begin(); b != data.end(); b++)
	{
		heap[i++] = *b;
	}
	for (int j = static_cast<int>(data.size() / 2); j >= 1; j--)
	{
		adjust(heap, j, heap.size());
	}
}
void MySort::shellsort(int step)
{
	for (int i = step; i > 0; i--)
	{
		for (int j = i; j < data.size(); j = j + i)
		{
			int now = data[j];
			int k = j;
			while (k - i >= 0 && data[k - i] > now)
			{
				data[k] = data[k - i];
				k = k - i;
			}
			data[k] = now;
		}
	}
}
void MySort::mergesort()
{
	int step = 1;
	int length = data.size();
	vector<int> a = data;
	while (data.size() <= step)
	{
		int num = ceil(length * 1.0 / (2*step));
		int left = 0;
		int mid = 0;
		int right = 0;
		while (num > 0)
		{
			right = left + 2 * step - 1;
			if (left + 2 * step > length - 1)
				right = length - 1;
			mid = (right - step) >= left ? right - step : left;
			hebing(data, left, mid, right);
			left = right + 1;
			num--;
		}
		step = step * 2;
	}

}
void MySort::hebing(vector<int>& data, int left, int m, int right)
{
	vector<int> now(right - left + 1);
	int i = left;
	int j = m + 1;
	int k = 0;
	while (i <= m && j <= right)
	{
		if (data[i] < data[j])
			now[k++] = data[i++];
		else
			now[k++] = data[j++];
	}
	while (i <= m)
		now[k++] = data[i++];
	while (j <= right)
		now[k++] = data[j++];
	for (int n = 0; n < now.size(); n++)
	{
		data[left++] = now[n];
	}
}
int main()
{
	MySort a;
	vector<int> b{ 1,7,5,3,2,1 };
	a.data = b;
	a.shellsort(3);
	for(auto i = a.data.begin(); i != a.data.end(); i++)
	   cout << *i;
}