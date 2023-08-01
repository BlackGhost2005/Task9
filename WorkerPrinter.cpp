//#include<iostream>
//#include<cassert>
//using namespace std;
//
//typedef unsigned short int ushort;
//
//const int MaxSize = 10;
//
//template<typename T>
//class Queue {
//
//	T _array[MaxSize];
//	int _front = -1;
//	int _rear = -1;
//
//public:
//
//
//
//	T getFrontData();
//
//	T getRearData();
//
//	bool isEmpty();
//
//	bool isFull();
//
//	void enQueue(T element);
//
//	T deQueue();
//
//	T peek();
//
//	~Queue() { delete[] _array; }
//
//	template<typename T>
//	friend ostream& operator<<(ostream& out, const Queue<T>& queue);
//	friend class Printer;
//	friend class Worker;
//};
//
//template<typename T>
//ostream& operator<<(ostream& out, const Queue<T>& queue)
//{
//	for (size_t i = 0; i < queue._rear + 1; i++)
//		out << "[" << i << "] => " << queue._array[i] << endl;
//	return out;
//}
//
//template<typename T>
//T Queue<T>::getFrontData() { return this->_array[this->_front]; }
//
//template<typename T>
//T Queue<T>::getRearData() { return this->_array[this->_rear]; }
//
//template<typename T>
//bool Queue<T>::isEmpty()
//{
//	return (_front == -1);
//}
//
//template<typename T>
//bool Queue<T>::isFull() {
//	return (_rear == MaxSize - 1);
//}
//
//template<typename T>
//void Queue<T>::enQueue(T element) {
//	if (isFull()) {
//		assert(!"Queue is full");
//	}
//	else {
//		if (_front == -1)
//			_front = 0;
//		_rear++;
//		_array[_rear] = element;
//	}
//}
//
//template<typename T>
//T Queue<T>::deQueue() {
//	T element;
//	if (isEmpty()) {
//		assert(!"Queue is empty");
//	}
//	else {
//		element = _array[_front];
//		if (_front == _rear) {
//			_front = -1;
//			_rear = -1;
//		}
//		else {
//			_front++;
//		}
//		return element;
//	}
//}
//
//template<typename T>
//T Queue<T>::peek() {
//
//	return this->_array[this->_front];
//}
//
//
//class Worker {
//
//	static ushort _static_id;
//	ushort _id;
//	char* _name;
//	char* _surname;
//	ushort _age;
//	ushort _pageCount;
//public:
//	
//	Worker(const char* name, const char* surname, ushort age, ushort pageCount)
//	{
//		int len = strlen(name);
//		if (len >= 1)
//		{
//			if (this->_name != NULL)
//				delete[] this->_name;
//
//			this->_name = new char[++len];
//			strcpy_s(this->_name, len, name);
//		}
//		else
//		{
//			assert(!"Ad yoxdur!");
//		}
//
//		int len1 = strlen(surname);
//		if (len1 >= 1)
//		{
//			if (this->_surname != NULL)
//				delete[] this->_surname;
//
//			this->_surname = new char[++len1];
//			strcpy_s(this->_surname, len1, surname);
//		}
//		else
//		{
//			assert(!"Soyad yoxdur!");
//		}
//
//		_id = _static_id++;
//		this->_age = age;
//		this->_pageCount = pageCount;
//	}
//
//	ushort getID() { return this->_id; }
//	char* getName() { return this->_name; }
//	char* getSurname() { return this->_surname; }
//	ushort getAge() { return this->_age; }
//	ushort getPageCount() { return this->_pageCount; }
//
//	void Show() {
//
//		cout << "ID : " << _id << endl;
//		cout << "Name : " << _name << endl;
//		cout << "Surname : " << _surname << endl;
//		cout << "Age : " << _age << endl;
//		cout << "PageCOunt : " << +_pageCount << endl;
//	}
//
//	friend class Printer;
//
//	template<typename T>
//	friend class Queue;
//};
//
//
//ushort Worker::_static_id = 0;
//
//class Printer {
//
//	Queue<Worker*>* WorkerQueue;
//
//public:
//	Printer(Queue<Worker*>* queue)
//	{
//		this->WorkerQueue = queue;
//	}
//
//	void start() {
//
//		while (!(WorkerQueue->isEmpty()))
//		{
//			WorkerQueue->peek()->Show();
//			cout << endl;
//			while (WorkerQueue->peek()->_pageCount > 0)
//			{
//				cout << "Page -> " << WorkerQueue->peek()->_pageCount << endl;
//				WorkerQueue->peek()->_pageCount--;
//			}
//			WorkerQueue->deQueue();
//			cout << endl;
//		}
//
//	}
//};
//
//
//int main() {
//
//	Queue<Worker*>* queue = new Queue<Worker*>();
//	queue->enQueue(new Worker("Huseyn", "Orucov", 18, 3));
//	queue->enQueue(new Worker("Cavid", "Atamoglanov", 25, 2));
//	Printer* printer = new Printer(queue);
//	printer->start();
//}