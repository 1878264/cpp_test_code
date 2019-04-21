#include <iostream>

class Point
{
public:
	Point(int xx,int yy);
	~Point();
	Point(Point &p);
	int GetX(){ return x; }
	int GetY(){ return y; }

private:
	int x;
	int y;
};

Point::Point(int xx, int yy)
{
	using namespace std;
	cout << "Point construction" << endl;
	x = xx;
	y = yy;
}

Point::Point(Point &p)
{
	using namespace std;
	cout << "copy point" <<endl;
	x = p.GetX();
	y = p.GetY();
//	y = p.y;
}

Point::~Point()
{
}

class Distance
{
public:
	Distance(Point pp1,Point pp2);
	~Distance();
	double GetDistance(){ return distance; }

private:
	double distance;
	Point p1;
	Point p2;
};

Distance::Distance(Point pp1, Point pp2) :p1(pp1), p2(pp2)
{
	using namespace std;
	cout << "Distannce construction"<<endl;
	double x = double(pp1.GetX() - pp2.GetX());
	double y = double(pp1.GetY() - pp2.GetY());

	distance = sqrt(x*x + y*y);
	return;
}

Distance::~Distance()
{
}

int main()
{
	using namespace std;
	Point a(0, 0);
	Point b(3, 4);
	Distance dist1(a, b);
	cout << "Distance is " << dist1.GetDistance() << endl;
}