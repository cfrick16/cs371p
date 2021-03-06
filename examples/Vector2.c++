// -----------
// Vector2.c++
// -----------

// http://en.cppreference.com/w/cpp/container/vector

#include <algorithm>        // equal
#include <cassert>          // assert
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl
#include <vector>           // vector

using namespace std;

void test1 () {
    const vector<int> x;
    assert(x.size() == 0);}

void test2 () {
    const vector<int> x(3);
    assert(x.size() == 3);
    assert(equal(begin(x), end(x), begin({0, 0, 0})));}

void test3 () {
    const vector<int> x(3, 2);
    assert(x.size() == 3);
    assert(equal(begin(x), end(x), begin({2, 2, 2})));}

void test4 () {
    const initializer_list<int> x = {2, 3, 4};
    assert(x.size() == 3);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));
    const vector<int> y(x);
    assert(y.size() == 3);
    assert(equal(begin(y), end(y), begin({2, 3, 4})));}

void test5 () {
    vector<int> x = {2, 3, 4};
    assert(x[1] == 3);
    x[1] = 5;
    assert(equal(begin(x), end(x), begin({2, 5, 4})));}

void test6 () {
    const vector<int> x = {2, 3, 4};
    assert(x[1] == 3);
//  x[1] = 5;                                           // error: cannot assign to return value because function 'operator[]' returns a const value
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test7 () {
    const vector<int> x(10, 2);
    const vector<int> y = x;
    assert(begin(x) != begin(y));
    assert(x == y);}

void test8 () {
    const vector<int> x(10, 2);
          vector<int> y(20, 3);
    y = x;
    assert(begin(x) != begin(y));
    assert(x == y);}

void test9 () {
    const vector<int> x(20, 3);
          vector<int> y(10, 2);
    y = x;
    assert(begin(x) != begin(y));
    assert(x == y);}

int main () {
    cout << "Vector2.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    cout << "Done." << endl;
    return 0;}
