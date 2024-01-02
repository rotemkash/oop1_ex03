#include <catch2/catch_test_macros.hpp>

#include "Zi.h"

#include <sstream>

TEST_CASE("Zi operations", "[Zi]")
{

    {
        auto z0 = Zi(14, 3);
        auto z1 = Zi(4, 5);

        auto oss = std::ostringstream();
        oss << z0;

        REQUIRE(oss.str() == "14+3i");

        REQUIRE(!z0.dividedBy(z1));
        REQUIRE(Zi(1, 3).norm() == 10);
        REQUIRE(Zi(1, 3) == Zi(1, 1) * Zi(2, 1));

        {
            auto z2 = z0 * z1;
            REQUIRE(z2.dividedBy(z0));
            REQUIRE(z2.dividedBy(z1));
            REQUIRE(z2 / z0 == z1);
            REQUIRE(z2 % z0 == 0);
            REQUIRE(z2 / z1 == z0);
            REQUIRE(z2 % z1 == 0);
        }

        REQUIRE(z0 == z0);
        REQUIRE(z0 != z1);
    }


    {
        auto z2 = Zi(27, -23);
        auto z3 = Zi(8, 1);

        REQUIRE(!z2.dividedBy(z3));

        auto rhs = z3;
        auto lhs = z2;

        REQUIRE(z2 / z3 == Zi(3, -3));
        REQUIRE(z2 % z3 == Zi(0, -2));
    }
}