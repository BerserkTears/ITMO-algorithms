#include "gtest/gtest.h"
#define TESTING
#include "task1.cpp"


TEST(given, first){
    string a = "aba", b = "abaCaba";
    vector<int> answer = {1,5};
    EXPECT_EQ(search(a,b), answer);
}

TEST(given, second){
    string a = "ab", b = "DababCab";
    vector<int> answer = {2, 4 ,7};
    EXPECT_EQ(search(a,b), answer);
}