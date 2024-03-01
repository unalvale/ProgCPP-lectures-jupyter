#include <string>
#include <iostream>
#include "primes.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Primes are computed", "[prime]" ) {
    REQUIRE( is_prime( 2) == true );
    REQUIRE( is_prime( 3) == true );
    REQUIRE( is_prime( 5) == true );
    REQUIRE( is_prime( 7) == true );
    REQUIRE( is_prime( 10000019) == true );
    REQUIRE( is_prime( 3000000019) == true );
    REQUIRE( is_prime(-1) == false );
    REQUIRE( is_prime(1) == false );
    REQUIRE( is_prime(4) == false );
    REQUIRE( is_prime(10) == false );
}
