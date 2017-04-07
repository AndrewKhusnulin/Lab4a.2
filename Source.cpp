#include "iostream"

using namespace std;
class Figure
{
protected:
	int x, y;
	int vx, vy;
public:
	void init(int x, int y, int vx, int vy);
	int get_X() { return x; }
	int get_Y() { return y; }
	virtual void step();
};

void Figure::init(int x, int y, int vx, int vy)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}
void Figure::step() 
{

	this->x += vx; this->y += vy;
	(x > 100) || (x < 0) ? vx = -vx : NULL;
	(y > 100) || (y < 0) ? vy = -vy : NULL;
};
class rectangle : public Figure
{
protected:
	int height;
	int length;
public:
	rectangle(int a, int b);
	~rectangle() {};
};
rectangle::rectangle(int a, int b) :Figure()
{
	this->height = a;
	this->length = b;
};
class circle : public Figure
{
protected:
	int radius;
public:
	circle(int a);
	~circle() {};
};
circle::circle(int a) :Figure()
{
	this->radius = a;
}
void main()
{
	setlocale(LC_ALL, "Russian");
	rectangle f1(5, 10);
	circle f2(5);
	f1.init(20, 30, 1, 1);
	f2.init(40, 60, 1, -1);
	for (unsigned i = 0; i < 20; ++i)
	{
		cout << "Координаты f1(" << f1.get_X() << ";" << f1.get_Y() << ")" << endl;
		cout << "Координаты f2(" << f2.get_X() << ";" << f2.get_Y() << ")" << endl;
		f1.step();
		f2.step();
	};
	system("pause");
};
