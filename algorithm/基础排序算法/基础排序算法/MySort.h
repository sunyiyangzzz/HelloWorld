#pragma once
#include <iostream>
#include <vector>
using namespace std;
class MySort
{
public:
	vector<int> data;
	void qsort();          //����
	static void qsort2(vector<int>& data, int left, int right);
	void maopao();         //ð��
	void selectsort();     //ѡ��
	void heapsort();       //��
	void buildheap(vector<int>& data, vector<int>& heap);
	static void adjust(vector<int>& heap, int j ,int length);
	void insertsort();     //����
	void shellsort(int step);  //ϣ��
	void mergesort(); //�鲢
	void hebing(vector<int>& data, int left, int m, int right);

};

