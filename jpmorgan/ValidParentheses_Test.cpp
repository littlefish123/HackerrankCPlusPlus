#define BOOST_TEST_MODULE ValidParenthesesTest
#include <boost/test/included/unit_test.hpp>
#include "ValidParentheses.cpp"

BOOST_AUTO_TEST_CASE(BasicTests) {
    BOOST_CHECK_EQUAL(isBalanced("({{}]}}"), "NO");
    BOOST_CHECK_EQUAL(isBalanced("((([])))}"), "NO");
    BOOST_CHECK_EQUAL(isBalanced("()"), "YES");
    BOOST_CHECK_EQUAL(isBalanced("()[]{}"), "YES");
    BOOST_CHECK_EQUAL(isBalanced("(]"), "NO");
    BOOST_CHECK_EQUAL(isBalanced("([)]"), "NO");
    // this test case should be failed
    BOOST_CHECK_EQUAL(isBalanced("{[]}"), "NO");
}

BOOST_AUTO_TEST_CASE(EdgeCases) {
    BOOST_CHECK_EQUAL(isBalanced(""), "YES");
    BOOST_CHECK_EQUAL(isBalanced("("), "NO");
    BOOST_CHECK_EQUAL(isBalanced(")"), "NO");
    BOOST_CHECK_EQUAL(isBalanced("(((((("), "NO");
    BOOST_CHECK_EQUAL(isBalanced("))))))"), "NO");
}