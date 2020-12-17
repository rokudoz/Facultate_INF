#include <iostream>
#include <string>

using namespace std;

class Yeap {
private:
	string name;
	int age;

public:
	Yeap(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
};

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void sort(int array[], int size) {
	/*for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j < size; j++)
		{
			if (array[i] > array[j])
			{
				swap(array[i], array[j]);
			}
		}
	}*/

	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (size_t i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);

				sorted = false;
			}

		}
	}

}

void printArray(int array[], int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void main() {

	int a[5] = { 33,2,1,4,8 };
	int size = sizeof(a) / sizeof(int);


	int* g;
	g = (int*)malloc(sizeof(int) * 10);

	g[9] = 3232;
	//cout << g[8];

	Yeap* object = new Yeap("eeee", 3);

	cout << object->getName()<<" " << object->getAge() << endl;

	//printArray(a, size);

	//sort(a, size);

	//printArray(a, size);

	cin.get();
}