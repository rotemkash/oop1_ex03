#include <catch2/catch_test_macros.hpp>

#include "Vector.h"

#include <sstream>
#include <string_view>

std::string_view rtrim(std::string_view str)
{
    const auto pos = str.find_last_not_of(" ");
    str.remove_suffix(std::min(str.size() - pos - 1, str.size()));
    return str;
}

TEST_CASE("Vector operations", "[Vector]")
{
    auto v0 = Vector();
    auto v1 = Vector(4, 5);

    auto oss = std::ostringstream();
    oss << v0;
    REQUIRE(oss.view() == "");

    oss.str("");
    oss << v1;
    REQUIRE(rtrim(oss.view()) == "5+0i 5+0i 5+0i 5+0i");

    REQUIRE(v0 + v1 == v1);

    auto v2 = Vector(2);
    v2[0] = 5;
    v2[1] = Zi(3, -6);

    oss.str("");
    oss << v2;
    REQUIRE(rtrim(oss.view()) == "5+0i 3-6i");
    
    oss.str("");
    oss << -v2;
    REQUIRE(rtrim(oss.view()) == "-5+0i -3+6i");
}

TEST_CASE("Operations with different size vectors", "[Vector]")
{
    auto v0 = Vector();
    auto v1 = Vector(2);
    v1[0] = 5;
    v1[1] = Zi(3, -6);

    auto v2 = v0 - v1;
    auto oss = std::ostringstream();
    oss << v2;

    REQUIRE(v2 == -v1);
    REQUIRE(rtrim(oss.view()) == "-5+0i -3+6i");

    REQUIRE(v0 * v1 == Vector(2));

    auto v3 = Vector(1, 1) * v1;
    REQUIRE(v3.size() == 2);
    REQUIRE(v3[0] == v1[0]);
    REQUIRE(v3[1] == 0);
}