#include <iostream>
//https://zhuanlan.zhihu.com/p/101004501?utm_source=com.evernote

struct data {
	int a;
	double b;
	std::partial_ordering operator<=>(const data& that) const//<=>生成六个关系运算符重载（ == 、 != 、 < 、 <= 、 > 、 >= ）
	{
		if (a < 0 || that.a < 0)  return std::partial_ordering::unordered;//-128
		if (b > that.b) return std::partial_ordering::greater;//1
		if (b < that.b) return std::partial_ordering::less;//-1
		return std::partial_ordering::equivalent;//相等0
	}
	bool operator==(const data& that) const
	{
		return (*this <=> that) == 0;
	}
};

struct Point {
	int x;
public:
	Point(int a) :x(a) {}
	auto operator<=>(const Point& p) const {//<=> 生成六个关系运算符重载（ == 、 != 、 < 、 <= 、 > 、 >= ）
		return x <=> p.x;
	}
};

int main() {

	data ta = { 2, 1.0f };
	data  tb = { 3, 1.0f };
	std::cout << (ta == tb) << std::endl;//1
	std::cout << (ta > tb) << std::endl;//0
	std::cout << (ta >= tb) << std::endl;//1

	std::shared_ptr<Point> p = std::make_shared<Point>(6);
	std::shared_ptr<Point> p1 = std::make_shared<Point>(5);
	std::cout << (p >= p1) << std::endl;//满足为1
	std::cout << (p < p1) << std::endl;//不满足为0
	std::cout << (p == p1) << std::endl;//不满足为0
	return 0;
}
