#pragma once
#include <iostream>
#include <vector>
using namespace std;
class MySort
{
public:
	vector<int> data;
	void qsort();          //øÏ≈≈
	static void qsort2(vector<int>& data, int left, int right);
	void maopao();         //√∞≈›
	void selectsort();     //—°‘Ò
	void heapsort();       //∂—
	void buildheap(vector<int>& data, vector<int>& heap);
	static void adjust(vector<int>& heap, int j ,int length);
	void insertsort();     //≤Â»Î
	void shellsort(int step);  //œ£∂˚
	void mergesort(); //πÈ≤¢
	void hebing(vector<int>& data, int left, int m, int right);

};

