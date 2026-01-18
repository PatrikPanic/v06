#pragma once
#include <iostream>

namespace vsite::oop::v7 {

	class money {
	private:
		int cents;   

	public:
		money(int eur = 0, int ct = 0);

		money& operator+=(const money& other);
		money& operator-=(const money& other);

		friend std::istream& operator>>(std::istream& in, money& m);
		friend std::ostream& operator<<(std::ostream& out, const money& m);
	};

}
//