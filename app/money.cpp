#include "money.h"
#include <iomanip>
#include <cstdlib>

namespace vsite::oop::v7 {

	money::money(int eur, int ct) {
		cents = eur * 100 + ct;
	}

	money& money::operator+=(const money& other) {
		cents += other.cents;
		return *this;
	}

	money& money::operator-=(const money& other) {
		cents -= other.cents;
		return *this;
	}

	std::istream& operator>>(std::istream& in, money& m) {
		int eur, ct;
		in >> eur >> ct;
		m.cents = eur * 100 + ct;
		return in;
	}

	std::ostream& operator<<(std::ostream& out, const money& m) {
		int eur = m.cents / 100;
		int ct = std::abs(m.cents % 100);

		out << eur << " eur";

		if (ct != 0) {
			out << " "
				<< std::setw(2) << std::setfill('0') << ct
				<< " ct";
		}

		return out;
	}

}
